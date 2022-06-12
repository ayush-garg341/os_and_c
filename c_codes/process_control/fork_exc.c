#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>

int main(){
    printf("Hello from initial pid %d\n", getpid());
    /*fflush(stdout);*/
    pid_t p1 = fork();
    assert(p1 >= 0);

    pid_t p2 = fork();
    assert(p2 >= 0);

    printf("Hello from final pid %d\n", getpid());
    /*fflush(stdout);*/
}

/*
 * How many lines of output would you expect to see when you run the program?
 *  5 lines 
 *  The first printf() prints one line, only in the parent, and then the second printf() will run four times, one in each process (parent + 2 children + 1 grand child).
 * How many lines of output would you expect if we run the program and redirect its output to a file (using ./a.out > fork_exc) ?
 *  We actually see 8 lines of output in the file. What’s going on??
 *  Note that we are using printf(), which is a stdio library function and not a system call.
 *  So there is caching going on.
 *  After the first printf() is called, the output only gets written to a buffer but not the actual file descriptor.
 *  The buffer is in user-space memory and will get duplicated after fork() is invoked.
 *  herefore every child process has two lines of output in its stdio buffer by the end of its execution, and a total of 8 lines get written to the file in the end.
 *  Recall that this buffering only occurs when stdout is being redirected to a file.
 *  When operating on the console, stdio flushes the buffer after each new line character, making it behaving like a system call.
 *  That’s why we don’t see this effect when running the program in the console without I/O redirection.
 *  We can avoid this behavior by calling flush(stdout) after the first printf() call.
 */
