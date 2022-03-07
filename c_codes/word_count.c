#include<stdio.h>

#define IN 1 // inside a word
#define OUT 0 // outside a word

/*count lines, words and characters in an input.*/

main(){
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while((c=getchar())!=EOF){
        ++nc;
        if(c==10){
            ++nl;
        }
        if(c==10 || c==9 || c==32){
            state = OUT;
        }
        else if(state==OUT){
            state = IN;
            ++nw;
        }
    }

    printf("lines=%d, words=%d, chars=%d\n", nl, nw, nc);
}
