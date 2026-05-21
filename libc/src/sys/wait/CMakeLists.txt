if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${LIBC_TARGET_OS})
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${LIBC_TARGET_OS})
endif()

add_header_library(
  wait4Impl
  HDRS
    wait4Impl.h
  DEPENDS
    libc.include.signal
    libc.include.sys_syscall
    libc.include.sys_wait
    libc.src.__support.common
    libc.src.__support.error_or
    libc.src.__support.OSUtil.osutil
    libc.src.errno.errno
)

add_entrypoint_object(
  wait
  ALIAS
  DEPENDS
    .${LIBC_TARGET_OS}.wait
)

add_entrypoint_object(
  wait4
  ALIAS
  DEPENDS
    .${LIBC_TARGET_OS}.wait4
)

add_entrypoint_object(
  waitpid
  ALIAS
  DEPENDS
    .${LIBC_TARGET_OS}.waitpid
)
