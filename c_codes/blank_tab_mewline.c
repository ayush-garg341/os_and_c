#include<stdio.h>

main(){
    int tab=0, sp=0, nl=0;
    int c;
    while((c=getchar())!=EOF){
        if(c==9){
            ++tab;
        }
        else if(c==10){
            ++nl;
        }
        else if(c==32){
            ++sp;
        }
    }

    printf("tabs=%d, spaces=%d, newlines=%d\n", tab, sp, nl);
}
