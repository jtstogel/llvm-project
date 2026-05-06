"""Repository rules for configuring system kernel headers for LLVM-libc."""

_ERROR_BUILD_CONTENT = r"""
cc_library(
    name = "{}",
    deps = ["@platforms//:incompatible"],
)
"""

_KERNEL_HEADER_BUILD_CONTENT = r"""
cc_library(
    name = "kernel_headers",
    textual_hdrs = glob(["kernel_include/**/*.h"]),
    includes = ["kernel_include"],
)
"""

_CLANG_RESOURCES_BUILD_CONTENT = r"""
cc_library(
    name = "resource_headers",
    textual_hdrs = glob(["resource_include/**/*.h"]),
    includes = ["resource_include"],
)
"""

def _configure_kernel_headers_rule(repository_ctx):
    kernel_headers_path = repository_ctx.os.environ.get("LIBC_KERNEL_HEADERS", "")
    repository_ctx.symlink(kernel_headers_path, "kernel_include")
    if not kernel_headers_path:
        return _ERROR_BUILD_CONTENT.format("kernel_headers")
    return _KERNEL_HEADER_BUILD_CONTENT

def _configure_clang_resources_rule(repository_ctx):
    cc = repository_ctx.os.environ.get("CC", "clang")
    result = repository_ctx.execute([cc, "-print-resource-dir"])
    if result.return_code != 0:
        return _ERROR_BUILD_CONTENT.format("resource_headers")
    res_dir = result.stdout.strip()
    repository_ctx.symlink(res_dir + "/include", "resource_include")
    return _CLANG_RESOURCES_BUILD_CONTENT

def _libc_configure_impl(repository_ctx):
    build_content = ['package(default_visibility = ["//visibility:public"])']
    build_content.append(_configure_kernel_headers_rule(repository_ctx))
    build_content.append(_configure_clang_resources_rule(repository_ctx))
    build_content = "\n".join(build_content)
    repository_ctx.file("BUILD", build_content)

libc_configure = repository_rule(
    implementation = _libc_configure_impl,
    environ = ["LIBC_KERNEL_HEADERS", "CC"],
    doc = "Configures a bazel package for kernel headers based on the LIBC_KERNEL_HEADERS environment variable.",
)
