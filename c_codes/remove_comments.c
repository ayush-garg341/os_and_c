// comments are represented by // or /* */.
#include<stdio.h>

#define IN 1
#define OUT 0

int main(){
    int c, i;
    int inside_str = OUT;
    int inside_comment = OUT;
    int word_count = 0;
    char comment[1];
    comment[0] = '\0';
    while((c=getchar())!=EOF){
        if(c==34 && inside_str==OUT && inside_comment==OUT){
            inside_str = IN;
        }
        if((c==47 || c==42) && inside_str==OUT){
            if(c==47 && comment[0]=='\0'){
                comment[0] = '/';
            }
            else if(comment[0]=='/' && inside_comment==OUT){
                if(c==42){
                    comment[0] = '*';
                }
                else if(c==47){
                    comment[0] = '/';
                }
                inside_comment = IN;
            }
            else if(inside_comment==IN && comment[0]=='*'){
                if(c==47 && word_count==0){
                    inside_comment = OUT;
                    comment[0] = '\0';
                }
            }
        }
        if(inside_comment==IN){
            putchar(35);
            if(c==42){
                word_count = 0;
            }
            if(comment[0] == '*'){
                if(c!=47){
                    word_count += 1;
                }
            }
        }
        else if(c==10){
            putchar(c);
            word_count = 0;
            if(comment[0]!='*'){
                inside_comment = OUT;
                comment[0] = '\0';
            }
        }
        else if(c==34 && inside_str==IN && inside_comment==OUT){
            inside_str = OUT;
            putchar(c);
        }
        else if(inside_comment==OUT){
            putchar(c);
        }
    }
    
    return 0;
}
