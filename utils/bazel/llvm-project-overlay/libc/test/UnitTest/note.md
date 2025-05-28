Testing with `alwayslink` causes duplicate symbol error, while the test runs fine when compiling without it:

```sh
$ cd utils/bazel/llvm-project-overlay

$ bazel test --config=generic_clang @llvm-project//libc/test/include:fpclassify_c_test
@llvm-project//libc/test/include:fpclassify_c_test              PASSED in 0.0s

$ bazel test --define=alwayslink_test=True --config=generic_clang @llvm-project//libc/test/include:fpclassify_c_test
Use --sandbox_debug to see verbose messages from the sandbox and retain the sandbox build root for debugging
ld.lld: error: duplicate symbol: main
>>> defined at fpclassify_test.c
>>>            bazel-out/k8-fastbuild/bin/external/llvm-project/libc/test/include/_objs/fpclassify_c_test/fpclassify_test.pic.o:(main)
>>> defined at LibcTestMain.cpp
>>>            bazel-out/k8-fastbuild/bin/external/llvm-project/libc/test/UnitTest/_objs/LibcUnitTest/LibcTestMain.pic.o:(.text+0x0)
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```


`main()` can get clobbered:

```
$ bazel test @llvm-project//libc/test/include:example_uses_framework_main_test
@llvm-project//libc/test/include:example_uses_framework_main_test       FAILED in 0.0s

$ bazel test @llvm-project//libc/test/include:example_uses_custom_main_test
@llvm-project//libc/test/include:example_uses_custom_main_test          PASSED in 0.0s
```