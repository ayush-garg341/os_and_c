#include<stdio.h>

struct twelve_bytes{
    int i1;
    int i2;
    char c1;
};


int main(){
    struct twelve_bytes tb;
    printf("%lu\n", sizeof(tb));
    return 0;
}
