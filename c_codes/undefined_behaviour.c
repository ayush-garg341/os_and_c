#include<stdio.h>
#include<limits.h>

int main(void){
    printf("%d\n", INT_MAX);
    printf("%d\n", INT_MAX+1);
    printf("%d\n", INT_MAX+2);
    printf("%d\n", (INT_MAX + 1) < 0);
    return 0;
}
