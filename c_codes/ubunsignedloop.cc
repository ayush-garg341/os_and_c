#include<cassert>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include "hexdump.hh"

int f(int x){
    return x;
}

void loop(unsigned n1, unsigned n2){
    unsigned i;
    for(i=n1; i<=n2; ++i){
        printf("%d\n", i);
    }

}


int main(int argc, char** argv){
    unsigned n1, n2;
    if (argc >= 3) {
        n1 = strtol(argv[1], nullptr, 0);
        n2 = strtol(argv[2], nullptr, 0);
    } else {
        fprintf(stderr, "Usage: %s LO HI\n", argv[0]);
        exit(1);
    }
    loop(n1, n2);

}


// g++ -std=gnu++11 ubunsignedloop.cc
// ./a.out 0xfffffffe (4294967294) 0xffffffff (4294967295)
