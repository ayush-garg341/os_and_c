#include<stdio.h>
#include<sys/types.h>
#include<assert.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t p = fork();
    assert(p >= 0);
    printf("Hello from pid %d\n", getpid());
    return 0;
}



/*
 * If we run the program multiple times though, sometimes we also see the following outputs:
     * Hello from pid 35933
     * user@ubuntu$ Hello from pid 35934
 * In this case a shell prompt gets printed before the child gets to print out its message.
 * This indicates that the shell only waits for the parent to finish before printing out a prompt and therefore can accept new commands.
 * When a shell "waits" for a process (like the parent, in this case) in this way, we call that the process executes in the foreground within the shell.
 */
