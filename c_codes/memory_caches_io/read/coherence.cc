#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <unistd.h>
#include <sys/fcntl.h>

#define TESTFILE "consistency-test.txt"

// Overwrite the contents of `TESTFILE` with the string `contents`.
void overwrite(const char* contents) {
    FILE* f = fopen(TESTFILE, "w");
    fputs(contents, f);
    fclose(f);
}

size_t read_using_stdio(char buf[BUFSIZ]) {
    overwrite("CS 61 is terrible!\n");
    // Contents of `TESTFILE` is now "CS 61 is terrible!\n"

        // Open `TESTFILE` and read first 9 bytes
        FILE* f = fopen(TESTFILE, "r");
        size_t nr = fread(buf, 1, 9, f);
        assert(nr == 9);

    overwrite("CS 61 is awesome!!\n");
    // Contents of `TESTFILE` is now "CS 61 is awesome!!\n"

        //fflush(f);
        // Read remaining bytes of already-open `TESTFILE`
        nr += fread(buf + nr, 1, BUFSIZ - nr, f);
        printf("Number of chars read using fread : %lu\n", nr);
        fclose(f);
        return nr;
}

size_t read_using_syscalls(char buf[BUFSIZ]) {
    overwrite("CS 61 is terrible!\n");
    // Contents of `TESTFILE` is now "CS 61 is terrible!\n"

        // Open `TESTFILE` and read first 9 bytes
        int fd = open(TESTFILE, O_RDONLY);
        ssize_t nr = read(fd, buf, 9);
        assert(nr == 9);

    overwrite("CS 61 is awesome!!\n");
    // Contents of `TESTFILE` is now "CS 61 is awesome!!\n"

        // Read remaining bytes of already-open `TESTFILE`
        nr += read(fd, buf + nr, BUFSIZ - nr);
        printf("Number of chars read using read : %lu\n", nr);
        close(fd);
        assert(nr >= 9);
        return nr;
}

int main() {
    printf("buffer size is: %d\n", BUFSIZ);
    char buf[BUFSIZ];

    printf("Reading using stdio:\n");
    size_t n = read_using_stdio(buf);
    printf("%lu\n", n);
    fwrite(buf, 1, n, stdout);

    printf("\nReading using system calls:\n");
    n = read_using_syscalls(buf);
    printf("%lu\n", n);
    fwrite(buf, 1, n, stdout);
}

/*Reads to a coherent cache always read data that is at least as new as the underlying storage. That is, a coherent cache provides the same semantics as direct access to the underlying storage.
 * An incoherent cache does not always provide its read users with the most up-to-date view of underlying storage. In particular, an incoherent cache can return stale data, data that does not represent the latest values written to a set of addresses.
 * The buffer cache is coherent
 * the stdio cache is incoherent
 * You can force the stdio cache to become coherent by adding a fflush(f) call before every read.
 * The stdio application interface does give applications some control over its coherence. Applications can request that stdio not cache a given file with setvbuf(3).
 */
