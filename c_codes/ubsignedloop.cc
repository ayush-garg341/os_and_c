#include<cassert>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include "hexdump.hh"

int f(int x){
    return x;
}

void loop(int n1, int n2){
    for(int i=n1; i<=n2; ++i){
        printf("%d\n", i);
    }

}


int main(int argc, char** argv){
    int n1, n2;
    if (argc >= 3) {
        n1 = strtol(argv[1], nullptr, 0);
        n2 = strtol(argv[2], nullptr, 0);
    } else {
        fprintf(stderr, "Usage: %s LO HI\n", argv[0]);
        exit(1);
    }

    printf("Sum of [%d,%d] is %ld\n", n1, n2, loop(n1, n2));

}


// g++ -std=gnu++11 ubsignedloop.cc
// ./a.out 0x7ffffffe 0x7fffffff
