#include<stdio.h>

#define TOTAL_CHARS 128 // 0-127

main(){
    int chars[TOTAL_CHARS];
    int i, c;
    for(i=0; i<TOTAL_CHARS; i++){
        chars[i]=0;
    }

    while((c=getchar())!=EOF){
        chars[c] += 1;
    }

    for(i=0; i<TOTAL_CHARS; i++){
        if(chars[i]!=0){
            putchar(i);
            int j;
            for(j=0; j < chars[i]; j++){
                putchar(42);
            }
            printf("\n");
        }
    }
}
