#ifndef IOBENCH_HH
#define IOBENCH_HH
#define _GNU_SOURCE 1
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <clocale>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <climits>
#include <ctime>
extern bool quiet; // external variable define in other .c file, no memory has been assigned yet, extern make sure of that
// if it's been bool quiet -> garbage value is placed at the memory location but the variable is ready to be used.
// Extern to be used in header files only
extern double start_tstamp;

// Inline Function are those function whose definitions are small and be substituted at the place where its function call is happened.


// tstamp()
//    Return current timestamp as a double.
inline double tstamp() {
    struct timespec tv;
    clock_gettime(CLOCK_REALTIME, &tv);
    return tv.tv_sec + tv.tv_nsec * 1.0e-9;
}

// report(n, final)
//    Print a report to stderr of # bytes printed, elapsed time, and rate.
inline void report(size_t n, bool final = false) {
    static bool locale_set = false;
    if (!quiet || final) {
        if (!locale_set) {
            setlocale(LC_NUMERIC, "");
            locale_set = true;
        }
        double elapsed = tstamp() - start_tstamp;
        fprintf(stderr, "\r%'14zd bytes   %8.3f sec   %'16.0f bytes/sec%s",
                n, elapsed, n / elapsed, final ? "\n" : "   ");
    }
}

// filesize(fd)
//    Return the size of the open file with file descriptor `fd`.
inline ssize_t filesize(int fd) {
    struct stat s;
    int r = fstat(fd, &s);
    if (r >= 0 && S_ISREG(s.st_mode) && s.st_size <= SSIZE_MAX) {
        return s.st_size;
    } else {
        return -1;
    }
}

// parse_arguments(argc, argv, size, block_size)
//    Parse command line arguments. Any `-s SIZE` argument is stored in
//    `*size`; any `-b BLOCKSIZE` argument is stored in `*block_size` (if
//    `block_size != nullptr`); and if `-q` is given, then the `report()`
//    output is quieted.
inline void parse_arguments(int argc, char* argv[],
                            size_t* size, size_t* block_size) {
    const char* argspec = block_size ? "b:n:s:q" : "n:s:q";
    int ch;
    while ((ch = getopt(argc, argv, argspec)) != -1) {
        size_t* ptr = nullptr, val;
        if (ch == 'b') {
            ptr = block_size;
        } else if (ch == 'n' || ch == 's') {
            ptr = size;
        } else if (ch == 'q') {
            quiet = true;
        }
        if (ptr && sscanf(optarg, "%zi", &val) == 1) {
            *ptr = val;
        }
    }
}


// if not define in .c file then take these values

#ifndef PRINT_FREQUENCY
#define PRINT_FREQUENCY 4096
#endif

#ifndef DATAFILE
#define DATAFILE "data"
#endif

template <typename T>
inline T min(T x, T y) {
    return x < y ? x : y;
}

#endif
