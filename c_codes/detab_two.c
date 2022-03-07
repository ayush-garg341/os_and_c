#include<stdio.h>
#define TAB 8

int main(){
    int c, count=0;
    while((c=getchar())!=EOF){
        if(c==9){
            int num_space = TAB - count%TAB;
            for(int j=0; j<num_space; j++){
                /*putchar(32);*/
                putchar(35); // for #
            }
            count = 0;
        }
        else if(c==10){
            count = 0;
            putchar(c);
        }
        else{
            count++;
            putchar(c);
        }
    }
    return 0;
}
