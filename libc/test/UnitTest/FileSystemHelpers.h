//===-- Declarative filesystem setup for libc unittests ---------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_TEST_UNITTEST_FILESYSTEMHELPERS_H
#define LLVM_LIBC_TEST_UNITTEST_FILESYSTEMHELPERS_H

#include "src/__support/CPP/string.h"
#include "src/__support/CPP/string_view.h"
#include "src/__support/CPP/vector.h"
#include "src/__support/macros/config.h"

namespace LIBC_NAMESPACE_DECL {
namespace testing {

namespace internal {
// FileSystemEntry represents a node in the filesystem tree.
struct FileSystemEntry {
  enum class Type { File, Directory, Symlink } type;
  cpp::string path;
  cpp::string target; // Only used for Type::Symlink
};
} // namespace internal

// TestDir is an RAII object that maintains a temporary filesystem structure
// and removes it upon destruction. It is created via a TestDirBuilder.
class TestDir {
  cpp::string root;
  cpp::vector<internal::FileSystemEntry> entries;

public:
  // TestDir takes ownership of the root path and the entries.
  TestDir(cpp::string &&root_path,
          cpp::vector<internal::FileSystemEntry> &&entries);
  ~TestDir();

  TestDir(const TestDir &) = delete;
  TestDir &operator=(const TestDir &) = delete;
  TestDir(TestDir &&) = default;
  TestDir &operator=(TestDir &&) = default;

  // Get the absolute path to the test directory root.
  const char *get_root() const { return root.c_str(); }

  // Helper to get an absolute path for a relative path within the test
  // directory.
  cpp::string absolute_path(cpp::string_view relative_path) const;

private:
  void create_entry(const internal::FileSystemEntry &entry);
};

// TestDirBuilder allows declarative definition of a filesystem structure.
class TestDirBuilder {
  cpp::string_view root_name;
  cpp::vector<internal::FileSystemEntry> entries;

public:
  explicit TestDirBuilder(cpp::string_view name) : root_name(name) {}

  TestDirBuilder &add_file(cpp::string path) {
    entries.push_back({internal::FileSystemEntry::Type::File, cpp::move(path), ""});
    return *this;
  }

  TestDirBuilder &add_directory(cpp::string path) {
    entries.push_back(
        {internal::FileSystemEntry::Type::Directory, cpp::move(path), ""});
    return *this;
  }

  TestDirBuilder &add_symlink(cpp::string path, cpp::string target) {
    entries.push_back({internal::FileSystemEntry::Type::Symlink, cpp::move(path),
                       cpp::move(target)});
    return *this;
  }

  // Materializes the defined structure to disk and returns an RAII TestDir.
  TestDir build();
};

// ChangeDirGuard is an RAII object that saves the current working directory
// and restores it upon destruction.
class ChangeDirGuard {
  cpp::string old_cwd;

public:
  explicit ChangeDirGuard(cpp::string_view new_cwd);
  ~ChangeDirGuard();
};

} // namespace testing
} // namespace LIBC_NAMESPACE_DECL

#endif // LLVM_LIBC_TEST_UNITTEST_FILESYSTEMHELPERS_H
