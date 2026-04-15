//===-- Unittests for realpath --------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/__support/CPP/string.h"
#include "src/__support/OSUtil/filesystem.h"
#include "src/stdlib/realpath.h"
#include "test/UnitTest/ErrnoCheckingTest.h"
#include "test/UnitTest/FileSystemHelpers.h"
#include "test/UnitTest/Test.h"

#include <errno.h>
#include <stddef.h>

namespace {
using LIBC_NAMESPACE::testing::ChangeDirGuard;
using LIBC_NAMESPACE::testing::ErrnoCheckingTest;
using LIBC_NAMESPACE::testing::libc_make_test_file_path_func;
using LIBC_NAMESPACE::testing::TestDir;
using LIBC_NAMESPACE::testing::TestDirBuilder;

class LlvmLibcRealpathTest : public ErrnoCheckingTest {
public:
  char *realpath(const char *path) {
    return LIBC_NAMESPACE::realpath(path, buf);
  }

  char *realpath(const LIBC_NAMESPACE::cpp::string &path) {
    return realpath(path.c_str());
  }

  char buf[PATH_MAX];
};

// Test for simple traversals using directory structure {test_dir}/a/b/c.
class LlvmLibcRealpathABCTest : public ErrnoCheckingTest {
public:
  static TestDir &test_dir() {
    static TestDir fs = TestDirBuilder("LlvmLibcRealpathABCTest")
                            .add_directory("a")
                            .add_directory("a/b")
                            .add_directory("a/b/c")
                            .build();
    return fs;
  }

  LIBC_NAMESPACE::cpp::string abspath(LIBC_NAMESPACE::cpp::string_view path) {
    return test_dir().absolute_path(path);
  }

  char *realpath(const char *path) {
    return LIBC_NAMESPACE::realpath(path, test_buf);
  }
  char *realpath(const LIBC_NAMESPACE::cpp::string &path) {
    return realpath(path.c_str());
  }

  char test_buf[PATH_MAX];
};

TEST_F(LlvmLibcRealpathABCTest, DotTraversalInPathIsNop) {
  ASSERT_STREQ(realpath(abspath("a/./b")), abspath("a/b").c_str());
}

TEST_F(LlvmLibcRealpathABCTest, DotTraversalAtEndOfPathIsNop) {
  ASSERT_STREQ(realpath(abspath("a/b/.")), abspath("a/b").c_str());
}

TEST_F(LlvmLibcRealpathABCTest, DotDotTraversalInPathMovesBack) {
  ASSERT_STREQ(realpath(abspath("a/../a")), abspath("a").c_str());
}

TEST_F(LlvmLibcRealpathABCTest, DotDotTraversalAtEndOfPathMovesBack) {
  ASSERT_STREQ(realpath(abspath("a/b/..")), abspath("a").c_str());
}

TEST_F(LlvmLibcRealpathABCTest, ExtraSlashesAreRemoved) {
  ASSERT_STREQ(realpath(abspath("a//b///c//")), abspath("a/b/c").c_str());
}

TEST_F(LlvmLibcRealpathABCTest, UsesCurrentWorkingDirForRelativePaths) {
  ChangeDirGuard chdir_guard(test_dir().get_root());
  ASSERT_STREQ(realpath("./a//b//c//"), abspath("a/b/c").c_str());
}

TEST_F(LlvmLibcRealpathTest, MovingBackwardsAtRootYieldsRoot) {
  ASSERT_STREQ(realpath("/../.."), "/");
}

TEST_F(LlvmLibcRealpathTest, FollowsSymlinkOnPath) {
  TestDir fs = TestDirBuilder(getName())
                   .add_directory("dir")
                   .add_directory("dir/a")
                   .add_symlink("link", "dir")
                   .build();
  ASSERT_STREQ(realpath(fs.absolute_path("link/a")),
               fs.absolute_path("dir/a").c_str());
}

TEST_F(LlvmLibcRealpathTest, FollowsSymlinkAtEndOfPath) {
  TestDir fs = TestDirBuilder(getName())
                   .add_directory("dir")
                   .add_symlink("link", "dir")
                   .build();
  ASSERT_STREQ(realpath(fs.absolute_path("link")),
               fs.absolute_path("dir").c_str());
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfTraversingFile) {
  TestDir fs = TestDirBuilder(getName()).add_file("file").build();

  // Test error -- ENOTDIR.
  ASSERT_EQ(realpath(fs.absolute_path("file/other_file")),
            static_cast<char *>(nullptr));
  ASSERT_ERRNO_EQ(ENOTDIR);
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfTooManySymlinkTraversals) {
  TestDir fs = TestDirBuilder(getName())
                   .add_symlink("a", "b")
                   .add_symlink("b", "a")
                   .build();

  // Test error -- ELOOP.
  ASSERT_EQ(realpath(fs.absolute_path("a")), static_cast<char *>(nullptr));
  ASSERT_ERRNO_EQ(ELOOP);
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfNameTooLong) {
  LIBC_NAMESPACE::cpp::string root(libc_make_test_file_path(getName()));
  ChangeDirGuard chdir_guard(root.c_str());

  LIBC_NAMESPACE::cpp::string segment =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  size_t nested_dir_count = 0;
  for (size_t s = 0; s < PATH_MAX; s += segment.size()) {
    LIBC_NAMESPACE::internal::mkdir(segment.data(), S_IRWXU);
    LIBC_NAMESPACE::internal::chdir(segment.data());
    nested_dir_count++;
  }

  // Test error -- ENAMETOOLONG.
  ASSERT_EQ(realpath("."), static_cast<char *>(nullptr));
  ASSERT_ERRNO_EQ(ENAMETOOLONG);

  for (; nested_dir_count > 0; nested_dir_count--) {
    LIBC_NAMESPACE::internal::chdir("..");
    LIBC_NAMESPACE::internal::rmdir(segment.data());
  }
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfPathIsNull) {
  // Test error -- EINVAL.
  ASSERT_EQ(realpath(nullptr), static_cast<char *>(nullptr));
  ASSERT_ERRNO_EQ(EINVAL);
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfPathDirectoryDoesNotExists) {
  TestDir fs = TestDirBuilder(getName()).add_directory("exists").build();
  // Test error -- ENOENT.
  ASSERT_EQ(realpath(fs.absolute_path("does_not_exist/file")),
            static_cast<char *>(nullptr));
  ASSERT_ERRNO_EQ(ENOENT);
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfFinalSegmentDoesNotExist) {
  TestDir fs = TestDirBuilder(getName()).add_directory("exists").build();
  // Test error -- ENOENT.
  ASSERT_EQ(realpath(fs.absolute_path("exists/file")),
            static_cast<char *>(nullptr));
  ASSERT_ERRNO_EQ(ENOENT);
}

TEST_F(LlvmLibcRealpathTest, AllocatesResolvedPathIfNullPassed) {
  TestDir fs = TestDirBuilder(getName())
                   .add_directory("exists")
                   .add_file("exists/file")
                   .build();
  char *resolved = LIBC_NAMESPACE::realpath(
      fs.absolute_path("exists//file").c_str(), nullptr);
  ASSERT_STREQ(resolved, fs.absolute_path("exists/file").c_str());
  free(resolved);
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfPathIsEmpty) {
  // Test error -- ENOENT.
  ASSERT_EQ(realpath(""), static_cast<char *>(nullptr));
  ASSERT_ERRNO_EQ(ENOENT);
}
} // namespace
