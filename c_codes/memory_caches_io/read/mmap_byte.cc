#include "iobench.hh"
#include <sys/mman.h>
bool quiet = false;
double start_tstamp;

int main(int argc, char* argv[]) {
    int fd = STDIN_FILENO;
    if (isatty(fd)) {
        fd = open(DATAFILE, O_RDONLY);
    }
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    size_t size = filesize(fd);
    parse_arguments(argc, argv, &size, nullptr);

    char* buf = (char*) malloc(1);
    start_tstamp = tstamp();

    char* file_data = (char*) mmap(nullptr, size, PROT_READ, MAP_SHARED, fd, 0);
    if (file_data == (char*) MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    size_t n = 0;
    while (n < size) {
        memcpy(buf, &file_data[n], 1);
        n += 1;
        if (n % PRINT_FREQUENCY == 0) {
            report(n);
        }
    }

    munmap(file_data, size);
    close(fd);
    report(n, true);
}

/* void * mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
 * The mmap() system call causes the pages starting at addr and continuing for at most len bytes to be mapped from the object described by fd, starting at byte offset offset.
 * Upon successful completion, mmap() returns a pointer to the mapped region.  Otherwise, a value of MAP_FAILED is returned and errno is set to indicate the error.
 * int unmap(void *addr, size_t len);
 * The munmap() system call deletes the mappings for the specified address range, causing further references to addresses within the range to generate invalid memory references.
 */
