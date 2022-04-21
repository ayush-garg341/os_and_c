/*
 * Writes one byte at a time
 * Using stdio library function calls
 * Asynchronously
 * Uses two distinct layers of software cache: a stdio cache, managed by the stdio library inside the program, uses caching to reduce the cost of system calls; and the buffer cache, managed by the operating system inside the kernel, uses caching to reduce the cost of disk access.
 * This program is incredibly and surprisingly faster than sync_byte.cc and byte.cc
 */

#include "iobench.hh"
bool quiet = false;
double start_tstamp;

int main(int argc, char* argv[]){
    FILE *f = stdout;
    if (isatty(fileno(f))){
        printf("%d\n", fileno(f));
        printf("%s\n", ttyname(fileno(f)));
        f = fopen(DATAFILE, "w");
        printf("%d\n", fileno(f));
    }
    if (!f){
        perror("fopen");
        exit(1);
    }

    size_t size = 5120000;
    parse_arguments(argc, argv, &size, nullptr);

    const char* buf = "6";
    start_tstamp = tstamp();

    size_t n = 0;
    while (n < size) {
        // The fputc() function writes the character c (converted to an ``unsigned char'') to the output stream pointed to by stream.
        int ch = fputc(buf[0], f);
        if (ch == EOF) {
            perror("write");
            exit(1);
        }
        ++n;
        if (n % PRINT_FREQUENCY == 0) {
            report(n);
        }
    }

    fclose(f);
    report(n, true);

}

/*
 * The stdio cache is a cache in application memory for the buffer cache, which is in kernel memory.
 */
