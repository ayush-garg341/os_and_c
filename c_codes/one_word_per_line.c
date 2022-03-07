#include<stdio.h>

#define IN 1
#define OUT 0

main(){
    int c, state;
    state=OUT;
    while((c=getchar())!=EOF){
        if(c!=9 && c!=32 && c!=10){
            state=IN;
            putchar(c);
        }
        else if(state==IN){
            state=OUT;
            putchar(10);
        }
    }
}
