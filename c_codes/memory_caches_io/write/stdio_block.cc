/*
 * Writes 512 bytes at a time
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
    size_t block_size = 512;
    parse_arguments(argc, argv, &size, &block_size);

    char *buf = (char *)malloc(sizeof(char) * block_size);
    // The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.
    memset(buf, '6', block_size);
    start_tstamp = tstamp();

    size_t n = 0;
    while (n < size) {
        size_t nw = min(block_size, size - n);
        size_t r = fwrite(buf, 1, nw, f);
        if (r != nw) {
            perror("write");
            exit(1);
        }
        n += nw;
        if (n % PRINT_FREQUENCY == 0) {
            report(n);
        }
    }

    fclose(f);
    report(n, true);

}

/*
 * The stdio cache is a cache in application memory for the buffer cache, which is in kernel memory.
 * size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
 * The function fwrite() writes nitems objects, each size bytes long, to the stream pointed to by stream, obtaining them from the location given by ptr.
 * The function fwrite() returns a value less than nitems only if a write error has occurred.
 */
