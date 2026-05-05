#!/bin/bash
cd "$(dirname "$0")/utils/bazel/llvm-project-overlay" && exec bazel "$@"
