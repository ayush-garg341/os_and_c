#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    srandom(getpid());
    for(int i=0; i < 16; i++){
        long int r = random();
        printf("%ld\n", r);
    }
}
