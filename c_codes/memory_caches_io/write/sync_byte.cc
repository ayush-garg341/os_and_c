/* Writes the file one byte at a time
 * using direct system call (write, open)
 * Synchronously to the disk
 * “Synchronously” means that each write operation completes only when the data has made its way through all layers of caching out to the true disk hardware.
 * We request synchronous writes by opening the file with the O_SYNC option to open.
 */


#define PRINT_FREQUENCY 128
#include "iobench.hh"

bool quiet = false; // used in iobench.hh memory has been assigned
double start_tstamp; // timestamp variable of type double

int main(int argc, char* argv[]){
    int fd = STDOUT_FILENO; // 1
    if (isatty(fd)){
        printf("%s \n", ttyname(fd)); // /dev/pts/0
        fd = open(DATAFILE, O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, 0666);
        // 0666 is permission for the current user read (r) - 4, write (w) - 2, execute (x) - 1
    }
    if (fd < 0){
        perror("open");
        exit(1);
    }

    size_t size = 5120000;
    parse_arguments(argc, argv, &size, nullptr);

    const char* buf = "6";
    start_tstamp = tstamp(); // get current time

    size_t n = 0;
    while (n < size){
        // On success, the number of bytes written is returned.
        // The types size_t and ssize_t are, respectively, unsigned and signed integer data types
        ssize_t r = write(fd, buf, 1); // write one byte (6) into the file
        if (r != 1) {
            perror("write");
            exit(1);
        }
        n += r;
        if (n % PRINT_FREQUENCY == 0) {
            report(n); // create the report in multiple of 128 bytes / chars
        }
    }

    close(fd); // close the file descriptor
    report(n, true); // create the report with newline char
}



// gcc -std=gnu++11  sync_byte.cc
