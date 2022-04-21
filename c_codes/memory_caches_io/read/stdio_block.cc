/* Reads 512 bytes at a time
 * Using stdio
 * Asynchronously
 */

#include "iobench.hh"
bool quiet = false;
double start_tstamp;

int main(int argc, char *argv[]){
    FILE *f = stdin;
    if(isatty(fileno(f))){
        f = fopen(DATAFILE, "r");
    }
    if(!f){
        perror("open");
        exit(1);
    }

    size_t size = filesize(fileno(f));
    size_t block = 512;
    parse_arguments(argc, argv, &size, &block);

    char *buf = (char *)malloc(sizeof(char)*block);

    start_tstamp = tstamp();
    size_t n = 0;
    while(n < size){
        // The function fread() reads nitems objects, each size bytes long, from the stream pointed to by stream, storing them at the location given by ptr.
        size_t r = fread(buf, 1, block, f);
        if (r == 0 && ferror(f)) {
            perror("read");
            exit(1);
        } else if (r != block) {
            break;
        }

        n += r;
        if (n % PRINT_FREQUENCY == 0){
            report(n);
        }

    }
    fclose(f);
    report(n, true);
}
