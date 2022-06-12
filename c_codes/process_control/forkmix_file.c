/*
 * Now writing to a file instead of std out
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>

int main(int argc, char* argv[]){
    FILE *f = fopen(argv[1], "w");
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

/*
 * gcc forkmix_file.c 
 * ./a.out datafile
 * cat datafile | sort | uniq -c
 */
