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
#include "src/__support/fixedvector.h"
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

// TestDir sets up a temporary directory structure on constrution
// and removes it upon destrution. To make one, use TestDirBuilder.
class TestDir {
public:
  using FileSystemEntryVector = FixedVector<internal::FileSystemEntry, 32>;

  // TestDir takes ownership of the root path and the entries.
  TestDir(cpp::string &&root_path, FileSystemEntryVector &&entries);
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
  cpp::string get_path(cpp::string_view relative_path) const {
    return absolute_path(relative_path);
  }
  void create_entry(const internal::FileSystemEntry &entry);

  cpp::string root;
  FileSystemEntryVector entries;
};

// TestDirBuilder allows declarative definition of a filesystem structure.
class TestDirBuilder {
public:
  explicit TestDirBuilder(cpp::string_view name) : root_name(name) {}

  TestDirBuilder &add_file(cpp::string path);
  TestDirBuilder &add_directory(cpp::string path);
  TestDirBuilder &add_symlink(cpp::string path, cpp::string target);

  // Materializes the defined structure to disk and returns an RAII TestDir.
  TestDir build();

private:
  cpp::string root_name;
  TestDir::FileSystemEntryVector entries;
};

// ChangeDirGuard chdir's into a directory on construction and restores the
// previous working directory on destruction.
class ChangeDirGuard {
public:
  explicit ChangeDirGuard(cpp::string_view new_cwd);
  ~ChangeDirGuard();

private:
  cpp::string old_cwd;
};

} // namespace testing
} // namespace LIBC_NAMESPACE_DECL

#endif // LLVM_LIBC_TEST_UNITTEST_FILESYSTEMHELPERS_H
