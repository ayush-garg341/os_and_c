/*
 * Same program as sync_byte.cc but rather than writig one byte, writing a block_size of 512 bytes at a time.
 */


#include "iobench.hh"
bool quiet = false;
double start_tstamp;


int main(int argc, char* argv[]){
    int fd = STDOUT_FILENO;
    if (isatty(fd)){
        printf("%d\n", fd);
        printf("%s\n", ttyname(fd));
        fd = open(DATAFILE, O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, 0666);
        printf("%d\n", fd);
    }
    if (fd < 0){
        perror("open");
        exit(1);
    }

    size_t size = 5120000;
    size_t block_size = 512;
    parse_arguments(argc, argv, &size, &block_size);

    char* b = (char *)malloc(sizeof(char)*block_size);
    // The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.
    memset(b, '6', block_size);

    start_tstamp = tstamp();
    size_t n = 0;

    while (n < size){
        size_t nw = min(block_size, size - n);
        ssize_t r = write(fd, b, nw);
        if (size_t(r)!=nw){
            perror("write");
            exit(1);
        }
        n += nw;
        if (n % PRINT_FREQUENCY == 0){
            report(n);
        }
    }

    close(fd);
    report(n, true);

}
