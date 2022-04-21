/* Reads one byte at a time
 * Using stdio cache
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
    if (!f){
        perror("open");
        exit(1);
    }

    size_t size = filesize(fileno(f));
    parse_arguments(argc, argv, &size, nullptr);

    start_tstamp = tstamp();

    size_t n = 0;
    while (n < size){
        // The fgetc() function obtains the next input character (if present) from the stream pointed at by stream,
        // If successful, these routines return the next requested object from the stream.  Character values are returned as an unsigned char converted to an int. If the stream is at end-of-file or a read error occurs, the routines return EOF.
        int ch = fgetc(f);
        if(ch == EOF && ferror(f)){
            perror("read");
            exit(1);
        }
        else if (ch == EOF){
            break;
        }
        n += 1;
        if (n % PRINT_FREQUENCY == 0){
            report(n);
        }
    }
    fclose(f);
    report(n, true);
}
