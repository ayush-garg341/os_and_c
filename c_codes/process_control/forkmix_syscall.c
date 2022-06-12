/*
 * Using system call write
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>

int main(){
    pid_t p1 = fork();
    assert(p1 >= 0);
    const char* test;
    if (p1==0){
        test = "BABY\n";
    }
    else{
        test = "MAMA\n";
    }
    for(int i = 0; i!=100000; ++i){
        ssize_t s = write(STDOUT_FILENO, test, strlen(test));
        assert(s == (ssize_t) strlen(test));
    }
}


/*
 * Running the program prints out interleaving lines of BABY and mama to the screen. 
 * Sometimes the interleaving is perfect (we see exactly one BABY followed by exactly one mama, and so on),
 * sometimes we see consecutive printouts of BABY or mama.
 * It does seem that every line is either BABY or mama.
 * Verify using 
 *  gcc forkmix_syscall.c 
 *  ./a.out | sort | uniq -c
 */
