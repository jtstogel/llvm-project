"""Repository rules for configuring system kernel headers for LLVM-libc."""

_ERROR_BUILD_CONTENT = r"""
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "kernel_headers",
    deps = ["@platforms//:incompatible"],
)
"""

_HEADER_BUILD_CONTENT = r"""
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "kernel_headers",
    textual_hdrs = glob(["kernel_include/**/*.h"]),
    includes = ["kernel_include"],
)
"""

def _configure_kernel_headers(repository_ctx):
    kernel_headers_path = repository_ctx.os.environ.get("LIBC_KERNEL_HEADERS", "")
    repository_ctx.symlink(kernel_headers_path, "kernel_include")
    build_content = _HEADER_BUILD_CONTENT if kernel_headers_path else _ERROR_BUILD_CONTENT
    repository_ctx.file("BUILD", build_content)


def _libc_configure_impl(repository_ctx):
    _configure_kernel_headers(repository_ctx)

libc_configure = repository_rule(
    implementation = _libc_configure_impl,
    environ = ["LIBC_KERNEL_HEADERS"],
    doc = "Configures a bazel package for kernel headers based on the LIBC_KERNEL_HEADERS environment variable.",
)
