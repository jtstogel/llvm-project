LIBC_ENTRYPOINTS = [
    "isalnum",  # libc.src.ctype
    "isalpha",  # libc.src.ctype
    "isascii",  # libc.src.ctype
    "isblank",  # libc.src.ctype
    "iscntrl",  # libc.src.ctype
    "isdigit",  # libc.src.ctype
    "isgraph",  # libc.src.ctype
    "islower",  # libc.src.ctype
    "isprint",  # libc.src.ctype
    "ispunct",  # libc.src.ctype
    "isspace",  # libc.src.ctype
    "isupper",  # libc.src.ctype
    "isxdigit",  # libc.src.ctype
    "toascii",  # libc.src.ctype
    "tolower",  # libc.src.ctype
    "toupper",  # libc.src.ctype
    # "dladdr",  # missing bazel rule  # libc.src.dlfcn
    # "dlclose",  # missing bazel rule  # libc.src.dlfcn
    # "dlerror",  # missing bazel rule  # libc.src.dlfcn
    # "dlopen",  # missing bazel rule  # libc.src.dlfcn
    # "dlsym",  # missing bazel rule  # libc.src.dlfcn
    "errno",  # libc.src.errno
    "creat",  # libc.src.fcntl
    "fcntl",  # libc.src.fcntl
    "open",  # libc.src.fcntl
    "openat",  # libc.src.fcntl
    # "poll",  # missing bazel rule  # libc.src.poll
    # "getcpu",  # missing bazel rule  # libc.src.sched
    # "sched_get_priority_max",  # missing bazel rule  # libc.src.sched
    # "sched_get_priority_min",  # missing bazel rule  # libc.src.sched
    # "sched_getaffinity",  # missing bazel rule  # libc.src.sched
    # "sched_getcpu",  # missing bazel rule  # libc.src.sched
    # "sched_getparam",  # missing bazel rule  # libc.src.sched
    # "sched_getscheduler",  # missing bazel rule  # libc.src.sched
    # "sched_rr_get_interval",  # missing bazel rule  # libc.src.sched
    # "sched_setaffinity",  # missing bazel rule  # libc.src.sched
    # "sched_setparam",  # missing bazel rule  # libc.src.sched
    # "sched_setscheduler",  # missing bazel rule  # libc.src.sched
    # "sched_yield",  # missing bazel rule  # libc.src.sched
    "memccpy",  # libc.src.string
    "memchr",  # libc.src.string
    "memcmp",  # libc.src.string
    "memcpy",  # libc.src.string
    "memmem",  # libc.src.string
    "memmove",  # libc.src.string
    "mempcpy",  # libc.src.string
    "memrchr",  # libc.src.string
    "memset",  # libc.src.string
    "memset_explicit",  # libc.src.string
    "stpcpy",  # libc.src.string
    "stpncpy",  # libc.src.string
    "strcasestr",  # libc.src.string
    "strcat",  # libc.src.string
    "strchr",  # libc.src.string
    "strchrnul",  # libc.src.string
    "strcmp",  # libc.src.string
    # "strcoll",  # missing bazel rule  # libc.src.string
    "strcpy",  # libc.src.string
    "strcspn",  # libc.src.string
    # "strdup",  # missing bazel rule  # libc.src.string
    # "strerror",  # missing bazel rule  # libc.src.string
    # "strerror_r",  # missing bazel rule  # libc.src.string
    "strlcat",  # libc.src.string
    "strlcpy",  # libc.src.string
    "strlen",  # libc.src.string
    "strncat",  # libc.src.string
    "strncmp",  # libc.src.string
    "strncpy",  # libc.src.string
    # "strndup",  # missing bazel rule  # libc.src.string
    "strnlen",  # libc.src.string
    # "strnlen_s",  # missing bazel rule  # libc.src.string
    "strpbrk",  # libc.src.string
    "strrchr",  # libc.src.string
    "strsep",  # libc.src.string
    # "strsignal",  # missing bazel rule  # libc.src.string
    "strspn",  # libc.src.string
    "strstr",  # libc.src.string
    "strtok",  # libc.src.string
    "strtok_r",  # libc.src.string
    # "strxfrm",  # missing bazel rule  # libc.src.string
    "bcmp",  # libc.src.strings
    "bcopy",  # libc.src.strings
    "bzero",  # libc.src.strings
    # "ffs",  # missing bazel rule  # libc.src.strings
    # "ffsl",  # missing bazel rule  # libc.src.strings
    # "ffsll",  # missing bazel rule  # libc.src.strings
    "index",  # libc.src.strings
    "rindex",  # libc.src.strings
    "strcasecmp",  # libc.src.strings
    "strncasecmp",  # libc.src.strings
    "imaxabs",  # libc.src.inttypes
    "imaxdiv",  # libc.src.inttypes
    "strtoimax",  # libc.src.inttypes
    "strtoumax",  # libc.src.inttypes
    "stdc_bit_ceil_uc",  # libc.src.stdbit
    "stdc_bit_ceil_ui",  # libc.src.stdbit
    "stdc_bit_ceil_ul",  # libc.src.stdbit
    "stdc_bit_ceil_ull",  # libc.src.stdbit
    "stdc_bit_ceil_us",  # libc.src.stdbit
    "stdc_bit_floor_uc",  # libc.src.stdbit
    "stdc_bit_floor_ui",  # libc.src.stdbit
    "stdc_bit_floor_ul",  # libc.src.stdbit
    "stdc_bit_floor_ull",  # libc.src.stdbit
    "stdc_bit_floor_us",  # libc.src.stdbit
    "stdc_bit_width_uc",  # libc.src.stdbit
    "stdc_bit_width_ui",  # libc.src.stdbit
    "stdc_bit_width_ul",  # libc.src.stdbit
    "stdc_bit_width_ull",  # libc.src.stdbit
    "stdc_bit_width_us",  # libc.src.stdbit
    "stdc_count_ones_uc",  # libc.src.stdbit
    "stdc_count_ones_ui",  # libc.src.stdbit
    "stdc_count_ones_ul",  # libc.src.stdbit
    "stdc_count_ones_ull",  # libc.src.stdbit
    "stdc_count_ones_us",  # libc.src.stdbit
    "stdc_count_zeros_uc",  # libc.src.stdbit
    "stdc_count_zeros_ui",  # libc.src.stdbit
    "stdc_count_zeros_ul",  # libc.src.stdbit
    "stdc_count_zeros_ull",  # libc.src.stdbit
    "stdc_count_zeros_us",  # libc.src.stdbit
    "stdc_first_leading_one_uc",  # libc.src.stdbit
    "stdc_first_leading_one_ui",  # libc.src.stdbit
    "stdc_first_leading_one_ul",  # libc.src.stdbit
    "stdc_first_leading_one_ull",  # libc.src.stdbit
    "stdc_first_leading_one_us",  # libc.src.stdbit
    "stdc_first_leading_zero_uc",  # libc.src.stdbit
    "stdc_first_leading_zero_ui",  # libc.src.stdbit
    "stdc_first_leading_zero_ul",  # libc.src.stdbit
    "stdc_first_leading_zero_ull",  # libc.src.stdbit
    "stdc_first_leading_zero_us",  # libc.src.stdbit
    "stdc_first_trailing_one_uc",  # libc.src.stdbit
    "stdc_first_trailing_one_ui",  # libc.src.stdbit
    "stdc_first_trailing_one_ul",  # libc.src.stdbit
    "stdc_first_trailing_one_ull",  # libc.src.stdbit
    "stdc_first_trailing_one_us",  # libc.src.stdbit
    "stdc_first_trailing_zero_uc",  # libc.src.stdbit
    "stdc_first_trailing_zero_ui",  # libc.src.stdbit
    "stdc_first_trailing_zero_ul",  # libc.src.stdbit
    "stdc_first_trailing_zero_ull",  # libc.src.stdbit
    "stdc_first_trailing_zero_us",  # libc.src.stdbit
    "stdc_has_single_bit_uc",  # libc.src.stdbit
    "stdc_has_single_bit_ui",  # libc.src.stdbit
    "stdc_has_single_bit_ul",  # libc.src.stdbit
    "stdc_has_single_bit_ull",  # libc.src.stdbit
    "stdc_has_single_bit_us",  # libc.src.stdbit
    "stdc_leading_ones_uc",  # libc.src.stdbit
    "stdc_leading_ones_ui",  # libc.src.stdbit
    "stdc_leading_ones_ul",  # libc.src.stdbit
    "stdc_leading_ones_ull",  # libc.src.stdbit
    "stdc_leading_ones_us",  # libc.src.stdbit
    "stdc_leading_zeros_uc",  # libc.src.stdbit
    "stdc_leading_zeros_ui",  # libc.src.stdbit
    "stdc_leading_zeros_ul",  # libc.src.stdbit
    "stdc_leading_zeros_ull",  # libc.src.stdbit
    "stdc_leading_zeros_us",  # libc.src.stdbit
    "stdc_trailing_ones_uc",  # libc.src.stdbit
    "stdc_trailing_ones_ui",  # libc.src.stdbit
    "stdc_trailing_ones_ul",  # libc.src.stdbit
    "stdc_trailing_ones_ull",  # libc.src.stdbit
    "stdc_trailing_ones_us",  # libc.src.stdbit
    "stdc_trailing_zeros_uc",  # libc.src.stdbit
    "stdc_trailing_zeros_ui",  # libc.src.stdbit
    "stdc_trailing_zeros_ul",  # libc.src.stdbit
    "stdc_trailing_zeros_ull",  # libc.src.stdbit
    "stdc_trailing_zeros_us",  # libc.src.stdbit
    # "a64l",  # missing bazel rule  # libc.src.stdlib
    "abs",  # libc.src.stdlib
    "atof",  # libc.src.stdlib
    "atoi",  # libc.src.stdlib
    "atol",  # libc.src.stdlib
    "atoll",  # libc.src.stdlib
    "bsearch",  # libc.src.stdlib
    "div",  # libc.src.stdlib
    # "l64a",  # missing bazel rule  # libc.src.stdlib
    "labs",  # libc.src.stdlib
    "ldiv",  # libc.src.stdlib
    "llabs",  # libc.src.stdlib
    "lldiv",  # libc.src.stdlib
    # "memalignment",  # missing bazel rule  # libc.src.stdlib
    "qsort",  # libc.src.stdlib
    "qsort_r",  # libc.src.stdlib
    "rand",  # libc.src.stdlib
    "srand",  # libc.src.stdlib
    "strfromd",  # libc.src.stdlib
    "strfromf",  # libc.src.stdlib
    "strfroml",  # libc.src.stdlib
    "strtod",  # libc.src.stdlib
    "strtof",  # libc.src.stdlib
    "strtol",  # libc.src.stdlib
    "strtold",  # libc.src.stdlib
    "strtoll",  # libc.src.stdlib
    "strtoul",  # libc.src.stdlib
    "strtoull",  # libc.src.stdlib
    # "aligned_alloc",  # missing bazel rule  # libc.src.stdlib
    # "calloc",  # missing bazel rule  # libc.src.stdlib
    # "free",  # missing bazel rule  # libc.src.stdlib
    # "malloc",  # missing bazel rule  # libc.src.stdlib
    # "posix_memalign",  # missing bazel rule  # libc.src.stdlib
    # "realloc",  # missing bazel rule  # libc.src.stdlib
    # "fprintf",  # libc.src.stdio
    # "fscanf",  # libc.src.stdio
    # "vfscanf",  # libc.src.stdio
    # "printf",  # libc.src.stdio
    # "remove",  # libc.src.stdio
    # "rename",  # libc.src.stdio
    # "scanf",  # libc.src.stdio
    # "vscanf",  # libc.src.stdio
    # "snprintf",  # libc.src.stdio
    # "sprintf",  # libc.src.stdio
    # "asprintf",  # libc.src.stdio
    # "sscanf",  # libc.src.stdio
    # "stderr",  # libc.src.stdio
    # "stdin",  # libc.src.stdio
    # "stdout",  # libc.src.stdio
    # "vsscanf",  # libc.src.stdio
    # "vfprintf",  # libc.src.stdio
    # "vprintf",  # libc.src.stdio
    # "vsnprintf",  # libc.src.stdio
    # "vsprintf",  # libc.src.stdio
    # "vasprintf",  # libc.src.stdio
    "epoll_create",  # libc.src.sys.epoll
    "epoll_create1",  # libc.src.sys.epoll
    "epoll_ctl",  # libc.src.sys.epoll
    "epoll_pwait",  # libc.src.sys.epoll
    "epoll_wait",  # libc.src.sys.epoll
    # "ioctl",  # missing bazel rule  # libc.src.sys.ioctl
    # "ftok",  # missing bazel rule  # libc.src.sys.ipc
    "madvise",  # libc.src.sys.mman
    "mincore",  # libc.src.sys.mman
    "mlock",  # libc.src.sys.mman
    "mlock2",  # libc.src.sys.mman
    "mlockall",  # libc.src.sys.mman
    "mmap",  # libc.src.sys.mman
    "mremap",  # libc.src.sys.mman
    "mprotect",  # libc.src.sys.mman
    "msync",  # libc.src.sys.mman
    "munlock",  # libc.src.sys.mman
    "munlockall",  # libc.src.sys.mman
    "munmap",  # libc.src.sys.mman
    "pkey_alloc",  # libc.src.sys.mman
    "pkey_free",  # libc.src.sys.mman
    "pkey_get",  # libc.src.sys.mman
    "pkey_mprotect",  # libc.src.sys.mman
    "pkey_set",  # libc.src.sys.mman
    "remap_file_pages",  # libc.src.sys.mman
    "posix_madvise",  # libc.src.sys.mman
    "shm_open",  # libc.src.sys.mman
    "shm_unlink",  # libc.src.sys.mman
    # "getrandom",  # missing bazel rule  # libc.src.sys.random
    "getrlimit",  # libc.src.sys.resource
    "setrlimit",  # libc.src.sys.resource
    # "semget",  # missing bazel rule  # libc.src.sys.sem
    # "semctl",  # missing bazel rule  # libc.src.sys.sem
    # "semop",  # missing bazel rule  # libc.src.sys.sem
    # "sendfile",  # missing bazel rule  # libc.src.sys.sendfile
    # "accept",  # missing bazel rule  # libc.src.sys.socket
    # "accept4",  # missing bazel rule  # libc.src.sys.socket
    # "bind",  # missing bazel rule  # libc.src.sys.socket
    # "connect",  # missing bazel rule  # libc.src.sys.socket
    "getsockopt",  # libc.src.sys.socket
    # "listen",  # missing bazel rule  # libc.src.sys.socket
    "recv",  # libc.src.sys.socket
    "recvfrom",  # libc.src.sys.socket
    "send",  # libc.src.sys.socket
    "sendto",  # libc.src.sys.socket
    # "setsockopt",  # missing bazel rule  # libc.src.sys.socket
    # "shutdown",  # missing bazel rule  # libc.src.sys.socket
    "socket",  # libc.src.sys.socket
    "socketpair",  # libc.src.sys.socket
    "recvmsg",  # libc.src.sys.socket
    "sendmsg",  # libc.src.sys.socket
    # "chmod",  # missing bazel rule  # libc.src.sys.stat
    # "fchmod",  # missing bazel rule  # libc.src.sys.stat
    # "fchmodat",  # missing bazel rule  # libc.src.sys.stat
    # "fstat",  # missing bazel rule  # libc.src.sys.stat
    # "lstat",  # missing bazel rule  # libc.src.sys.stat
    "mkdir",  # libc.src.sys.stat
    "mkdirat",  # libc.src.sys.stat
    # "stat",  # missing bazel rule  # libc.src.sys.stat
    # "utimensat",  # missing bazel rule  # libc.src.sys.stat
    # "fstatvfs",  # missing bazel rule  # libc.src.sys.statvfs
    # "statvfs",  # missing bazel rule  # libc.src.sys.statvfs
    # "utimes",  # missing bazel rule  # libc.src.sys.time
    # "uname",  # missing bazel rule  # libc.src.sys.utsname
    # "wait",  # missing bazel rule  # libc.src.sys.wait
    # "wait4",  # missing bazel rule  # libc.src.sys.wait
    # "waitpid",  # missing bazel rule  # libc.src.sys.wait
    # "prctl",  # missing bazel rule  # libc.src.sys.prctl
    # "personality",  # missing bazel rule  # libc.src.sys.personality
    # "getauxval",  # missing bazel rule  # libc.src.sys.auxv
    # "cfgetispeed",  # missing bazel rule  # libc.src.termios
    # "cfgetospeed",  # missing bazel rule  # libc.src.termios
    # "cfsetispeed",  # missing bazel rule  # libc.src.termios
    # "cfsetospeed",  # missing bazel rule  # libc.src.termios
    # "tcdrain",  # missing bazel rule  # libc.src.termios
    # "tcflow",  # missing bazel rule  # libc.src.termios
    # "tcflush",  # missing bazel rule  # libc.src.termios
    # "tcgetattr",  # missing bazel rule  # libc.src.termios
    # "tcgetsid",  # missing bazel rule  # libc.src.termios
    # "tcsendbreak",  # missing bazel rule  # libc.src.termios
    # "tcsetattr",  # missing bazel rule  # libc.src.termios
    "access",  # libc.src.unistd
    "chdir",  # libc.src.unistd
    # "chown",  # missing bazel rule  # libc.src.unistd
    "close",  # libc.src.unistd
    "dup",  # libc.src.unistd
    "dup2",  # libc.src.unistd
    "dup3",  # libc.src.unistd
    # "execve",  # missing bazel rule  # libc.src.unistd
    # "faccessat",  # missing bazel rule  # libc.src.unistd
    "fchdir",  # libc.src.unistd
    # "fchown",  # missing bazel rule  # libc.src.unistd
    # "fpathconf",  # missing bazel rule  # libc.src.unistd
    "fsync",  # libc.src.unistd
    "ftruncate",  # libc.src.unistd
    # "getcwd",  # missing bazel rule  # libc.src.unistd
    # "getentropy",  # missing bazel rule  # libc.src.unistd
    "geteuid",  # libc.src.unistd
    # "gethostname",  # missing bazel rule  # libc.src.unistd
    "getpagesize",  # libc.src.unistd
    # "getpid",  # missing bazel rule  # libc.src.unistd
    "getppid",  # libc.src.unistd
    # "getsid",  # missing bazel rule  # libc.src.unistd
    # "gettid",  # missing bazel rule  # libc.src.unistd
    # "getgid",  # missing bazel rule  # libc.src.unistd
    "getuid",  # libc.src.unistd
    "isatty",  # libc.src.unistd
    "link",  # libc.src.unistd
    "linkat",  # libc.src.unistd
    "lseek",  # libc.src.unistd
    # "pathconf",  # missing bazel rule  # libc.src.unistd
    "pipe",  # libc.src.unistd
    # "pipe2",  # missing bazel rule  # libc.src.unistd
    "pread",  # libc.src.unistd
    "pwrite",  # libc.src.unistd
    "read",  # libc.src.unistd
    "readlink",  # libc.src.unistd
    "readlinkat",  # libc.src.unistd
    "rmdir",  # libc.src.unistd
    # "setsid",  # missing bazel rule  # libc.src.unistd
    "symlink",  # libc.src.unistd
    "symlinkat",  # libc.src.unistd
    "sysconf",  # libc.src.unistd
    "truncate",  # libc.src.unistd
    "unlink",  # libc.src.unistd
    "unlinkat",  # libc.src.unistd
    "write",  # libc.src.unistd
    "btowc",  # libc.src.wchar
    "wcslen",  # libc.src.wchar
    # "wcsnlen",  # missing bazel rule  # libc.src.wchar
    "wctob",  # libc.src.wchar
    "wmemmove",  # libc.src.wchar
    "wmemset",  # libc.src.wchar
    "wcschr",  # libc.src.wchar
    "wcsncmp",  # libc.src.wchar
    # "wcsxfrm",  # missing bazel rule  # libc.src.wchar
    "wcscmp",  # libc.src.wchar
    # "wcscoll",  # missing bazel rule  # libc.src.wchar
    "wcspbrk",  # libc.src.wchar
    "wcsrchr",  # libc.src.wchar
    "wcsspn",  # libc.src.wchar
    "wcscspn",  # libc.src.wchar
    # "wcsdup",  # missing bazel rule  # libc.src.wchar
    "wmemcmp",  # libc.src.wchar
    "wmempcpy",  # libc.src.wchar
    "wmemcpy",  # libc.src.wchar
    "wcsncpy",  # libc.src.wchar
    "wcscat",  # libc.src.wchar
    "wcsstr",  # libc.src.wchar
    "wcsncat",  # libc.src.wchar
    "wcslcat",  # libc.src.wchar
    "wcscpy",  # libc.src.wchar
    "wcslcpy",  # libc.src.wchar
    "wmemchr",  # libc.src.wchar
    "wcpcpy",  # libc.src.wchar
    "wcpncpy",  # libc.src.wchar
    # "wcstod",  # missing bazel rule  # libc.src.wchar
    # "wcstof",  # missing bazel rule  # libc.src.wchar
    # "wcstok",  # missing bazel rule  # libc.src.wchar
    # "wcstol",  # missing bazel rule  # libc.src.wchar
    # "wcstold",  # missing bazel rule  # libc.src.wchar
    # "wcstoll",  # missing bazel rule  # libc.src.wchar
    # "wcstoul",  # missing bazel rule  # libc.src.wchar
    # "wcstoull",  # missing bazel rule  # libc.src.wchar
    # "iswalpha",  # missing bazel rule  # libc.src.wctype
    # "iswgraph",  # missing bazel rule  # libc.src.wctype
    # "iswcntrl",  # missing bazel rule  # libc.src.wctype
    # "iswdigit",  # missing bazel rule  # libc.src.wctype
    # "iswupper",  # missing bazel rule  # libc.src.wctype
    # "iswalnum",  # missing bazel rule  # libc.src.wctype
    # "iswlower",  # missing bazel rule  # libc.src.wctype
    # "iswspace",  # missing bazel rule  # libc.src.wctype
    # "iswblank",  # missing bazel rule  # libc.src.wctype
    # "iswxdigit",  # missing bazel rule  # libc.src.wctype
    # "iswpunct",  # missing bazel rule  # libc.src.wctype
    # "iswprint",  # missing bazel rule  # libc.src.wctype
    # "iswctype",  # missing bazel rule  # libc.src.wctype
    # "wctype",  # missing bazel rule  # libc.src.wctype
    # "writev",  # missing bazel rule  # libc.src.sys.uio
    # "readv",  # missing bazel rule  # libc.src.sys.uio
    # "setitimer",  # missing bazel rule  # libc.src.sys.time
    # "getitimer",  # missing bazel rule  # libc.src.sys.time
    # "isalnum_l",  # missing bazel rule  # libc.src.ctype
    # "isalpha_l",  # missing bazel rule  # libc.src.ctype
    # "isblank_l",  # missing bazel rule  # libc.src.ctype
    # "iscntrl_l",  # missing bazel rule  # libc.src.ctype
    # "isdigit_l",  # missing bazel rule  # libc.src.ctype
    # "isgraph_l",  # missing bazel rule  # libc.src.ctype
    # "islower_l",  # missing bazel rule  # libc.src.ctype
    # "isprint_l",  # missing bazel rule  # libc.src.ctype
    # "ispunct_l",  # missing bazel rule  # libc.src.ctype
    # "isspace_l",  # missing bazel rule  # libc.src.ctype
    # "isupper_l",  # missing bazel rule  # libc.src.ctype
    # "isxdigit_l",  # missing bazel rule  # libc.src.ctype
    # "tolower_l",  # missing bazel rule  # libc.src.ctype
    # "toupper_l",  # missing bazel rule  # libc.src.ctype
    # "strtod_l",  # missing bazel rule  # libc.src.stdlib
    # "strtof_l",  # missing bazel rule  # libc.src.stdlib
    # "strtol_l",  # missing bazel rule  # libc.src.stdlib
    # "strtold_l",  # missing bazel rule  # libc.src.stdlib
    # "strtoll_l",  # missing bazel rule  # libc.src.stdlib
    # "strtoul_l",  # missing bazel rule  # libc.src.stdlib
    # "strtoull_l",  # missing bazel rule  # libc.src.stdlib
    # "strcoll_l",  # missing bazel rule  # libc.src.string
    # "strxfrm_l",  # missing bazel rule  # libc.src.string
    # "strcasecmp_l",  # missing bazel rule  # libc.src.strings
    # "strncasecmp_l",  # missing bazel rule  # libc.src.strings
    # "__assert_fail",  # missing bazel rule  # libc.src.assert
    # "__stack_chk_fail",  # missing bazel rule  # libc.src.compiler
    # "closedir",  # missing bazel rule  # libc.src.dirent
    # "dirfd",  # missing bazel rule  # libc.src.dirent
    # "opendir",  # missing bazel rule  # libc.src.dirent
    # "readdir",  # missing bazel rule  # libc.src.dirent
    # "htonl",  # missing bazel rule  # libc.src.arpa.inet
    # "htons",  # missing bazel rule  # libc.src.arpa.inet
    # "inet_addr",  # missing bazel rule  # libc.src.arpa.inet
    # "inet_aton",  # missing bazel rule  # libc.src.arpa.inet
    # "ntohl",  # missing bazel rule  # libc.src.arpa.inet
    # "ntohs",  # missing bazel rule  # libc.src.arpa.inet
    # "pthread_atfork",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_destroy",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_getdetachstate",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_getguardsize",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_getstack",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_getstacksize",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_init",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_setdetachstate",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_setguardsize",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_setstack",  # missing bazel rule  # libc.src.pthread
    # "pthread_attr_setstacksize",  # missing bazel rule  # libc.src.pthread
    # "pthread_condattr_destroy",  # missing bazel rule  # libc.src.pthread
    # "pthread_condattr_getclock",  # missing bazel rule  # libc.src.pthread
    # "pthread_condattr_getpshared",  # missing bazel rule  # libc.src.pthread
    # "pthread_condattr_init",  # missing bazel rule  # libc.src.pthread
    # "pthread_condattr_setclock",  # missing bazel rule  # libc.src.pthread
    # "pthread_condattr_setpshared",  # missing bazel rule  # libc.src.pthread
    # "pthread_cond_broadcast",  # missing bazel rule  # libc.src.pthread
    # "pthread_cond_clockwait",  # missing bazel rule  # libc.src.pthread
    # "pthread_cond_destroy",  # missing bazel rule  # libc.src.pthread
    # "pthread_cond_init",  # missing bazel rule  # libc.src.pthread
    # "pthread_cond_signal",  # missing bazel rule  # libc.src.pthread
    # "pthread_cond_timedwait",  # missing bazel rule  # libc.src.pthread
    # "pthread_cond_wait",  # missing bazel rule  # libc.src.pthread
    # "pthread_create",  # missing bazel rule  # libc.src.pthread
    # "pthread_detach",  # missing bazel rule  # libc.src.pthread
    # "pthread_equal",  # missing bazel rule  # libc.src.pthread
    # "pthread_exit",  # missing bazel rule  # libc.src.pthread
    # "pthread_getname_np",  # missing bazel rule  # libc.src.pthread
    # "pthread_getspecific",  # missing bazel rule  # libc.src.pthread
    # "pthread_join",  # missing bazel rule  # libc.src.pthread
    # "pthread_key_create",  # missing bazel rule  # libc.src.pthread
    # "pthread_key_delete",  # missing bazel rule  # libc.src.pthread
    # "pthread_barrier_init",  # missing bazel rule  # libc.src.pthread
    # "pthread_barrier_wait",  # missing bazel rule  # libc.src.pthread
    # "pthread_barrier_destroy",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutex_destroy",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutex_init",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutex_lock",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutex_trylock",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutex_unlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutexattr_destroy",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutexattr_getpshared",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutexattr_getrobust",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutexattr_gettype",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutexattr_init",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutexattr_setpshared",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutexattr_setrobust",  # missing bazel rule  # libc.src.pthread
    # "pthread_mutexattr_settype",  # missing bazel rule  # libc.src.pthread
    # "pthread_once",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_clockrdlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_clockwrlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_destroy",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_init",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_rdlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_timedrdlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_timedwrlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_tryrdlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_trywrlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_unlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlock_wrlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlockattr_destroy",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlockattr_getkind_np",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlockattr_getpshared",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlockattr_init",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlockattr_setkind_np",  # missing bazel rule  # libc.src.pthread
    # "pthread_rwlockattr_setpshared",  # missing bazel rule  # libc.src.pthread
    # "pthread_spin_destroy",  # missing bazel rule  # libc.src.pthread
    # "pthread_spin_init",  # missing bazel rule  # libc.src.pthread
    # "pthread_spin_lock",  # missing bazel rule  # libc.src.pthread
    # "pthread_spin_trylock",  # missing bazel rule  # libc.src.pthread
    # "pthread_spin_unlock",  # missing bazel rule  # libc.src.pthread
    # "pthread_self",  # missing bazel rule  # libc.src.pthread
    # "pthread_setname_np",  # missing bazel rule  # libc.src.pthread
    # "pthread_setspecific",  # missing bazel rule  # libc.src.pthread
    # "__sched_getcpucount",  # missing bazel rule  # libc.src.sched
    # "__sched_setcpuzero",  # missing bazel rule  # libc.src.sched
    # "__sched_setcpuset",  # missing bazel rule  # libc.src.sched
    # "__sched_getcpuisset",  # missing bazel rule  # libc.src.sched
    # "longjmp",  # missing bazel rule  # libc.src.setjmp
    # "setjmp",  # missing bazel rule  # libc.src.setjmp
    # "siglongjmp",  # missing bazel rule  # libc.src.setjmp
    # "sigsetjmp",  # missing bazel rule  # libc.src.setjmp
    # "getcontext",  # missing bazel rule  # libc.src.ucontext
    # "setcontext",  # missing bazel rule  # libc.src.ucontext
    # "clearerr",  # missing bazel rule  # libc.src.stdio
    # "clearerr_unlocked",  # missing bazel rule  # libc.src.stdio
    # "fclose",  # missing bazel rule  # libc.src.stdio
    # "fdopen",  # missing bazel rule  # libc.src.stdio
    # "feof",  # missing bazel rule  # libc.src.stdio
    # "feof_unlocked",  # missing bazel rule  # libc.src.stdio
    # "ferror",  # missing bazel rule  # libc.src.stdio
    # "ferror_unlocked",  # missing bazel rule  # libc.src.stdio
    # "fflush",  # missing bazel rule  # libc.src.stdio
    # "fgetc",  # missing bazel rule  # libc.src.stdio
    # "fgetc_unlocked",  # missing bazel rule  # libc.src.stdio
    # "fgets",  # missing bazel rule  # libc.src.stdio
    # "fileno",  # missing bazel rule  # libc.src.stdio
    # "flockfile",  # missing bazel rule  # libc.src.stdio
    # "fopen",  # missing bazel rule  # libc.src.stdio
    # "fopencookie",  # missing bazel rule  # libc.src.stdio
    # "fputc",  # missing bazel rule  # libc.src.stdio
    # "fputs",  # missing bazel rule  # libc.src.stdio
    # "fread",  # missing bazel rule  # libc.src.stdio
    # "fread_unlocked",  # missing bazel rule  # libc.src.stdio
    # "fseek",  # missing bazel rule  # libc.src.stdio
    # "fseeko",  # missing bazel rule  # libc.src.stdio
    # "ftell",  # missing bazel rule  # libc.src.stdio
    # "ftello",  # missing bazel rule  # libc.src.stdio
    # "funlockfile",  # missing bazel rule  # libc.src.stdio
    # "fwrite",  # missing bazel rule  # libc.src.stdio
    # "fwrite_unlocked",  # missing bazel rule  # libc.src.stdio
    # "getc",  # missing bazel rule  # libc.src.stdio
    # "getc_unlocked",  # missing bazel rule  # libc.src.stdio
    # "getchar",  # missing bazel rule  # libc.src.stdio
    # "getchar_unlocked",  # missing bazel rule  # libc.src.stdio
    # "perror",  # missing bazel rule  # libc.src.stdio
    # "putc",  # missing bazel rule  # libc.src.stdio
    # "putchar",  # missing bazel rule  # libc.src.stdio
    # "puts",  # missing bazel rule  # libc.src.stdio
    # "rewind",  # missing bazel rule  # libc.src.stdio
    # "setbuf",  # missing bazel rule  # libc.src.stdio
    # "setvbuf",  # missing bazel rule  # libc.src.stdio
    # "stderr",  # missing bazel rule  # libc.src.stdio
    # "stdin",  # missing bazel rule  # libc.src.stdio
    # "stdout",  # missing bazel rule  # libc.src.stdio
    # "ungetc",  # missing bazel rule  # libc.src.stdio
    # "_Exit",  # missing bazel rule  # libc.src.stdlib
    # "abort",  # missing bazel rule  # libc.src.stdlib
    # "at_quick_exit",  # missing bazel rule  # libc.src.stdlib
    # "atexit",  # missing bazel rule  # libc.src.stdlib
    # "exit",  # missing bazel rule  # libc.src.stdlib
    # "getenv",  # missing bazel rule  # libc.src.stdlib
    # "mbstowcs",  # missing bazel rule  # libc.src.stdlib
    # "mbtowc",  # missing bazel rule  # libc.src.stdlib
    # "quick_exit",  # missing bazel rule  # libc.src.stdlib
    # "wcstombs",  # missing bazel rule  # libc.src.stdlib
    # "wctomb",  # missing bazel rule  # libc.src.stdlib
    # "kill",  # missing bazel rule  # libc.src.signal
    # "raise",  # missing bazel rule  # libc.src.signal
    # "sigaction",  # missing bazel rule  # libc.src.signal
    # "sigaddset",  # missing bazel rule  # libc.src.signal
    # "sigaltstack",  # missing bazel rule  # libc.src.signal
    # "sigdelset",  # missing bazel rule  # libc.src.signal
    # "sigemptyset",  # missing bazel rule  # libc.src.signal
    # "sigfillset",  # missing bazel rule  # libc.src.signal
    # "signal",  # missing bazel rule  # libc.src.signal
    # "sigprocmask",  # missing bazel rule  # libc.src.signal
    # "posix_spawn",  # missing bazel rule  # libc.src.spawn
    # "posix_spawn_file_actions_addclose",  # missing bazel rule  # libc.src.spawn
    # "posix_spawn_file_actions_adddup2",  # missing bazel rule  # libc.src.spawn
    # "posix_spawn_file_actions_addopen",  # missing bazel rule  # libc.src.spawn
    # "posix_spawn_file_actions_destroy",  # missing bazel rule  # libc.src.spawn
    # "posix_spawn_file_actions_init",  # missing bazel rule  # libc.src.spawn
    # "hcreate",  # missing bazel rule  # libc.src.search
    # "hcreate_r",  # missing bazel rule  # libc.src.search
    # "hdestroy",  # missing bazel rule  # libc.src.search
    # "hdestroy_r",  # missing bazel rule  # libc.src.search
    # "hsearch",  # missing bazel rule  # libc.src.search
    # "hsearch_r",  # missing bazel rule  # libc.src.search
    # "insque",  # missing bazel rule  # libc.src.search
    # "lfind",  # missing bazel rule  # libc.src.search
    # "lsearch",  # missing bazel rule  # libc.src.search
    # "remque",  # missing bazel rule  # libc.src.search
    # "tdelete",  # missing bazel rule  # libc.src.search
    # "tdestroy",  # missing bazel rule  # libc.src.search
    # "tfind",  # missing bazel rule  # libc.src.search
    # "tsearch",  # missing bazel rule  # libc.src.search
    # "twalk",  # missing bazel rule  # libc.src.search
    # "twalk_r",  # missing bazel rule  # libc.src.search
    # "call_once",  # missing bazel rule  # libc.src.threads
    # "cnd_broadcast",  # missing bazel rule  # libc.src.threads
    # "cnd_destroy",  # missing bazel rule  # libc.src.threads
    # "cnd_init",  # missing bazel rule  # libc.src.threads
    # "cnd_signal",  # missing bazel rule  # libc.src.threads
    # "cnd_wait",  # missing bazel rule  # libc.src.threads
    # "mtx_destroy",  # missing bazel rule  # libc.src.threads
    # "mtx_init",  # missing bazel rule  # libc.src.threads
    # "mtx_lock",  # missing bazel rule  # libc.src.threads
    # "mtx_unlock",  # missing bazel rule  # libc.src.threads
    # "thrd_create",  # missing bazel rule  # libc.src.threads
    # "thrd_current",  # missing bazel rule  # libc.src.threads
    # "thrd_detach",  # missing bazel rule  # libc.src.threads
    # "thrd_equal",  # missing bazel rule  # libc.src.threads
    # "thrd_exit",  # missing bazel rule  # libc.src.threads
    # "thrd_join",  # missing bazel rule  # libc.src.threads
    # "tss_create",  # missing bazel rule  # libc.src.threads
    # "tss_delete",  # missing bazel rule  # libc.src.threads
    # "tss_get",  # missing bazel rule  # libc.src.threads
    # "tss_set",  # missing bazel rule  # libc.src.threads
    # "asctime",  # missing bazel rule  # libc.src.time
    # "asctime_r",  # missing bazel rule  # libc.src.time
    # "ctime",  # missing bazel rule  # libc.src.time
    # "ctime_r",  # missing bazel rule  # libc.src.time
    # "clock",  # missing bazel rule  # libc.src.time
    # "clock_gettime",  # missing bazel rule  # libc.src.time
    # "clock_settime",  # missing bazel rule  # libc.src.time
    # "difftime",  # missing bazel rule  # libc.src.time
    # "gettimeofday",  # missing bazel rule  # libc.src.time
    # "gmtime",  # missing bazel rule  # libc.src.time
    # "gmtime_r",  # missing bazel rule  # libc.src.time
    # "localtime",  # missing bazel rule  # libc.src.time
    # "localtime_r",  # missing bazel rule  # libc.src.time
    # "mktime",  # missing bazel rule  # libc.src.time
    # "nanosleep",  # missing bazel rule  # libc.src.time
    # "strftime",  # missing bazel rule  # libc.src.time
    # "strftime_l",  # missing bazel rule  # libc.src.time
    # "time",  # missing bazel rule  # libc.src.time
    # "timespec_get",  # missing bazel rule  # libc.src.time
    # "localeconv",  # missing bazel rule  # libc.src.locale
    # "duplocale",  # missing bazel rule  # libc.src.locale
    # "freelocale",  # missing bazel rule  # libc.src.locale
    # "localeconv",  # missing bazel rule  # libc.src.locale
    # "newlocale",  # missing bazel rule  # libc.src.locale
    # "setlocale",  # missing bazel rule  # libc.src.locale
    # "uselocale",  # missing bazel rule  # libc.src.locale
    # "__llvm_libc_syscall",  # missing bazel rule  # libc.src.unistd
    # "_exit",  # missing bazel rule  # libc.src.unistd
    "environ",  # libc.src.unistd
    # "execv",  # missing bazel rule  # libc.src.unistd
    # "fork",  # missing bazel rule  # libc.src.unistd
    # "getopt",  # missing bazel rule  # libc.src.unistd
    # "optarg",  # missing bazel rule  # libc.src.unistd
    # "opterr",  # missing bazel rule  # libc.src.unistd
    # "optind",  # missing bazel rule  # libc.src.unistd
    # "optopt",  # missing bazel rule  # libc.src.unistd
    "swab",  # libc.src.unistd
    # "select",  # missing bazel rule  # libc.src.sys.select
    # "mblen",  # missing bazel rule  # libc.src.wchar
    # "mbrlen",  # missing bazel rule  # libc.src.wchar
    # "mbsinit",  # missing bazel rule  # libc.src.wchar
    # "mbrtowc",  # missing bazel rule  # libc.src.wchar
    # "mbsrtowcs",  # missing bazel rule  # libc.src.wchar
    # "mbsnrtowcs",  # missing bazel rule  # libc.src.wchar
    # "wcrtomb",  # missing bazel rule  # libc.src.wchar
    # "wcsrtombs",  # missing bazel rule  # libc.src.wchar
    # "wcsnrtombs",  # missing bazel rule  # libc.src.wchar
    # "catopen",  # missing bazel rule  # libc.src.nl_types
    # "catclose",  # missing bazel rule  # libc.src.nl_types
    # "catgets",  # missing bazel rule  # libc.src.nl_types
]

LIBM_ENTRYPOINTS = [
    "creal",  # libc.src.complex
    "crealf",  # libc.src.complex
    "creall",  # libc.src.complex
    "cimag",  # libc.src.complex
    "cimagf",  # libc.src.complex
    "cimagl",  # libc.src.complex
    "conj",  # libc.src.complex
    "conjf",  # libc.src.complex
    "conjl",  # libc.src.complex
    "cproj",  # libc.src.complex
    "cprojf",  # libc.src.complex
    "cprojl",  # libc.src.complex
    "feclearexcept",  # libc.src.fenv
    "fedisableexcept",  # libc.src.fenv
    "feenableexcept",  # libc.src.fenv
    "fegetenv",  # libc.src.fenv
    "fegetexcept",  # libc.src.fenv
    "fegetexceptflag",  # libc.src.fenv
    "fegetround",  # libc.src.fenv
    "feholdexcept",  # libc.src.fenv
    "feraiseexcept",  # libc.src.fenv
    "fesetenv",  # libc.src.fenv
    "fesetexcept",  # libc.src.fenv
    "fesetexceptflag",  # libc.src.fenv
    "fesetround",  # libc.src.fenv
    "fetestexcept",  # libc.src.fenv
    "fetestexceptflag",  # libc.src.fenv
    "feupdateenv",  # libc.src.fenv
    "acos",  # libc.src.math
    "acosf",  # libc.src.math
    "acoshf",  # libc.src.math
    "acospif",  # libc.src.math
    "asin",  # libc.src.math
    "asinf",  # libc.src.math
    "asinhf",  # libc.src.math
    "asinpi",  # libc.src.math
    "asinpif",  # libc.src.math
    "atan2",  # libc.src.math
    "atan2f",  # libc.src.math
    "atan",  # libc.src.math
    "atanf",  # libc.src.math
    "atanhf",  # libc.src.math
    "canonicalize",  # libc.src.math
    "canonicalizef",  # libc.src.math
    "canonicalizel",  # libc.src.math
    "cbrt",  # libc.src.math
    "cbrtf",  # libc.src.math
    "cbrtbf16",  # libc.src.math
    "ceil",  # libc.src.math
    "ceilf",  # libc.src.math
    "ceill",  # libc.src.math
    "copysign",  # libc.src.math
    "copysignf",  # libc.src.math
    "copysignl",  # libc.src.math
    "cos",  # libc.src.math
    "cosf",  # libc.src.math
    "coshf",  # libc.src.math
    "cospif",  # libc.src.math
    "dfmal",  # libc.src.math
    "dmull",  # libc.src.math
    "dsqrtl",  # libc.src.math
    "daddl",  # libc.src.math
    "ddivl",  # libc.src.math
    "dsubl",  # libc.src.math
    "erff",  # libc.src.math
    "exp",  # libc.src.math
    "exp10",  # libc.src.math
    "exp10f",  # libc.src.math
    "exp10m1f",  # libc.src.math
    "exp2",  # libc.src.math
    "exp2f",  # libc.src.math
    "exp2m1f",  # libc.src.math
    "expf",  # libc.src.math
    "expm1",  # libc.src.math
    "expm1f",  # libc.src.math
    "fabs",  # libc.src.math
    "fabsf",  # libc.src.math
    "fabsl",  # libc.src.math
    "fadd",  # libc.src.math
    "faddl",  # libc.src.math
    "fdim",  # libc.src.math
    "fdimf",  # libc.src.math
    "fdiml",  # libc.src.math
    "fdiv",  # libc.src.math
    "fdivl",  # libc.src.math
    "ffma",  # libc.src.math
    "ffmal",  # libc.src.math
    "floor",  # libc.src.math
    "floorf",  # libc.src.math
    "floorl",  # libc.src.math
    "fma",  # libc.src.math
    "fmabf16",  # libc.src.math
    "fmaf",  # libc.src.math
    "fmax",  # libc.src.math
    "fmaxf",  # libc.src.math
    "fmaximum",  # libc.src.math
    "fmaximum_mag",  # libc.src.math
    "fmaximum_mag_num",  # libc.src.math
    "fmaximum_mag_numf",  # libc.src.math
    "fmaximum_mag_numl",  # libc.src.math
    "fmaximum_magf",  # libc.src.math
    "fmaximum_magl",  # libc.src.math
    "fmaximum_num",  # libc.src.math
    "fmaximum_numf",  # libc.src.math
    "fmaximum_numl",  # libc.src.math
    "fmaximumf",  # libc.src.math
    "fmaximuml",  # libc.src.math
    "fmaxl",  # libc.src.math
    "fmin",  # libc.src.math
    "fminf",  # libc.src.math
    "fminimum",  # libc.src.math
    "fminimum_mag",  # libc.src.math
    "fminimum_mag_num",  # libc.src.math
    "fminimum_mag_numf",  # libc.src.math
    "fminimum_mag_numl",  # libc.src.math
    "fminimum_magf",  # libc.src.math
    "fminimum_magl",  # libc.src.math
    "fminimum_num",  # libc.src.math
    "fminimum_numf",  # libc.src.math
    "fminimum_numl",  # libc.src.math
    "fminimumf",  # libc.src.math
    "fminimuml",  # libc.src.math
    "fminl",  # libc.src.math
    "fmod",  # libc.src.math
    "fmodf",  # libc.src.math
    "fmodl",  # libc.src.math
    "fmul",  # libc.src.math
    "fmull",  # libc.src.math
    "frexp",  # libc.src.math
    "frexpf",  # libc.src.math
    "frexpl",  # libc.src.math
    "fromfp",  # libc.src.math
    "fromfpf",  # libc.src.math
    "fromfpl",  # libc.src.math
    "fromfpx",  # libc.src.math
    "fromfpxf",  # libc.src.math
    "fromfpxl",  # libc.src.math
    "fsqrt",  # libc.src.math
    "fsqrtl",  # libc.src.math
    "fsub",  # libc.src.math
    "fsubl",  # libc.src.math
    "getpayload",  # libc.src.math
    "getpayloadf",  # libc.src.math
    "getpayloadl",  # libc.src.math
    "hypot",  # libc.src.math
    "hypotf",  # libc.src.math
    "ilogb",  # libc.src.math
    "ilogbf",  # libc.src.math
    "ilogbl",  # libc.src.math
    "iscanonical",  # libc.src.math
    "iscanonicalf",  # libc.src.math
    "iscanonicall",  # libc.src.math
    "isnan",  # libc.src.math
    "isnanf",  # libc.src.math
    "isnanl",  # libc.src.math
    "issignaling",  # libc.src.math
    "issignalingf",  # libc.src.math
    "issignalingl",  # libc.src.math
    "ldexp",  # libc.src.math
    "ldexpf",  # libc.src.math
    "ldexpl",  # libc.src.math
    "llogb",  # libc.src.math
    "llogbf",  # libc.src.math
    "llogbl",  # libc.src.math
    "llrint",  # libc.src.math
    "llrintf",  # libc.src.math
    "llrintl",  # libc.src.math
    "llround",  # libc.src.math
    "llroundf",  # libc.src.math
    "llroundl",  # libc.src.math
    "log",  # libc.src.math
    "log10",  # libc.src.math
    "log10f",  # libc.src.math
    "log1p",  # libc.src.math
    "log1pf",  # libc.src.math
    "log2",  # libc.src.math
    "log2f",  # libc.src.math
    "logb",  # libc.src.math
    "logbf",  # libc.src.math
    "logbl",  # libc.src.math
    "logf",  # libc.src.math
    "lrint",  # libc.src.math
    "lrintf",  # libc.src.math
    "lrintl",  # libc.src.math
    "lround",  # libc.src.math
    "lroundf",  # libc.src.math
    "lroundl",  # libc.src.math
    "modf",  # libc.src.math
    "modff",  # libc.src.math
    "modfl",  # libc.src.math
    "nan",  # libc.src.math
    "nanf",  # libc.src.math
    "nanl",  # libc.src.math
    "nearbyint",  # libc.src.math
    "nearbyintf",  # libc.src.math
    "nearbyintl",  # libc.src.math
    "nextafter",  # libc.src.math
    "nextafterf",  # libc.src.math
    "nextafterl",  # libc.src.math
    "nextdown",  # libc.src.math
    "nextdownf",  # libc.src.math
    "nextdownl",  # libc.src.math
    "nexttoward",  # libc.src.math
    "nexttowardf",  # libc.src.math
    "nexttowardl",  # libc.src.math
    "nextup",  # libc.src.math
    "nextupf",  # libc.src.math
    "nextupl",  # libc.src.math
    "pow",  # libc.src.math
    "powf",  # libc.src.math
    "remainder",  # libc.src.math
    "remainderf",  # libc.src.math
    "remainderl",  # libc.src.math
    "remquo",  # libc.src.math
    "remquof",  # libc.src.math
    "remquol",  # libc.src.math
    "rint",  # libc.src.math
    "rintf",  # libc.src.math
    "rintl",  # libc.src.math
    "round",  # libc.src.math
    "roundeven",  # libc.src.math
    "roundevenf",  # libc.src.math
    "roundevenl",  # libc.src.math
    "roundf",  # libc.src.math
    "roundl",  # libc.src.math
    "scalbln",  # libc.src.math
    "scalblnf",  # libc.src.math
    "scalblnl",  # libc.src.math
    "scalbn",  # libc.src.math
    "scalbnf",  # libc.src.math
    "scalbnl",  # libc.src.math
    "setpayload",  # libc.src.math
    "setpayloadf",  # libc.src.math
    "setpayloadl",  # libc.src.math
    "setpayloadsig",  # libc.src.math
    "setpayloadsigf",  # libc.src.math
    "setpayloadsigl",  # libc.src.math
    "sin",  # libc.src.math
    "sincos",  # libc.src.math
    "sincosf",  # libc.src.math
    "sinf",  # libc.src.math
    "sinhf",  # libc.src.math
    "sinpif",  # libc.src.math
    "sqrt",  # libc.src.math
    "sqrtf",  # libc.src.math
    "sqrtl",  # libc.src.math
    "tan",  # libc.src.math
    "tanf",  # libc.src.math
    "tanhf",  # libc.src.math
    "tanpif",  # libc.src.math
    "totalorder",  # libc.src.math
    "totalorderf",  # libc.src.math
    "totalorderl",  # libc.src.math
    "totalordermag",  # libc.src.math
    "totalordermagf",  # libc.src.math
    "totalordermagl",  # libc.src.math
    "trunc",  # libc.src.math
    "truncf",  # libc.src.math
    "truncl",  # libc.src.math
    "ufromfp",  # libc.src.math
    "ufromfpf",  # libc.src.math
    "ufromfpl",  # libc.src.math
    "ufromfpx",  # libc.src.math
    "ufromfpxf",  # libc.src.math
    "ufromfpxl",  # libc.src.math
    "acosf16",  # libc.src.math
    "acoshf16",  # libc.src.math
    "acospif16",  # libc.src.math
    "asinf16",  # libc.src.math
    "asinhf16",  # libc.src.math
    "asinpif16",  # libc.src.math
    "atanf16",  # libc.src.math
    "atan2f16",  # libc.src.math
    "atanhf16",  # libc.src.math
    "atanpif16",  # libc.src.math
    "canonicalizef16",  # libc.src.math
    "ceilf16",  # libc.src.math
    "copysignf16",  # libc.src.math
    "cosf16",  # libc.src.math
    "coshf16",  # libc.src.math
    "cospif16",  # libc.src.math
    "erff16",  # libc.src.math
    "erfcf16",  # libc.src.math
    "exp10f16",  # libc.src.math
    "exp10m1f16",  # libc.src.math
    "exp2f16",  # libc.src.math
    "exp2m1f16",  # libc.src.math
    "expf16",  # libc.src.math
    "expm1f16",  # libc.src.math
    "f16add",  # libc.src.math
    "f16addf",  # libc.src.math
    "f16addl",  # libc.src.math
    "f16div",  # libc.src.math
    "f16divf",  # libc.src.math
    "f16divl",  # libc.src.math
    "f16fma",  # libc.src.math
    "f16fmaf",  # libc.src.math
    "f16fmal",  # libc.src.math
    "f16mul",  # libc.src.math
    "f16mulf",  # libc.src.math
    "f16mull",  # libc.src.math
    "f16sqrt",  # libc.src.math
    "f16sqrtf",  # libc.src.math
    "f16sqrtl",  # libc.src.math
    "f16sub",  # libc.src.math
    "f16subf",  # libc.src.math
    "f16subl",  # libc.src.math
    "fabsf16",  # libc.src.math
    "fdimf16",  # libc.src.math
    "floorf16",  # libc.src.math
    "fmaf16",  # libc.src.math
    "fmaxf16",  # libc.src.math
    "fmaximum_mag_numf16",  # libc.src.math
    "fmaximum_magf16",  # libc.src.math
    "fmaximum_numf16",  # libc.src.math
    "fmaximumf16",  # libc.src.math
    "fminf16",  # libc.src.math
    "fminimum_mag_numf16",  # libc.src.math
    "fminimum_magf16",  # libc.src.math
    "fminimum_numf16",  # libc.src.math
    "fminimumf16",  # libc.src.math
    "fmodf16",  # libc.src.math
    "frexpf16",  # libc.src.math
    "fromfpf16",  # libc.src.math
    "fromfpxf16",  # libc.src.math
    "getpayloadf16",  # libc.src.math
    "hypotf16",  # libc.src.math
    "ilogbf16",  # libc.src.math
    "iscanonicalf16",  # libc.src.math
    "issignalingf16",  # libc.src.math
    "ldexpf16",  # libc.src.math
    "llogbf16",  # libc.src.math
    "llrintf16",  # libc.src.math
    "llroundf16",  # libc.src.math
    "log10f16",  # libc.src.math
    "log10p1f16",  # libc.src.math
    "log2f16",  # libc.src.math
    "log2p1f16",  # libc.src.math
    "logbf16",  # libc.src.math
    "logf16",  # libc.src.math
    "lrintf16",  # libc.src.math
    "lroundf16",  # libc.src.math
    "modff16",  # libc.src.math
    "nanf16",  # libc.src.math
    "nearbyintf16",  # libc.src.math
    "nextafterf16",  # libc.src.math
    "nextdownf16",  # libc.src.math
    "nexttowardf16",  # libc.src.math
    "nextupf16",  # libc.src.math
    "remainderf16",  # libc.src.math
    "remquof16",  # libc.src.math
    "rintf16",  # libc.src.math
    "roundevenf16",  # libc.src.math
    "roundf16",  # libc.src.math
    "rsqrtf",  # libc.src.math
    "rsqrtf16",  # libc.src.math
    "scalblnf16",  # libc.src.math
    "scalbnf16",  # libc.src.math
    "setpayloadf16",  # libc.src.math
    "setpayloadsigf16",  # libc.src.math
    "sinf16",  # libc.src.math
    "sinhf16",  # libc.src.math
    "sinpif16",  # libc.src.math
    "sqrtf16",  # libc.src.math
    "tanf16",  # libc.src.math
    "tanhf16",  # libc.src.math
    "tanpif16",  # libc.src.math
    "totalorderf16",  # libc.src.math
    "totalordermagf16",  # libc.src.math
    "truncf16",  # libc.src.math
    "ufromfpf16",  # libc.src.math
    "ufromfpxf16",  # libc.src.math
    "atanbf16",  # libc.src.math
    "asinbf16",  # libc.src.math
    "bf16add",  # libc.src.math
    "bf16addf",  # libc.src.math
    "bf16addl",  # libc.src.math
    "bf16div",  # libc.src.math
    "bf16divf",  # libc.src.math
    "bf16divl",  # libc.src.math
    "bf16fma",  # libc.src.math
    "bf16fmaf",  # libc.src.math
    "bf16fmal",  # libc.src.math
    "bf16mul",  # libc.src.math
    "bf16mulf",  # libc.src.math
    "bf16mull",  # libc.src.math
    "bf16sub",  # libc.src.math
    "bf16subf",  # libc.src.math
    "bf16subl",  # libc.src.math
    # "canonicalizebf16",  # missing bazel rule  # libc.src.math
    "ceilbf16",  # libc.src.math
    "copysignbf16",  # libc.src.math
    "fabsbf16",  # libc.src.math
    "fdimbf16",  # libc.src.math
    "floorbf16",  # libc.src.math
    "fmaxbf16",  # libc.src.math
    "fmaximumbf16",  # libc.src.math
    "fmaximum_magbf16",  # libc.src.math
    "fmaximum_mag_numbf16",  # libc.src.math
    "fmaximum_numbf16",  # libc.src.math
    "fminbf16",  # libc.src.math
    "fminimumbf16",  # libc.src.math
    "fminimum_magbf16",  # libc.src.math
    "fminimum_mag_numbf16",  # libc.src.math
    "fminimum_numbf16",  # libc.src.math
    "fmodbf16",  # libc.src.math
    "frexpbf16",  # libc.src.math
    "fromfpbf16",  # libc.src.math
    "fromfpxbf16",  # libc.src.math
    # "getpayloadbf16",  # missing bazel rule  # libc.src.math
    "hypotbf16",  # libc.src.math
    "ilogbbf16",  # libc.src.math
    "iscanonicalbf16",  # libc.src.math
    "issignalingbf16",  # libc.src.math
    "ldexpbf16",  # libc.src.math
    "llogbbf16",  # libc.src.math
    "llrintbf16",  # libc.src.math
    "llroundbf16",  # libc.src.math
    "log_bf16",  # libc.src.math
    "logbbf16",  # libc.src.math
    "lrintbf16",  # libc.src.math
    "lroundbf16",  # libc.src.math
    "modfbf16",  # libc.src.math
    "nanbf16",  # libc.src.math
    "nearbyintbf16",  # libc.src.math
    "nextafterbf16",  # libc.src.math
    "nextdownbf16",  # libc.src.math
    "nexttowardbf16",  # libc.src.math
    "nextupbf16",  # libc.src.math
    "remainderbf16",  # libc.src.math
    "remquobf16",  # libc.src.math
    "rintbf16",  # libc.src.math
    "roundbf16",  # libc.src.math
    "roundevenbf16",  # libc.src.math
    "scalblnbf16",  # libc.src.math
    "scalbnbf16",  # libc.src.math
    # "setpayloadbf16",  # missing bazel rule  # libc.src.math
    # "setpayloadsigbf16",  # missing bazel rule  # libc.src.math
    "sqrtbf16",  # libc.src.math
    "truncbf16",  # libc.src.math
    "totalorderbf16",  # libc.src.math
    "totalordermagbf16",  # libc.src.math
    "ufromfpbf16",  # libc.src.math
    "ufromfpxbf16",  # libc.src.math
]
