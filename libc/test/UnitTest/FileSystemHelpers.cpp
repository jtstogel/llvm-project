//===-- Implementation of filesystem setup for libc unittests -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "test/UnitTest/FileSystemHelpers.h"
#include "src/__support/CPP/string.h"
#include "src/__support/OSUtil/filesystem.h"
#include "test/UnitTest/Test.h"

#include <fcntl.h>
#include <sys/stat.h>

namespace LIBC_NAMESPACE_DECL {
namespace testing {

TestDir::TestDir(cpp::string &&root_path,
                 TestDir::FileSystemEntryVector &&entries)
    : root(cpp::move(root_path)), entries(cpp::move(entries)) {
  LIBC_NAMESPACE::internal::mkdir(root.c_str(), S_IRWXU);
  for (const auto &entry : this->entries) {
    create_entry(entry);
  }
}

TestDir::~TestDir() {
  if (root.empty()) {
    return;
  }

  // Iterate in reverse to remove files before their parent directories.
  for (size_t i = entries.size(); i > 0; --i) {
    const auto &entry = entries[i - 1];
    cpp::string full_path = get_path(entry.path);
    if (entry.type == internal::FileSystemEntry::Type::Directory) {
      LIBC_NAMESPACE::internal::rmdir(full_path.c_str());
    } else {
      LIBC_NAMESPACE::internal::unlink(full_path.c_str());
    }
  }

  LIBC_NAMESPACE::internal::rmdir(root.c_str());
}

cpp::string TestDir::absolute_path(cpp::string_view relative_path) const {
  cpp::string full_path = root;
  if (!relative_path.empty() && relative_path[0] != '/') {
    full_path += "/";
  }
  full_path += relative_path;
  return full_path;
}

void TestDir::create_entry(const internal::FileSystemEntry &entry) {
  cpp::string full_path = absolute_path(entry.path);

  switch (entry.type) {
  case internal::FileSystemEntry::Type::File: {
    auto result = LIBC_NAMESPACE::internal::open(full_path.c_str(),
                                                 O_CREAT | O_WRONLY, S_IRWXU);
    if (result.has_value()) {
      LIBC_NAMESPACE::internal::close(result.value());
    }
    break;
  }
  case internal::FileSystemEntry::Type::Directory:
    LIBC_NAMESPACE::internal::mkdir(full_path.c_str(), S_IRWXU);
    break;
  case internal::FileSystemEntry::Type::Symlink:
    LIBC_NAMESPACE::internal::symlink(entry.target.c_str(), full_path.c_str());
    break;
  }
}

TestDir TestDirBuilder::build() {
  cpp::string root_path =
      static_cast<const char *>(libc_make_test_file_path(root_name.data()));
  if (!root_path.empty() && root_path[0] != '/') {
    char buf[PATH_MAX];
    LIBC_ASSERT(LIBC_NAMESPACE::internal::getcwd(buf, PATH_MAX));
    cpp::string absolute_root = buf;
    absolute_root += "/";
    absolute_root += root_path;
    root_path = absolute_root;
  }
  return TestDir(cpp::move(root_path), cpp::move(entries));
}

TestDirBuilder &TestDirBuilder::add_file(cpp::string path) {
  bool success = entries.push_back(
      {internal::FileSystemEntry::Type::File, cpp::move(path), ""});
  LIBC_ASSERT(success);
  return *this;
}

TestDirBuilder &TestDirBuilder::add_directory(cpp::string path) {
  bool success = entries.push_back(
      {internal::FileSystemEntry::Type::Directory, cpp::move(path), ""});
  LIBC_ASSERT(success);
  return *this;
}

TestDirBuilder &TestDirBuilder::add_symlink(cpp::string path,
                                            cpp::string target) {
  bool success = entries.push_back({internal::FileSystemEntry::Type::Symlink,
                                    cpp::move(path), cpp::move(target)});
  LIBC_ASSERT(success);
  return *this;
}

ChangeDirGuard::ChangeDirGuard(cpp::string_view new_cwd) {
  char buf[PATH_MAX];
  if (LIBC_NAMESPACE::internal::getcwd(buf, PATH_MAX).has_value()) {
    old_cwd = cpp::string_view(buf);
    LIBC_NAMESPACE::internal::chdir(cpp::string(new_cwd).c_str());
  }
}

ChangeDirGuard::~ChangeDirGuard() {
  if (!old_cwd.empty()) {
    LIBC_NAMESPACE::internal::chdir(old_cwd.c_str());
  }
}

} // namespace testing
} // namespace LIBC_NAMESPACE_DECL
