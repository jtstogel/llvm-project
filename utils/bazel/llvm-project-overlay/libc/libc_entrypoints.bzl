CMAKE_LIBC_ENTRYPOINTS = [
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
    "dladdr",  # libc.src.dlfcn
    "dlclose",  # libc.src.dlfcn
    "dlerror",  # libc.src.dlfcn
    "dlopen",  # libc.src.dlfcn
    "dlsym",  # libc.src.dlfcn
    "errno",  # libc.src.errno
    "creat",  # libc.src.fcntl
    "fcntl",  # libc.src.fcntl
    "open",  # libc.src.fcntl
    "openat",  # libc.src.fcntl
    "poll",  # libc.src.poll
    "getcpu",  # libc.src.sched
    "sched_get_priority_max",  # libc.src.sched
    "sched_get_priority_min",  # libc.src.sched
    "sched_getaffinity",  # libc.src.sched
    "sched_getcpu",  # libc.src.sched
    "sched_getparam",  # libc.src.sched
    "sched_getscheduler",  # libc.src.sched
    "sched_rr_get_interval",  # libc.src.sched
    "sched_setaffinity",  # libc.src.sched
    "sched_setparam",  # libc.src.sched
    "sched_setscheduler",  # libc.src.sched
    "sched_yield",  # libc.src.sched
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
    "strcoll",  # libc.src.string
    "strcpy",  # libc.src.string
    "strcspn",  # libc.src.string
    "strdup",  # libc.src.string
    "strerror",  # libc.src.string
    "strerror_r",  # libc.src.string
    "strlcat",  # libc.src.string
    "strlcpy",  # libc.src.string
    "strlen",  # libc.src.string
    "strncat",  # libc.src.string
    "strncmp",  # libc.src.string
    "strncpy",  # libc.src.string
    "strndup",  # libc.src.string
    "strnlen",  # libc.src.string
    "strnlen_s",  # libc.src.string
    "strpbrk",  # libc.src.string
    "strrchr",  # libc.src.string
    "strsep",  # libc.src.string
    "strsignal",  # libc.src.string
    "strspn",  # libc.src.string
    "strstr",  # libc.src.string
    "strtok",  # libc.src.string
    "strtok_r",  # libc.src.string
    "strxfrm",  # libc.src.string
    "bcmp",  # libc.src.strings
    "bcopy",  # libc.src.strings
    "bzero",  # libc.src.strings
    "ffs",  # libc.src.strings
    "ffsl",  # libc.src.strings
    "ffsll",  # libc.src.strings
    "index",  # libc.src.strings
    "rindex",  # libc.src.strings
    "strcasecmp",  # libc.src.strings
    "strncasecmp",  # libc.src.strings
    "imaxabs",  # libc.src.inttypes
    "imaxdiv",  # libc.src.inttypes
    "strtoimax",  # libc.src.inttypes
    "strtoumax",  # libc.src.inttypes
    # "stdc_bit_ceil_uc",  # libc.src.stdbit
    # "stdc_bit_ceil_ui",  # libc.src.stdbit
    # "stdc_bit_ceil_ul",  # libc.src.stdbit
    # "stdc_bit_ceil_ull",  # libc.src.stdbit
    # "stdc_bit_ceil_us",  # libc.src.stdbit
    # "stdc_bit_floor_uc",  # libc.src.stdbit
    # "stdc_bit_floor_ui",  # libc.src.stdbit
    # "stdc_bit_floor_ul",  # libc.src.stdbit
    # "stdc_bit_floor_ull",  # libc.src.stdbit
    # "stdc_bit_floor_us",  # libc.src.stdbit
    # "stdc_bit_width_uc",  # libc.src.stdbit
    # "stdc_bit_width_ui",  # libc.src.stdbit
    # "stdc_bit_width_ul",  # libc.src.stdbit
    # "stdc_bit_width_ull",  # libc.src.stdbit
    # "stdc_bit_width_us",  # libc.src.stdbit
    # "stdc_count_ones_uc",  # libc.src.stdbit
    # "stdc_count_ones_ui",  # libc.src.stdbit
    # "stdc_count_ones_ul",  # libc.src.stdbit
    # "stdc_count_ones_ull",  # libc.src.stdbit
    # "stdc_count_ones_us",  # libc.src.stdbit
    # "stdc_count_zeros_uc",  # libc.src.stdbit
    # "stdc_count_zeros_ui",  # libc.src.stdbit
    # "stdc_count_zeros_ul",  # libc.src.stdbit
    # "stdc_count_zeros_ull",  # libc.src.stdbit
    # "stdc_count_zeros_us",  # libc.src.stdbit
    # "stdc_first_leading_one_uc",  # libc.src.stdbit
    # "stdc_first_leading_one_ui",  # libc.src.stdbit
    # "stdc_first_leading_one_ul",  # libc.src.stdbit
    # "stdc_first_leading_one_ull",  # libc.src.stdbit
    # "stdc_first_leading_one_us",  # libc.src.stdbit
    # "stdc_first_leading_zero_uc",  # libc.src.stdbit
    # "stdc_first_leading_zero_ui",  # libc.src.stdbit
    # "stdc_first_leading_zero_ul",  # libc.src.stdbit
    # "stdc_first_leading_zero_ull",  # libc.src.stdbit
    # "stdc_first_leading_zero_us",  # libc.src.stdbit
    # "stdc_first_trailing_one_uc",  # libc.src.stdbit
    # "stdc_first_trailing_one_ui",  # libc.src.stdbit
    # "stdc_first_trailing_one_ul",  # libc.src.stdbit
    # "stdc_first_trailing_one_ull",  # libc.src.stdbit
    # "stdc_first_trailing_one_us",  # libc.src.stdbit
    # "stdc_first_trailing_zero_uc",  # libc.src.stdbit
    # "stdc_first_trailing_zero_ui",  # libc.src.stdbit
    # "stdc_first_trailing_zero_ul",  # libc.src.stdbit
    # "stdc_first_trailing_zero_ull",  # libc.src.stdbit
    # "stdc_first_trailing_zero_us",  # libc.src.stdbit
    # "stdc_has_single_bit_uc",  # libc.src.stdbit
    # "stdc_has_single_bit_ui",  # libc.src.stdbit
    # "stdc_has_single_bit_ul",  # libc.src.stdbit
    # "stdc_has_single_bit_ull",  # libc.src.stdbit
    # "stdc_has_single_bit_us",  # libc.src.stdbit
    # "stdc_leading_ones_uc",  # libc.src.stdbit
    # "stdc_leading_ones_ui",  # libc.src.stdbit
    # "stdc_leading_ones_ul",  # libc.src.stdbit
    # "stdc_leading_ones_ull",  # libc.src.stdbit
    # "stdc_leading_ones_us",  # libc.src.stdbit
    # "stdc_leading_zeros_uc",  # libc.src.stdbit
    # "stdc_leading_zeros_ui",  # libc.src.stdbit
    # "stdc_leading_zeros_ul",  # libc.src.stdbit
    # "stdc_leading_zeros_ull",  # libc.src.stdbit
    # "stdc_leading_zeros_us",  # libc.src.stdbit
    # "stdc_trailing_ones_uc",  # libc.src.stdbit
    # "stdc_trailing_ones_ui",  # libc.src.stdbit
    # "stdc_trailing_ones_ul",  # libc.src.stdbit
    # "stdc_trailing_ones_ull",  # libc.src.stdbit
    # "stdc_trailing_ones_us",  # libc.src.stdbit
    # "stdc_trailing_zeros_uc",  # libc.src.stdbit
    # "stdc_trailing_zeros_ui",  # libc.src.stdbit
    # "stdc_trailing_zeros_ul",  # libc.src.stdbit
    # "stdc_trailing_zeros_ull",  # libc.src.stdbit
    # "stdc_trailing_zeros_us",  # libc.src.stdbit
    "a64l",  # libc.src.stdlib
    "abs",  # libc.src.stdlib
    "atof",  # libc.src.stdlib
    "atoi",  # libc.src.stdlib
    "atol",  # libc.src.stdlib
    "atoll",  # libc.src.stdlib
    "bsearch",  # libc.src.stdlib
    "div",  # libc.src.stdlib
    "l64a",  # libc.src.stdlib
    "labs",  # libc.src.stdlib
    "ldiv",  # libc.src.stdlib
    "llabs",  # libc.src.stdlib
    "lldiv",  # libc.src.stdlib
    "memalignment",  # libc.src.stdlib
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
    "aligned_alloc",  # libc.src.stdlib
    "calloc",  # libc.src.stdlib
    "free",  # libc.src.stdlib
    "malloc",  # libc.src.stdlib
    "posix_memalign",  # libc.src.stdlib
    "realloc",  # libc.src.stdlib
    "fprintf",  # libc.src.stdio
    "fscanf",  # libc.src.stdio
    "vfscanf",  # libc.src.stdio
    "printf",  # libc.src.stdio
    "remove",  # libc.src.stdio
    "rename",  # libc.src.stdio
    "scanf",  # libc.src.stdio
    "vscanf",  # libc.src.stdio
    "snprintf",  # libc.src.stdio
    "sprintf",  # libc.src.stdio
    "asprintf",  # libc.src.stdio
    "sscanf",  # libc.src.stdio
    "stderr",  # libc.src.stdio
    "stdin",  # libc.src.stdio
    "stdout",  # libc.src.stdio
    "vsscanf",  # libc.src.stdio
    "vfprintf",  # libc.src.stdio
    "vprintf",  # libc.src.stdio
    "vsnprintf",  # libc.src.stdio
    "vsprintf",  # libc.src.stdio
    "vasprintf",  # libc.src.stdio
    "epoll_create",  # libc.src.sys.epoll
    "epoll_create1",  # libc.src.sys.epoll
    "epoll_ctl",  # libc.src.sys.epoll
    "epoll_pwait",  # libc.src.sys.epoll
    "epoll_wait",  # libc.src.sys.epoll
    "ioctl",  # libc.src.sys.ioctl
    "ftok",  # libc.src.sys.ipc
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
    "getrandom",  # libc.src.sys.random
    "getrlimit",  # libc.src.sys.resource
    "setrlimit",  # libc.src.sys.resource
    "semget",  # libc.src.sys.sem
    "semctl",  # libc.src.sys.sem
    "semop",  # libc.src.sys.sem
    "sendfile",  # libc.src.sys.sendfile
    "accept",  # libc.src.sys.socket
    "accept4",  # libc.src.sys.socket
    "bind",  # libc.src.sys.socket
    "connect",  # libc.src.sys.socket
    "getsockopt",  # libc.src.sys.socket
    "listen",  # libc.src.sys.socket
    "recv",  # libc.src.sys.socket
    "recvfrom",  # libc.src.sys.socket
    "send",  # libc.src.sys.socket
    "sendto",  # libc.src.sys.socket
    "setsockopt",  # libc.src.sys.socket
    "shutdown",  # libc.src.sys.socket
    "socket",  # libc.src.sys.socket
    "socketpair",  # libc.src.sys.socket
    "recvmsg",  # libc.src.sys.socket
    "sendmsg",  # libc.src.sys.socket
    "chmod",  # libc.src.sys.stat
    "fchmod",  # libc.src.sys.stat
    "fchmodat",  # libc.src.sys.stat
    "fstat",  # libc.src.sys.stat
    "lstat",  # libc.src.sys.stat
    "mkdir",  # libc.src.sys.stat
    "mkdirat",  # libc.src.sys.stat
    "stat",  # libc.src.sys.stat
    "utimensat",  # libc.src.sys.stat
    "fstatvfs",  # libc.src.sys.statvfs
    "statvfs",  # libc.src.sys.statvfs
    "utimes",  # libc.src.sys.time
    "uname",  # libc.src.sys.utsname
    "wait",  # libc.src.sys.wait
    "wait4",  # libc.src.sys.wait
    "waitpid",  # libc.src.sys.wait
    "prctl",  # libc.src.sys.prctl
    "personality",  # libc.src.sys.personality
    "getauxval",  # libc.src.sys.auxv
    # "cfgetispeed",  # libc.src.termios
    # "cfgetospeed",  # libc.src.termios
    # "cfsetispeed",  # libc.src.termios
    # "cfsetospeed",  # libc.src.termios
    # "tcdrain",  # libc.src.termios
    # "tcflow",  # libc.src.termios
    # "tcflush",  # libc.src.termios
    # "tcgetattr",  # libc.src.termios
    # "tcgetsid",  # libc.src.termios
    # "tcsendbreak",  # libc.src.termios
    # "tcsetattr",  # libc.src.termios
    "access",  # libc.src.unistd
    "chdir",  # libc.src.unistd
    "chown",  # libc.src.unistd
    "close",  # libc.src.unistd
    "dup",  # libc.src.unistd
    "dup2",  # libc.src.unistd
    "dup3",  # libc.src.unistd
    "execve",  # libc.src.unistd
    "faccessat",  # libc.src.unistd
    "fchdir",  # libc.src.unistd
    "fchown",  # libc.src.unistd
    "fpathconf",  # libc.src.unistd
    "fsync",  # libc.src.unistd
    "ftruncate",  # libc.src.unistd
    "getcwd",  # libc.src.unistd
    "getentropy",  # libc.src.unistd
    "geteuid",  # libc.src.unistd
    "gethostname",  # libc.src.unistd
    "getpagesize",  # libc.src.unistd
    "getpid",  # libc.src.unistd
    "getppid",  # libc.src.unistd
    "getsid",  # libc.src.unistd
    "gettid",  # libc.src.unistd
    "getgid",  # libc.src.unistd
    "getuid",  # libc.src.unistd
    "isatty",  # libc.src.unistd
    "link",  # libc.src.unistd
    "linkat",  # libc.src.unistd
    "lseek",  # libc.src.unistd
    "pathconf",  # libc.src.unistd
    "pipe",  # libc.src.unistd
    "pipe2",  # libc.src.unistd
    "pread",  # libc.src.unistd
    "pwrite",  # libc.src.unistd
    "read",  # libc.src.unistd
    "readlink",  # libc.src.unistd
    "readlinkat",  # libc.src.unistd
    "rmdir",  # libc.src.unistd
    "setsid",  # libc.src.unistd
    "symlink",  # libc.src.unistd
    "symlinkat",  # libc.src.unistd
    "sysconf",  # libc.src.unistd
    "truncate",  # libc.src.unistd
    "unlink",  # libc.src.unistd
    "unlinkat",  # libc.src.unistd
    "write",  # libc.src.unistd
    "btowc",  # libc.src.wchar
    "wcslen",  # libc.src.wchar
    "wcsnlen",  # libc.src.wchar
    "wctob",  # libc.src.wchar
    "wmemmove",  # libc.src.wchar
    "wmemset",  # libc.src.wchar
    "wcschr",  # libc.src.wchar
    "wcsncmp",  # libc.src.wchar
    "wcsxfrm",  # libc.src.wchar
    "wcscmp",  # libc.src.wchar
    "wcscoll",  # libc.src.wchar
    "wcspbrk",  # libc.src.wchar
    "wcsrchr",  # libc.src.wchar
    "wcsspn",  # libc.src.wchar
    "wcscspn",  # libc.src.wchar
    "wcsdup",  # libc.src.wchar
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
    "wcstod",  # libc.src.wchar
    "wcstof",  # libc.src.wchar
    "wcstok",  # libc.src.wchar
    "wcstol",  # libc.src.wchar
    "wcstold",  # libc.src.wchar
    "wcstoll",  # libc.src.wchar
    "wcstoul",  # libc.src.wchar
    "wcstoull",  # libc.src.wchar
    "iswalpha",  # libc.src.wctype
    "iswgraph",  # libc.src.wctype
    "iswcntrl",  # libc.src.wctype
    "iswdigit",  # libc.src.wctype
    "iswupper",  # libc.src.wctype
    "iswalnum",  # libc.src.wctype
    "iswlower",  # libc.src.wctype
    "iswspace",  # libc.src.wctype
    "iswblank",  # libc.src.wctype
    "iswxdigit",  # libc.src.wctype
    "iswpunct",  # libc.src.wctype
    "iswprint",  # libc.src.wctype
    "iswctype",  # libc.src.wctype
    "wctype",  # libc.src.wctype
    "writev",  # libc.src.sys.uio
    "readv",  # libc.src.sys.uio
    "setitimer",  # libc.src.sys.time
    "getitimer",  # libc.src.sys.time
    "isalnum_l",  # libc.src.ctype
    "isalpha_l",  # libc.src.ctype
    "isblank_l",  # libc.src.ctype
    "iscntrl_l",  # libc.src.ctype
    "isdigit_l",  # libc.src.ctype
    "isgraph_l",  # libc.src.ctype
    "islower_l",  # libc.src.ctype
    "isprint_l",  # libc.src.ctype
    "ispunct_l",  # libc.src.ctype
    "isspace_l",  # libc.src.ctype
    "isupper_l",  # libc.src.ctype
    "isxdigit_l",  # libc.src.ctype
    "tolower_l",  # libc.src.ctype
    "toupper_l",  # libc.src.ctype
    "strtod_l",  # libc.src.stdlib
    "strtof_l",  # libc.src.stdlib
    "strtol_l",  # libc.src.stdlib
    "strtold_l",  # libc.src.stdlib
    "strtoll_l",  # libc.src.stdlib
    "strtoul_l",  # libc.src.stdlib
    "strtoull_l",  # libc.src.stdlib
    "strcoll_l",  # libc.src.string
    "strxfrm_l",  # libc.src.string
    "strcasecmp_l",  # libc.src.strings
    "strncasecmp_l",  # libc.src.strings
    "__assert_fail",  # libc.src.assert
    "__stack_chk_fail",  # libc.src.compiler
    "closedir",  # libc.src.dirent
    "dirfd",  # libc.src.dirent
    "opendir",  # libc.src.dirent
    "readdir",  # libc.src.dirent
    "htonl",  # libc.src.arpa.inet
    "htons",  # libc.src.arpa.inet
    "inet_addr",  # libc.src.arpa.inet
    "inet_aton",  # libc.src.arpa.inet
    "ntohl",  # libc.src.arpa.inet
    "ntohs",  # libc.src.arpa.inet
    "pthread_atfork",  # libc.src.pthread
    "pthread_attr_destroy",  # libc.src.pthread
    "pthread_attr_getdetachstate",  # libc.src.pthread
    "pthread_attr_getguardsize",  # libc.src.pthread
    "pthread_attr_getstack",  # libc.src.pthread
    "pthread_attr_getstacksize",  # libc.src.pthread
    "pthread_attr_init",  # libc.src.pthread
    "pthread_attr_setdetachstate",  # libc.src.pthread
    "pthread_attr_setguardsize",  # libc.src.pthread
    "pthread_attr_setstack",  # libc.src.pthread
    "pthread_attr_setstacksize",  # libc.src.pthread
    "pthread_condattr_destroy",  # libc.src.pthread
    "pthread_condattr_getclock",  # libc.src.pthread
    "pthread_condattr_getpshared",  # libc.src.pthread
    "pthread_condattr_init",  # libc.src.pthread
    "pthread_condattr_setclock",  # libc.src.pthread
    "pthread_condattr_setpshared",  # libc.src.pthread
    "pthread_cond_broadcast",  # libc.src.pthread
    "pthread_cond_clockwait",  # libc.src.pthread
    "pthread_cond_destroy",  # libc.src.pthread
    "pthread_cond_init",  # libc.src.pthread
    "pthread_cond_signal",  # libc.src.pthread
    "pthread_cond_timedwait",  # libc.src.pthread
    "pthread_cond_wait",  # libc.src.pthread
    "pthread_create",  # libc.src.pthread
    "pthread_detach",  # libc.src.pthread
    "pthread_equal",  # libc.src.pthread
    "pthread_exit",  # libc.src.pthread
    "pthread_getname_np",  # libc.src.pthread
    "pthread_getspecific",  # libc.src.pthread
    "pthread_join",  # libc.src.pthread
    "pthread_key_create",  # libc.src.pthread
    "pthread_key_delete",  # libc.src.pthread
    "pthread_barrier_init",  # libc.src.pthread
    "pthread_barrier_wait",  # libc.src.pthread
    "pthread_barrier_destroy",  # libc.src.pthread
    "pthread_mutex_destroy",  # libc.src.pthread
    "pthread_mutex_init",  # libc.src.pthread
    "pthread_mutex_lock",  # libc.src.pthread
    "pthread_mutex_trylock",  # libc.src.pthread
    "pthread_mutex_unlock",  # libc.src.pthread
    "pthread_mutexattr_destroy",  # libc.src.pthread
    "pthread_mutexattr_getpshared",  # libc.src.pthread
    "pthread_mutexattr_getrobust",  # libc.src.pthread
    "pthread_mutexattr_gettype",  # libc.src.pthread
    "pthread_mutexattr_init",  # libc.src.pthread
    "pthread_mutexattr_setpshared",  # libc.src.pthread
    "pthread_mutexattr_setrobust",  # libc.src.pthread
    "pthread_mutexattr_settype",  # libc.src.pthread
    "pthread_once",  # libc.src.pthread
    "pthread_rwlock_clockrdlock",  # libc.src.pthread
    "pthread_rwlock_clockwrlock",  # libc.src.pthread
    "pthread_rwlock_destroy",  # libc.src.pthread
    "pthread_rwlock_init",  # libc.src.pthread
    "pthread_rwlock_rdlock",  # libc.src.pthread
    "pthread_rwlock_timedrdlock",  # libc.src.pthread
    "pthread_rwlock_timedwrlock",  # libc.src.pthread
    "pthread_rwlock_tryrdlock",  # libc.src.pthread
    "pthread_rwlock_trywrlock",  # libc.src.pthread
    "pthread_rwlock_unlock",  # libc.src.pthread
    "pthread_rwlock_wrlock",  # libc.src.pthread
    "pthread_rwlockattr_destroy",  # libc.src.pthread
    "pthread_rwlockattr_getkind_np",  # libc.src.pthread
    "pthread_rwlockattr_getpshared",  # libc.src.pthread
    "pthread_rwlockattr_init",  # libc.src.pthread
    "pthread_rwlockattr_setkind_np",  # libc.src.pthread
    "pthread_rwlockattr_setpshared",  # libc.src.pthread
    "pthread_spin_destroy",  # libc.src.pthread
    "pthread_spin_init",  # libc.src.pthread
    "pthread_spin_lock",  # libc.src.pthread
    "pthread_spin_trylock",  # libc.src.pthread
    "pthread_spin_unlock",  # libc.src.pthread
    "pthread_self",  # libc.src.pthread
    "pthread_setname_np",  # libc.src.pthread
    "pthread_setspecific",  # libc.src.pthread
    "__sched_getcpucount",  # libc.src.sched
    "__sched_setcpuzero",  # libc.src.sched
    "__sched_setcpuset",  # libc.src.sched
    "__sched_getcpuisset",  # libc.src.sched
    "longjmp",  # libc.src.setjmp
    "setjmp",  # libc.src.setjmp
    "siglongjmp",  # libc.src.setjmp
    "sigsetjmp",  # libc.src.setjmp
    "getcontext",  # libc.src.ucontext
    "setcontext",  # libc.src.ucontext
    "clearerr",  # libc.src.stdio
    "clearerr_unlocked",  # libc.src.stdio
    "fclose",  # libc.src.stdio
    "fdopen",  # libc.src.stdio
    "feof",  # libc.src.stdio
    "feof_unlocked",  # libc.src.stdio
    "ferror",  # libc.src.stdio
    "ferror_unlocked",  # libc.src.stdio
    "fflush",  # libc.src.stdio
    "fgetc",  # libc.src.stdio
    "fgetc_unlocked",  # libc.src.stdio
    "fgets",  # libc.src.stdio
    "fileno",  # libc.src.stdio
    "flockfile",  # libc.src.stdio
    "fopen",  # libc.src.stdio
    "fopencookie",  # libc.src.stdio
    "fputc",  # libc.src.stdio
    "fputs",  # libc.src.stdio
    "fread",  # libc.src.stdio
    "fread_unlocked",  # libc.src.stdio
    "fseek",  # libc.src.stdio
    "fseeko",  # libc.src.stdio
    "ftell",  # libc.src.stdio
    "ftello",  # libc.src.stdio
    "funlockfile",  # libc.src.stdio
    "fwrite",  # libc.src.stdio
    "fwrite_unlocked",  # libc.src.stdio
    "getc",  # libc.src.stdio
    "getc_unlocked",  # libc.src.stdio
    "getchar",  # libc.src.stdio
    "getchar_unlocked",  # libc.src.stdio
    "perror",  # libc.src.stdio
    "putc",  # libc.src.stdio
    "putchar",  # libc.src.stdio
    "puts",  # libc.src.stdio
    "rewind",  # libc.src.stdio
    "setbuf",  # libc.src.stdio
    "setvbuf",  # libc.src.stdio
    "stderr",  # libc.src.stdio
    "stdin",  # libc.src.stdio
    "stdout",  # libc.src.stdio
    "ungetc",  # libc.src.stdio
    "_Exit",  # libc.src.stdlib
    "abort",  # libc.src.stdlib
    "at_quick_exit",  # libc.src.stdlib
    "atexit",  # libc.src.stdlib
    "exit",  # libc.src.stdlib
    "getenv",  # libc.src.stdlib
    "mbstowcs",  # libc.src.stdlib
    "mbtowc",  # libc.src.stdlib
    "quick_exit",  # libc.src.stdlib
    "wcstombs",  # libc.src.stdlib
    "wctomb",  # libc.src.stdlib
    "kill",  # libc.src.signal
    "raise",  # libc.src.signal
    "sigaction",  # libc.src.signal
    "sigaddset",  # libc.src.signal
    "sigaltstack",  # libc.src.signal
    "sigdelset",  # libc.src.signal
    "sigemptyset",  # libc.src.signal
    "sigfillset",  # libc.src.signal
    "signal",  # libc.src.signal
    "sigprocmask",  # libc.src.signal
    "posix_spawn",  # libc.src.spawn
    "posix_spawn_file_actions_addclose",  # libc.src.spawn
    "posix_spawn_file_actions_adddup2",  # libc.src.spawn
    "posix_spawn_file_actions_addopen",  # libc.src.spawn
    "posix_spawn_file_actions_destroy",  # libc.src.spawn
    "posix_spawn_file_actions_init",  # libc.src.spawn
    "hcreate",  # libc.src.search
    "hcreate_r",  # libc.src.search
    "hdestroy",  # libc.src.search
    "hdestroy_r",  # libc.src.search
    "hsearch",  # libc.src.search
    "hsearch_r",  # libc.src.search
    "insque",  # libc.src.search
    "lfind",  # libc.src.search
    "lsearch",  # libc.src.search
    "remque",  # libc.src.search
    "tdelete",  # libc.src.search
    "tdestroy",  # libc.src.search
    "tfind",  # libc.src.search
    "tsearch",  # libc.src.search
    "twalk",  # libc.src.search
    "twalk_r",  # libc.src.search
    "call_once",  # libc.src.threads
    "cnd_broadcast",  # libc.src.threads
    "cnd_destroy",  # libc.src.threads
    "cnd_init",  # libc.src.threads
    "cnd_signal",  # libc.src.threads
    "cnd_wait",  # libc.src.threads
    "mtx_destroy",  # libc.src.threads
    "mtx_init",  # libc.src.threads
    "mtx_lock",  # libc.src.threads
    "mtx_unlock",  # libc.src.threads
    "thrd_create",  # libc.src.threads
    "thrd_current",  # libc.src.threads
    "thrd_detach",  # libc.src.threads
    "thrd_equal",  # libc.src.threads
    "thrd_exit",  # libc.src.threads
    "thrd_join",  # libc.src.threads
    "tss_create",  # libc.src.threads
    "tss_delete",  # libc.src.threads
    "tss_get",  # libc.src.threads
    "tss_set",  # libc.src.threads
    "asctime",  # libc.src.time
    "asctime_r",  # libc.src.time
    "ctime",  # libc.src.time
    "ctime_r",  # libc.src.time
    "clock",  # libc.src.time
    "clock_gettime",  # libc.src.time
    "clock_settime",  # libc.src.time
    "difftime",  # libc.src.time
    "gettimeofday",  # libc.src.time
    "gmtime",  # libc.src.time
    "gmtime_r",  # libc.src.time
    "localtime",  # libc.src.time
    "localtime_r",  # libc.src.time
    "mktime",  # libc.src.time
    "nanosleep",  # libc.src.time
    "strftime",  # libc.src.time
    "strftime_l",  # libc.src.time
    "time",  # libc.src.time
    "timespec_get",  # libc.src.time
    "localeconv",  # libc.src.locale
    "duplocale",  # libc.src.locale
    "freelocale",  # libc.src.locale
    "localeconv",  # libc.src.locale
    "newlocale",  # libc.src.locale
    "setlocale",  # libc.src.locale
    "uselocale",  # libc.src.locale
    "__llvm_libc_syscall",  # libc.src.unistd
    "_exit",  # libc.src.unistd
    "environ",  # libc.src.unistd
    "execv",  # libc.src.unistd
    "fork",  # libc.src.unistd
    "getopt",  # libc.src.unistd
    "optarg",  # libc.src.unistd
    "opterr",  # libc.src.unistd
    "optind",  # libc.src.unistd
    "optopt",  # libc.src.unistd
    "swab",  # libc.src.unistd
    "select",  # libc.src.sys.select
    "mblen",  # libc.src.wchar
    "mbrlen",  # libc.src.wchar
    "mbsinit",  # libc.src.wchar
    "mbrtowc",  # libc.src.wchar
    "mbsrtowcs",  # libc.src.wchar
    "mbsnrtowcs",  # libc.src.wchar
    "wcrtomb",  # libc.src.wchar
    "wcsrtombs",  # libc.src.wchar
    "wcsnrtombs",  # libc.src.wchar
    "catopen",  # libc.src.nl_types
    "catclose",  # libc.src.nl_types
    "catgets",  # libc.src.nl_types
]

CMAKE_LIBM_ENTRYPOINTS = [
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
    "fadd",  # libc.src.math
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
    "canonicalizebf16",  # libc.src.math
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
    "getpayloadbf16",  # libc.src.math
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
    "setpayloadbf16",  # libc.src.math
    "setpayloadsigbf16",  # libc.src.math
    "sqrtbf16",  # libc.src.math
    "truncbf16",  # libc.src.math
    "totalorderbf16",  # libc.src.math
    "totalordermagbf16",  # libc.src.math
    "ufromfpbf16",  # libc.src.math
    "ufromfpxbf16",  # libc.src.math
]

ENTRYPOINTS_WITH_EXISTING_BAZEL_RULES = [
    "abs",
    "access",
    "acos",
    "acosf",
    "acosf16",
    "acoshf",
    "acoshf16",
    "acospif",
    "acospif16",
    "asin",
    "asinbf16",
    "asinf",
    "asinf16",
    "asinhf",
    "asinhf16",
    "asinpi",
    "asinpif",
    "asinpif16",
    "asprintf",
    "atan",
    "atan2",
    "atan2f",
    "atan2f128",
    "atan2f16",
    "atanbf16",
    "atanf",
    "atanf16",
    "atanhf",
    "atanhf16",
    "atanpif16",
    "atof",
    "atoi",
    "atol",
    "atoll",
    "bcmp",
    "bcopy",
    "bf16add",
    "bf16addf",
    "bf16addf128",
    "bf16addl",
    "bf16div",
    "bf16divf",
    "bf16divf128",
    "bf16divl",
    "bf16fma",
    "bf16fmaf",
    "bf16fmaf128",
    "bf16fmal",
    "bf16mul",
    "bf16mulf",
    "bf16mulf128",
    "bf16mull",
    "bf16sub",
    "bf16subf",
    "bf16subf128",
    "bf16subl",
    "bfloat16",
    "bsearch",
    "btowc",
    "build_mode",
    "bzero",
    "canonicalize",
    "canonicalizef",
    "canonicalizef128",
    "canonicalizef16",
    "canonicalizel",
    "cbrt",
    "cbrtbf16",
    "cbrtf",
    "ceil",
    "ceilbf16",
    "ceilf",
    "ceilf128",
    "ceilf16",
    "ceill",
    "chdir",
    "cimag",
    "cimagf",
    "cimagf128",
    "cimagf16",
    "cimagl",
    "close",
    "conj",
    "conjf",
    "conjf128",
    "conjf16",
    "conjl",
    "copy_llvm_libc_static_headers",
    "copy_modular_format_header",
    "copysign",
    "copysignbf16",
    "copysignf",
    "copysignf128",
    "copysignf16",
    "copysignl",
    "cos",
    "cosf",
    "cosf16",
    "coshf",
    "coshf16",
    "cospif",
    "cospif16",
    "cproj",
    "cprojf",
    "cprojf128",
    "cprojf16",
    "cprojl",
    "creal",
    "crealf",
    "crealf128",
    "crealf16",
    "creall",
    "creat",
    "daddf128",
    "daddl",
    "ddivf128",
    "ddivl",
    "dfmaf128",
    "dfmal",
    "div",
    "dmulf128",
    "dmull",
    "dsqrtf128",
    "dsqrtl",
    "dsubf128",
    "dsubl",
    "dup",
    "dup2",
    "dup3",
    "entrypoint_declarations",
    "environ",
    "epoll_create",
    "epoll_create1",
    "epoll_ctl",
    "epoll_pwait",
    "epoll_pwait2",
    "epoll_wait",
    "erfcf16",
    "erff",
    "erff16",
    "errno",
    "exp",
    "exp10",
    "exp10f",
    "exp10f16",
    "exp10m1f",
    "exp10m1f16",
    "exp2",
    "exp2f",
    "exp2f16",
    "exp2m1f",
    "exp2m1f16",
    "expf",
    "expf16",
    "expm1",
    "expm1f",
    "expm1f16",
    "f16add",
    "f16addf",
    "f16addf128",
    "f16addl",
    "f16div",
    "f16divf",
    "f16divf128",
    "f16divl",
    "f16fma",
    "f16fmaf",
    "f16fmaf128",
    "f16fmal",
    "f16mul",
    "f16mulf",
    "f16mulf128",
    "f16mull",
    "f16sqrt",
    "f16sqrtf",
    "f16sqrtf128",
    "f16sqrtl",
    "f16sub",
    "f16subf",
    "f16subf128",
    "f16subl",
    "fabs",
    "fabsbf16",
    "fabsf",
    "fabsf128",
    "fabsf16",
    "fabsl",
    "fadd",
    "faddf128",
    "faddl",
    "fchdir",
    "fcntl",
    "fdim",
    "fdimbf16",
    "fdimf",
    "fdimf128",
    "fdimf16",
    "fdiml",
    "fdiv",
    "fdivf128",
    "fdivl",
    "feclearexcept",
    "fedisableexcept",
    "feenableexcept",
    "fegetenv",
    "fegetexcept",
    "fegetexceptflag",
    "fegetround",
    "feholdexcept",
    "feraiseexcept",
    "fesetenv",
    "fesetexcept",
    "fesetexceptflag",
    "fesetround",
    "fetestexcept",
    "fetestexceptflag",
    "feupdateenv",
    "ffma",
    "ffmaf128",
    "ffmal",
    "floor",
    "floorbf16",
    "floorf",
    "floorf128",
    "floorf16",
    "floorl",
    "fma",
    "fmabf16",
    "fmaf",
    "fmaf16",
    "fmax",
    "fmaxbf16",
    "fmaxf",
    "fmaxf128",
    "fmaxf16",
    "fmaximum",
    "fmaximum_mag",
    "fmaximum_mag_num",
    "fmaximum_mag_numbf16",
    "fmaximum_mag_numf",
    "fmaximum_mag_numf128",
    "fmaximum_mag_numf16",
    "fmaximum_mag_numl",
    "fmaximum_magbf16",
    "fmaximum_magf",
    "fmaximum_magf128",
    "fmaximum_magf16",
    "fmaximum_magl",
    "fmaximum_num",
    "fmaximum_numbf16",
    "fmaximum_numf",
    "fmaximum_numf128",
    "fmaximum_numf16",
    "fmaximum_numl",
    "fmaximumbf16",
    "fmaximumf",
    "fmaximumf128",
    "fmaximumf16",
    "fmaximuml",
    "fmaxl",
    "fmin",
    "fminbf16",
    "fminf",
    "fminf128",
    "fminf16",
    "fminimum",
    "fminimum_mag",
    "fminimum_mag_num",
    "fminimum_mag_numbf16",
    "fminimum_mag_numf",
    "fminimum_mag_numf128",
    "fminimum_mag_numf16",
    "fminimum_mag_numl",
    "fminimum_magbf16",
    "fminimum_magf",
    "fminimum_magf128",
    "fminimum_magf16",
    "fminimum_magl",
    "fminimum_num",
    "fminimum_numbf16",
    "fminimum_numf",
    "fminimum_numf128",
    "fminimum_numf16",
    "fminimum_numl",
    "fminimumbf16",
    "fminimumf",
    "fminimumf128",
    "fminimumf16",
    "fminimuml",
    "fminl",
    "fmod",
    "fmodbf16",
    "fmodf",
    "fmodf128",
    "fmodf16",
    "fmodl",
    "fmul",
    "fmulf128",
    "fmull",
    "fprintf",
    "frexp",
    "frexpbf16",
    "frexpf",
    "frexpf128",
    "frexpf16",
    "frexpl",
    "fromfp",
    "fromfpbf16",
    "fromfpf",
    "fromfpf128",
    "fromfpf16",
    "fromfpl",
    "fromfpx",
    "fromfpxbf16",
    "fromfpxf",
    "fromfpxf128",
    "fromfpxf16",
    "fromfpxl",
    "fscanf",
    "fsqrt",
    "fsqrtf128",
    "fsqrtl",
    "fsub",
    "fsubf128",
    "fsubl",
    "fsync",
    "ftruncate",
    "full_build_enable",
    "func_aligned_alloc",
    "func_free",
    "func_malloc",
    "func_realloc",
    "geteuid",
    "getpagesize",
    "getpayload",
    "getpayloadf",
    "getpayloadf128",
    "getpayloadf16",
    "getpayloadl",
    "getppid",
    "getrlimit",
    "getsockopt",
    "getuid",
    "hdr_elf_proxy_h",
    "hdr_errno_macros",
    "hdr_fcntl_macros",
    "hdr_fcntl_overlay",
    "hdr_fenv_macros",
    "hdr_float_macros",
    "hdr_limits_macros",
    "hdr_math_macros",
    "hdr_signal_macros",
    "hdr_stdint_proxy",
    "hdr_stdio_macros",
    "hdr_stdio_overlay",
    "hdr_stdlib_macros",
    "hdr_stdlib_overlay",
    "hdr_sys_auxv_macros",
    "hdr_sys_epoll_macros",
    "hdr_sys_mman_macros",
    "hdr_sys_socket_macros",
    "hdr_sys_stat_macros",
    "hdr_time_macros",
    "hdr_uchar_overlay",
    "hdr_unistd_macros",
    "hdr_unistd_overlay",
    "hdr_wchar_macros",
    "hdr_wchar_overlay",
    "hdr_wctype_overlay",
    "hdrgen",
    "hypot",
    "hypotbf16",
    "hypotf",
    "hypotf16",
    "ilogb",
    "ilogbbf16",
    "ilogbf",
    "ilogbf128",
    "ilogbf16",
    "ilogbl",
    "imaxabs",
    "imaxdiv",
    "include_arpa_inet_h",
    "include_assert_h",
    "include_complex_h",
    "include_ctype_h",
    "include_dirent_h",
    "include_dlfcn_h",
    "include_elf_h",
    "include_endian_h",
    "include_errno_h",
    "include_fcntl_h",
    "include_features_h",
    "include_fenv_h",
    "include_float_h",
    "include_inttypes_h",
    "include_limits_h",
    "include_link_h",
    "include_locale_h",
    "include_malloc_h",
    "include_math_h",
    "include_netinet_in_h",
    "include_nl_types_h",
    "include_poll_h",
    "include_pthread_h",
    "include_sched_h",
    "include_search_h",
    "include_setjmp_h",
    "include_signal_h",
    "include_spawn_h",
    "include_stdbit_h",
    "include_stdckdint_h",
    "include_stdfix_h",
    "include_stdint_h",
    "include_stdio_h",
    "include_stdlib_h",
    "include_string_h",
    "include_strings_h",
    "include_sys_auxv_h",
    "include_sys_epoll_h",
    "include_sys_ioctl_h",
    "include_sys_ipc_h",
    "include_sys_mman_h",
    "include_sys_prctl_h",
    "include_sys_random_h",
    "include_sys_resource_h",
    "include_sys_select_h",
    "include_sys_socket_h",
    "include_sys_stat_h",
    "include_sys_statvfs_h",
    "include_sys_syscall_h",
    "include_sys_time_h",
    "include_sys_types_h",
    "include_sys_utsname_h",
    "include_sys_wait_h",
    "include_sysexits_h",
    "include_termios_h",
    "include_threads_h",
    "include_time_h",
    "include_uchar_h",
    "include_unistd_h",
    "include_wchar_h",
    "include_wctype_h",
    "index",
    "isalnum",
    "isalpha",
    "isascii",
    "isatty",
    "isblank",
    "iscanonical",
    "iscanonicalbf16",
    "iscanonicalf",
    "iscanonicalf128",
    "iscanonicalf16",
    "iscanonicall",
    "iscntrl",
    "isdigit",
    "isgraph",
    "islower",
    "isnan",
    "isnanf",
    "isnanl",
    "isprint",
    "ispunct",
    "issignaling",
    "issignalingbf16",
    "issignalingf",
    "issignalingf128",
    "issignalingf16",
    "issignalingl",
    "isspace",
    "isupper",
    "isxdigit",
    "labs",
    "ldexp",
    "ldexpbf16",
    "ldexpf",
    "ldexpf128",
    "ldexpf16",
    "ldexpl",
    "ldiv",
    "link",
    "linkat",
    "llabs",
    "lldiv",
    "llogb",
    "llogbbf16",
    "llogbf",
    "llogbf128",
    "llogbf16",
    "llogbl",
    "llrint",
    "llrintbf16",
    "llrintf",
    "llrintf128",
    "llrintf16",
    "llrintl",
    "llround",
    "llroundbf16",
    "llroundf",
    "llroundf128",
    "llroundf16",
    "llroundl",
    "llvm_libc_macros_complex_macros",
    "llvm_libc_macros_fcntl_macros",
    "llvm_libc_macros_float16_macros",
    "llvm_libc_macros_float_macros",
    "llvm_libc_macros_limits_macros",
    "llvm_libc_macros_math_macros",
    "llvm_libc_macros_stdfix_macros",
    "llvm_libc_macros_stdint_macros",
    "llvm_libc_macros_sys_socket_macros",
    "llvm_libc_macros_sys_stat_macros",
    "llvm_libc_types_cfloat128",
    "llvm_libc_types_cfloat16",
    "llvm_libc_types_char8_t",
    "llvm_libc_types_float128",
    "llvm_libc_types_size_t",
    "llvm_libc_types_struct_cmsghdr",
    "log",
    "log10",
    "log10f",
    "log10f16",
    "log10p1f16",
    "log1p",
    "log1pf",
    "log2",
    "log2f",
    "log2f16",
    "log2p1f16",
    "log_bf16",
    "logb",
    "logbbf16",
    "logbf",
    "logbf128",
    "logbf16",
    "logbl",
    "logf",
    "logf16",
    "lrint",
    "lrintbf16",
    "lrintf",
    "lrintf128",
    "lrintf16",
    "lrintl",
    "lround",
    "lroundbf16",
    "lroundf",
    "lroundf128",
    "lroundf16",
    "lroundl",
    "lseek",
    "madvise",
    "memccpy",
    "memchr",
    "memcmp",
    "memcpy",
    "memmem",
    "memmove",
    "mempcpy",
    "memrchr",
    "memset",
    "memset_explicit",
    "mincore",
    "mkdir",
    "mkdirat",
    "mlock",
    "mlock2",
    "mlockall",
    "mmap",
    "modf",
    "modfbf16",
    "modff",
    "modff128",
    "modff16",
    "modfl",
    "modular_format",
    "modular_format_enable",
    "mpc",
    "mpc_disable",
    "mpc_external",
    "mpc_system",
    "mpfr",
    "mpfr_disable",
    "mpfr_external",
    "mpfr_system",
    "mprotect",
    "mremap",
    "msync",
    "munlock",
    "munlockall",
    "munmap",
    "nan",
    "nanbf16",
    "nanf",
    "nanf128",
    "nanf16",
    "nanl",
    "nearbyint",
    "nearbyintbf16",
    "nearbyintf",
    "nearbyintf128",
    "nearbyintf16",
    "nearbyintl",
    "nextafter",
    "nextafterbf16",
    "nextafterf",
    "nextafterf128",
    "nextafterf16",
    "nextafterl",
    "nextdown",
    "nextdownbf16",
    "nextdownf",
    "nextdownf128",
    "nextdownf16",
    "nextdownl",
    "nexttoward",
    "nexttowardbf16",
    "nexttowardf",
    "nexttowardf16",
    "nexttowardl",
    "nextup",
    "nextupbf16",
    "nextupf",
    "nextupf128",
    "nextupf16",
    "nextupl",
    "open",
    "openat",
    "pipe",
    "pkey_alloc",
    "pkey_common",
    "pkey_free",
    "pkey_get",
    "pkey_mprotect",
    "pkey_set",
    "posix_madvise",
    "pow",
    "powf",
    "pread",
    "printf",
    "printf_config",
    "printf_converter",
    "printf_core_structs",
    "printf_error_mapper",
    "printf_main",
    "printf_parser",
    "printf_writer",
    "public_headers",
    "public_headers_deps",
    "pwrite",
    "qsort",
    "qsort_r",
    "qsort_util",
    "rand",
    "rand_util",
    "read",
    "readlink",
    "readlinkat",
    "recv",
    "recvfrom",
    "recvmsg",
    "remainder",
    "remainderbf16",
    "remainderf",
    "remainderf128",
    "remainderf16",
    "remainderl",
    "remap_file_pages",
    "remove",
    "remquo",
    "remquobf16",
    "remquof",
    "remquof128",
    "remquof16",
    "remquol",
    "rename",
    "rindex",
    "rint",
    "rintbf16",
    "rintf",
    "rintf128",
    "rintf16",
    "rintl",
    "rmdir",
    "round",
    "roundbf16",
    "roundeven",
    "roundevenbf16",
    "roundevenf",
    "roundevenf128",
    "roundevenf16",
    "roundevenl",
    "roundf",
    "roundf128",
    "roundf16",
    "roundl",
    "rsqrtf",
    "rsqrtf16",
    "scalbln",
    "scalblnbf16",
    "scalblnf",
    "scalblnf128",
    "scalblnf16",
    "scalblnl",
    "scalbn",
    "scalbnbf16",
    "scalbnf",
    "scalbnf128",
    "scalbnf16",
    "scalbnl",
    "scanf",
    "scanf_config",
    "scanf_converter",
    "scanf_core_structs",
    "scanf_main",
    "scanf_parser",
    "scanf_reader",
    "scanf_string_reader",
    "send",
    "sendmsg",
    "sendto",
    "setpayload",
    "setpayloadf",
    "setpayloadf128",
    "setpayloadf16",
    "setpayloadl",
    "setpayloadsig",
    "setpayloadsigf",
    "setpayloadsigf128",
    "setpayloadsigf16",
    "setpayloadsigl",
    "setrlimit",
    "shm_common",
    "shm_open",
    "shm_unlink",
    "sin",
    "sincos",
    "sincosf",
    "sinf",
    "sinf16",
    "sinhf",
    "sinhf16",
    "sinpif",
    "sinpif16",
    "snprintf",
    "socket",
    "socketpair",
    "sprintf",
    "sqrt",
    "sqrtbf16",
    "sqrtf",
    "sqrtf128",
    "sqrtf16",
    "sqrtl",
    "srand",
    "sscanf",
    "stdc_bit_ceil_uc",
    "stdc_bit_ceil_ui",
    "stdc_bit_ceil_ul",
    "stdc_bit_ceil_ull",
    "stdc_bit_ceil_us",
    "stdc_bit_floor_uc",
    "stdc_bit_floor_ui",
    "stdc_bit_floor_ul",
    "stdc_bit_floor_ull",
    "stdc_bit_floor_us",
    "stdc_bit_width_uc",
    "stdc_bit_width_ui",
    "stdc_bit_width_ul",
    "stdc_bit_width_ull",
    "stdc_bit_width_us",
    "stdc_count_ones_uc",
    "stdc_count_ones_ui",
    "stdc_count_ones_ul",
    "stdc_count_ones_ull",
    "stdc_count_ones_us",
    "stdc_count_zeros_uc",
    "stdc_count_zeros_ui",
    "stdc_count_zeros_ul",
    "stdc_count_zeros_ull",
    "stdc_count_zeros_us",
    "stdc_first_leading_one_uc",
    "stdc_first_leading_one_ui",
    "stdc_first_leading_one_ul",
    "stdc_first_leading_one_ull",
    "stdc_first_leading_one_us",
    "stdc_first_leading_zero_uc",
    "stdc_first_leading_zero_ui",
    "stdc_first_leading_zero_ul",
    "stdc_first_leading_zero_ull",
    "stdc_first_leading_zero_us",
    "stdc_first_trailing_one_uc",
    "stdc_first_trailing_one_ui",
    "stdc_first_trailing_one_ul",
    "stdc_first_trailing_one_ull",
    "stdc_first_trailing_one_us",
    "stdc_first_trailing_zero_uc",
    "stdc_first_trailing_zero_ui",
    "stdc_first_trailing_zero_ul",
    "stdc_first_trailing_zero_ull",
    "stdc_first_trailing_zero_us",
    "stdc_has_single_bit_uc",
    "stdc_has_single_bit_ui",
    "stdc_has_single_bit_ul",
    "stdc_has_single_bit_ull",
    "stdc_has_single_bit_us",
    "stdc_leading_ones_uc",
    "stdc_leading_ones_ui",
    "stdc_leading_ones_ul",
    "stdc_leading_ones_ull",
    "stdc_leading_ones_us",
    "stdc_leading_zeros_uc",
    "stdc_leading_zeros_ui",
    "stdc_leading_zeros_ul",
    "stdc_leading_zeros_ull",
    "stdc_leading_zeros_us",
    "stdc_trailing_ones_uc",
    "stdc_trailing_ones_ui",
    "stdc_trailing_ones_ul",
    "stdc_trailing_ones_ull",
    "stdc_trailing_ones_us",
    "stdc_trailing_zeros_uc",
    "stdc_trailing_zeros_ui",
    "stdc_trailing_zeros_ul",
    "stdc_trailing_zeros_ull",
    "stdc_trailing_zeros_us",
    "stdin",
    "stdout",
    "stpcpy",
    "stpncpy",
    "str_from_util",
    "strcasecmp",
    "strcasestr",
    "strcat",
    "strchr",
    "strchrnul",
    "strcmp",
    "strcpy",
    "strcspn",
    "strfromd",
    "strfromf",
    "strfroml",
    "string_memory_utils",
    "string_utils",
    "strlcat",
    "strlcpy",
    "strlen",
    "strncasecmp",
    "strncat",
    "strncmp",
    "strncpy",
    "strnlen",
    "strpbrk",
    "strrchr",
    "strsep",
    "strspn",
    "strstr",
    "strtod",
    "strtof",
    "strtoimax",
    "strtok",
    "strtok_r",
    "strtol",
    "strtold",
    "strtoll",
    "strtoul",
    "strtoull",
    "strtoumax",
    "swab",
    "symlink",
    "symlinkat",
    "sysconf",
    "tan",
    "tanf",
    "tanf16",
    "tanhf",
    "tanhf16",
    "tanpif",
    "tanpif16",
    "toascii",
    "tolower",
    "totalorder",
    "totalorderbf16",
    "totalorderf",
    "totalorderf128",
    "totalorderf16",
    "totalorderl",
    "totalordermag",
    "totalordermagbf16",
    "totalordermagf",
    "totalordermagf128",
    "totalordermagf16",
    "totalordermagl",
    "toupper",
    "trunc",
    "truncate",
    "truncbf16",
    "truncf",
    "truncf128",
    "truncf16",
    "truncl",
    "types_FILE",
    "types_char32_t",
    "types_char8_t",
    "types_clock_t",
    "types_clockid_t",
    "types_div_t",
    "types_fenv_t",
    "types_fexcept_t",
    "types_ldiv_t",
    "types_lldiv_t",
    "types_mode_t",
    "types_off_t",
    "types_pid_t",
    "types_sigset_t",
    "types_size_t",
    "types_socklen_t",
    "types_ssize_t",
    "types_struct_cmsghdr",
    "types_struct_epoll_event",
    "types_struct_f_owner_ex",
    "types_struct_flock",
    "types_struct_flock64",
    "types_struct_msghdr",
    "types_struct_rlimit",
    "types_struct_sockaddr",
    "types_struct_timespec",
    "types_struct_timeval",
    "types_time_t",
    "types_uid_t",
    "types_wchar_t",
    "types_wctype_t",
    "types_wint_t",
    "ufromfp",
    "ufromfpbf16",
    "ufromfpf",
    "ufromfpf128",
    "ufromfpf16",
    "ufromfpl",
    "ufromfpx",
    "ufromfpxbf16",
    "ufromfpxf",
    "ufromfpxf128",
    "ufromfpxf16",
    "ufromfpxl",
    "unlink",
    "unlinkat",
    "vasprintf",
    "vasprintf_internal",
    "vfprintf",
    "vfprintf_internal",
    "vfscanf",
    "vfscanf_internal",
    "vprintf",
    "vscanf",
    "vsnprintf",
    "vsprintf",
    "vsscanf",
    "wchar_utils",
    "wcpcpy",
    "wcpncpy",
    "wcscat",
    "wcschr",
    "wcscmp",
    "wcscpy",
    "wcscspn",
    "wcslcat",
    "wcslcpy",
    "wcslen",
    "wcsncat",
    "wcsncmp",
    "wcsncpy",
    "wcspbrk",
    "wcsrchr",
    "wcsspn",
    "wcsstr",
    "wctob",
    "wmemchr",
    "wmemcmp",
    "wmemcpy",
    "wmemmove",
    "wmempcpy",
    "wmemset",
    "write",
]

LIBC_ENTRYPOINTS = list(sorted(set(CMAKE_LIBC_ENTRYPOINTS) & set(ENTRYPOINTS_WITH_EXISTING_BAZEL_RULES)))

LIBM_ENTRYPOINTS = list(sorted(set(CMAKE_LIBM_ENTRYPOINTS) & set(ENTRYPOINTS_WITH_EXISTING_BAZEL_RULES)))
