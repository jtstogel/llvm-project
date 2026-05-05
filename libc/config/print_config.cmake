set(LLVM_LIBC_FULL_BUILD ON)
set(LIBC_TYPES_HAS_FLOAT16 ON)

include("libc/config/linux/x86_64/entrypoints.txt")

string(REPLACE ";" "\",\n\"" CLEAN_LIST "${TARGET_LIBC_ENTRYPOINTS}")
message("LIBC_ENTRYPOINTS = [\"${CLEAN_LIST}\"]")

string(REPLACE ";" "\",\n\"" CLEAN_LIST "${TARGET_LIBM_ENTRYPOINTS}")
message("LIBM_ENTRYPOINTS = [\"${CLEAN_LIST}\"]")

string(REPLACE ";" "\",\n\"" CLEAN_LIST "${TARGET_LIBMVEC_ENTRYPOINTS}")
message("LIBMVEC_ENTRYPOINTS = [\"${CLEAN_LIST}\"]")
