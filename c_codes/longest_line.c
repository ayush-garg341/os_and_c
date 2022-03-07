#include<stdio.h>

#define MAXLINE 1000

int getLine(char current[], int maxline);
void copy(char current[], char longest[]);

int main(){
    int len;
    int max;
    
    char current[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len=getLine(current, MAXLINE))>0){
        if(len > max){
            max = len;
            copy(current, longest);
        }
    }
    printf("Longest string is ----  %d\n", max);
    
    /*int i=0;*/
    /*while(longest[i]!='\0'){*/
        /*printf("%c", longest[i]);*/
        /*i++;*/
    /*}*/
    
    // we can use %s format specifier since our char array is null terminated i.e. \0 at the end.
    
    printf("%s\n", longest);
    return 0;
}


int getLine(char current[], int maxline){
    int c, i;
    for(i=0; i < maxline-1 && (c=getchar())!=EOF && c!='\n'; ++i){
        current[i]=c;
    }
    if(c=='\n'){
        current[i] = c;
        ++i;
    }
    current[i] = '\0';
    return i;
}

void copy(char src[], char dest[]){
    int i = 0;
    // while((dest[i]=src[i])!='\0')
    while(src[i]!='\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
