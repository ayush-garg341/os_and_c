/*
 * Reads One byte at a time
 * Using system calls
 * Asynchronously - allowing the operating system to use the buffer cache
 * Reading direct from disk is clearly much faster than writing direct to disk
 */

#include "iobench.hh"
bool quiet = false;
double start_tstamp;

int main(int argc, char *argv[]){
    int fd = STDIN_FILENO;
    if (isatty(fd)){
        printf("%d\n", fd);
        printf("%s\n", ttyname(fd));
        fd = open(DATAFILE, O_RDONLY);
        printf("%d\n", fd);
    }
    if (fd < 0){
        perror("open");
        exit(1);
    }

    size_t size = filesize(fd);
    parse_arguments(argc, argv, &size, nullptr);

    char *buf = (char *)malloc(sizeof(char)*1);
    start_tstamp = tstamp();

    size_t n = 0;
    while(n < size){
        // read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.
        // On files that support seeking, the read operation commences at the file offset, and the file offset is incremented by the number of bytes read.
        ssize_t r = read(fd, buf, 1);
        if (r == -1){
            perror("read");
            exit(1);
        }
        else if (r != 1){
            break;
        }
        n += r;
        if (n % PRINT_FREQUENCY == 0){
            report(n);
        }
    }
    close(fd);
    report(n, true);
}
