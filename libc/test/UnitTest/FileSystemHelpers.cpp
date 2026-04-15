//===-- Implementation of filesystem setup for libc unittests -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "test/UnitTest/FileSystemHelpers.h"
#include "src/__support/CPP/string.h"
#include "test/UnitTest/Test.h"

#include "src/fcntl/open.h"
#include "src/sys/stat/mkdir.h"
#include "src/unistd/chdir.h"
#include "src/unistd/close.h"
#include "src/unistd/getcwd.h"
#include "src/unistd/rmdir.h"
#include "src/unistd/symlink.h"
#include "src/unistd/unlink.h"

#include <fcntl.h>
#include <sys/stat.h>

namespace LIBC_NAMESPACE_DECL {
namespace testing {

TestDir::TestDir(cpp::string &&root_path,
                 TestDir::FileSystemEntryVector &&entries)
    : root(cpp::move(root_path)), entries(cpp::move(entries)) {
  LIBC_NAMESPACE::mkdir(root.c_str(), S_IRWXU);
  for (const auto &entry : this->entries) {
    create_entry(entry);
  }
}

TestDir::~TestDir() {
  if (root.empty())
    return;

  // Iterate in reverse to remove files before their parent directories.
  for (size_t i = entries.size(); i > 0; --i) {
    const auto &entry = entries[i - 1];
    cpp::string full_path = get_path(entry.path);
    if (entry.type == internal::FileSystemEntry::Type::Directory)
      LIBC_NAMESPACE::rmdir(full_path.c_str());
    else
      LIBC_NAMESPACE::unlink(full_path.c_str());
  }

  LIBC_NAMESPACE::rmdir(root.c_str());
}

cpp::string TestDir::absolute_path(cpp::string_view relative_path) const {
  cpp::string full_path = root;
  if (!relative_path.empty() && relative_path[0] != '/')
    full_path += "/";
  full_path += relative_path;
  return full_path;
}

void TestDir::create_entry(const internal::FileSystemEntry &entry) {
  cpp::string full_path = absolute_path(entry.path);

  switch (entry.type) {
  case internal::FileSystemEntry::Type::File: {
    int fd =
        LIBC_NAMESPACE::open(full_path.c_str(), O_CREAT | O_WRONLY, S_IRWXU);
    if (fd >= 0) {
      LIBC_NAMESPACE::close(fd);
    }
    break;
  }
  case internal::FileSystemEntry::Type::Directory:
    LIBC_NAMESPACE::mkdir(full_path.c_str(), S_IRWXU);
    break;
  case internal::FileSystemEntry::Type::Symlink:
    LIBC_NAMESPACE::symlink(entry.target.c_str(), full_path.c_str());
    break;
  }
}

TestDir TestDirBuilder::build() {
  return TestDir(cpp::string(static_cast<const char *>(
                     libc_make_test_file_path(cpp::string(root_name).c_str()))),
                 cpp::move(entries));
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
  if (LIBC_NAMESPACE::getcwd(buf, PATH_MAX)) {
    old_cwd = cpp::string_view(buf);
    LIBC_NAMESPACE::chdir(cpp::string(new_cwd).c_str());
  }
}

ChangeDirGuard::~ChangeDirGuard() {
  if (!old_cwd.empty()) {
    LIBC_NAMESPACE::chdir(old_cwd.c_str());
  }
}

} // namespace testing
} // namespace LIBC_NAMESPACE_DECL
