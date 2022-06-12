/*
 * Using stdio library call fputs
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>

int main(){
    FILE *f = stdout;
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
        int s = fputs(test, f);
        if (s==EOF){
            perror("write");
        }
    }
}

