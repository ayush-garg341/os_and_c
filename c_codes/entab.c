#include<stdio.h>

#define TABSTOP 8

int main(){
    int c;
    int pos, spaces;
    pos = spaces = 0;
    while((c=getchar())!=EOF){
        pos++;
        if(c==32){
            spaces++;
            if(pos%TABSTOP==0){
                /*Handling the case when only spaces are present after a char or just spaces.*/
                putchar(9);
                spaces = 0;
            }
        }
        else if(c==10){
            /*handling the case of new line.*/
            pos = 0;
            spaces = 0;
            putchar(c);
        }
        else{
            /*Handling the case when after space there is a char. */
            while(spaces>0){
                putchar(32);
                spaces--;
            }
            putchar(c);
        }
    }
    return 0;
}
