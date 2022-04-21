/*
 * Write to a file one byte at a time
 * Direct system calls
 * Asynchronously - allowing the operating system to use its caches.
 */

#include "iobench.hh"
bool quiet = false;
double start_tstamp;

int main(int argc, char* argv[]) {
    int fd = STDOUT_FILENO;
    if (isatty(fd)) {
        fd = open(DATAFILE, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        // no O_SYNC which makes the use of OS cache
    }
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    size_t size = 5120000;
    parse_arguments(argc, argv, &size, nullptr);

    const char* buf = "6";
    start_tstamp = tstamp();

    size_t n = 0;
    while (n < size) {
        ssize_t r = write(fd, buf, 1);
        if (r != 1) {
            perror("write");
            exit(1);
        }
        ++n;
        if (n % PRINT_FREQUENCY == 0) {
            report(n);
        }
    }

    close(fd);
    report(n, true);
}

//Here’s what happens at a high level when this program writes bytes to the file:

//The application makes a write system call asking the operating system to write a byte.

//The operating system performs this write to the buffer cache.

//The operating system immediately returns to the application!
//That is, the application gets control back before the data is written to disk. The data is written to disk eventually, either after some time goes by or because the buffer cache runs out of room, but such later writes can be overlapped with other processing.
