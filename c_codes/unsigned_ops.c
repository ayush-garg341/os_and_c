#include<stdio.h>

int main(){
    unsigned int a = 0xFFFFFFFFU;
    unsigned int b = 0x00000002U;
    unsigned int c = a + b;
    printf("%d\n", c); // 1
    return 0;
}
