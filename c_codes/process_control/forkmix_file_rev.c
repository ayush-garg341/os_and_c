#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>

int main(int argc, char* argv[]){
    /* forking before opening the file */
    pid_t p1 = fork();
    FILE *f = fopen(argv[1], "w");
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
 * gcc forkmix_file_rev.c 
 * ./a.out datafile_rev
 * cat datafile_rev | sort | uniq -c
 */
