//===-- Unittests for realpath --------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/stdlib/realpath.h"
#include "src/unistd/chdir.h"
#include "src/unistd/rmdir.h"
#include "test/UnitTest/FileSystemHelpers.h"
#include "test/UnitTest/Test.h"

#include <stddef.h>

using LIBC_NAMESPACE::testing::ChangeDirGuard;
using LIBC_NAMESPACE::testing::TestDir;
using LIBC_NAMESPACE::testing::TestDirBuilder;

class LlvmLibcRealpathTest : public LIBC_NAMESPACE::testing::Test {
public:
  char *realpath(const char *path) {
    return LIBC_NAMESPACE::realpath(path, buf);
  }
  char *realpath(const cpp::string &path) { return realpath(path.c_str()); }

  char buf[PATH_MAX];
};

// Test for simple traversals using directory structure {test_dir}/a/b/c.
class LlvmLibcRealpathABCTest : public LIBC_NAMESPACE::testing::Test {
public:
  static TestDir &test_dir() {
    static TestDir fs = TestDirBuilder("LlvmLibcRealpathABCTest")
                            .add_directory("a")
                            .add_directory("a/b")
                            .add_directory("a/b/c")
                            .build();
    return fs;
  }

  cpp::string abspath(cpp::string_view path) {
    return test_dir().absolute_path(path);
  }

  char *realpath(const char *path) {
    return LIBC_NAMESPACE::realpath(path, test_buf);
  }
  char *realpath(const cpp::string &path) { return realpath(path.c_str()); }

  char test_buf[PATH_MAX];
};

TEST_F(LlvmLibcRealpathABCTest, DotTraversalInPathIsNop) {
  ASSERT_STREQ(realpath(abspath("a/./b")), abspath("a/b").c_str());
}

TEST_F(LlvmLibcRealpathABCTest, DotTraversalAtEndOfPathIsNop) {
  ASSERT_STREQ(realpath(abspath("a/b/.")), abspath("a/b").c_str());
}

TEST_F(LlvmLibcRealpathABCTest, DotDotTraversalInPathMovesBack) {
  ASSERT_STREQ(realpath(abspath("a/../b")), abspath("b").c_str());
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
  ASSERT_STREQ(realpath(fs.absolute_path("link")), abspath("dir").c_str());
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfTraversingFile) {
  TestDir fs = TestDirBuilder(getName()).add_file("file").build();

  // Test error -- ENOTDIR.
  realpath(fs.absolute_path("file/other_file"));
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfTooManySymlinkTraversals) {
  TestDir fs = TestDirBuilder(getName())
                   .add_symlink("a", "b")
                   .add_symlink("b", "a")
                   .build();

  // Test error -- ELOOP.
  realpath(fs.absolute_path("a"));
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfNameTooLong) {
  cpp::string root = libc_make_test_file_path(cpp::string(getName()).c_str());
  ChangeDirGuard chdir_guard(root.c_str());

  cpp::string segment =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  size_t nested_dir_count = 0;
  for (size_t s = 0; s < PATH_MAX; s += segment.size()) {
    LIBC_NAMESPACE::mkdir(segment, S_IRWXU);
    LIBC_NAMESPACE::chdir(segment);
    nested_dir_count++;
  }

  // Test error -- ENAMETOOLONG.
  realpath(".");

  for (; nested_dir_count > 0; nested_dir_count--) {
    LIBC_NAMESPACE::chdir("..");
    LIBC_NAMESPACE::rmdir(segment);
  }
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfPathIsNull) {
  // Test error -- EINVAL.
  realpath(NULL);
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfPathDirectoryDoesNotExists) {
  TestDir fs = TestDirBuilder(getName()).add_directory("exists").build();
  // Test error -- ENOENT.
  realpath(fs.absolute_path("does_not_exist/file"));
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfFinalSegmentDoesNotExist) {
  TestDir fs = TestDirBuilder(getName()).add_directory("exists").build();
  // Test error -- ENOENT.
  realpath(fs.absolute_path("exists/file"));
}

TEST_F(LlvmLibcRealpathTest, AllocatesResolvedPathIfNullPassed) {
  TestDir fs = TestDirBuilder(getName())
                   .add_directory("exists")
                   .add_file("exists/file")
                   .build();
  char *resolved =
      LIBC_NAMESPACE::realpath(fs.absolute_path("exists//file").c_str(), NULL);
  ASSERT_STREQ(resolved, fs.absolute_path("exists/file").c_str());
  free(resolved);
}

TEST_F(LlvmLibcRealpathTest, ErrorsIfPathIsEmpty) {
  // Test error -- ENOENT.
  realpath("");
}