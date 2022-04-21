/*
 * Read in reverse
 * One byte at a time
 * Using stdio
 * Asynchronously
 */

#include "iobench.hh"
bool quiet = false;
double start_tstamp;

int main(int argc, char* argv[]) {
    FILE* f = stdin;
    if (isatty(fileno(f))) {
        f = fopen(DATAFILE, "r");
    }
    if (!f) {
        perror("fopen");
        exit(1);
    }

    size_t size = filesize(fileno(f));
    parse_arguments(argc, argv, &size, nullptr);

    start_tstamp = tstamp();

    off_t pos = size;
    size_t n = 0;
    while (n < size) {
        pos -= 1;
        if (fseek(f, pos, SEEK_SET) == -1) {
            perror("fseek");
            exit(1);
        }
        //printf("%ld\n", ftell(f));
        int ch = fgetc(f);
        if (ch == EOF && ferror(f)) {
            perror("fgetc");
            exit(1);
        } else if (ch == EOF) {
            break;
        }
        n += 1;
        if (n % PRINT_FREQUENCY == 0) {
            report(n);
        }
    }

    fclose(f);
    report(n, true);
}

/* int fseek(FILE *stream, long offset, int whence);
 * The fseek() function sets the file position indicator for the stream pointed to by stream.  The new position, measured in bytes, is obtained by adding offset bytes to the position specified by whence.
 * The fseek() functions return the value 0 if successful; otherwise the value -1 is returned and the global variable errno is set to indicate the error.
 */

/*
 * Stdio doesn’t work great for all access patterns. For example, for random one-byte reads distributed through in a large file, 
 * stdio will each time read 4,096 bytes, only one of which is likely to be useful. 
 * This incurs more per-unit costs than simply accessing the bytes directly using one-byte system calls.
 */
