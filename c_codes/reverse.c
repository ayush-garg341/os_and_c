#include<stdio.h>
#define MAXLINE 1000

int getLine(char current[], int maxline);
void reverses(char current[], char reverse[], int len);

int main(){
    char current[MAXLINE];
    char reverse[MAXLINE];

    int len;
    while((len=getLine(current, MAXLINE))>0){
        reverses(current, reverse, len);
        printf("%s\n", reverse);
    }
    return 0;
}


int getLine(char current[], int maxline){
    int c, i;
    for(i=0; i<maxline-1 && (c=getchar())!=EOF && c!='\n'; ++i){
        current[i] = c;
    }
    if(c=='\n'){
        current[i] = c;
        i++;
    }
    current[i] = '\0';
    return i;

}


void reverses(char current[], char reverse[], int len){
    int i = 0;
    int end = len-1;
    while(end>=0){
        reverse[i] = current[end];
        end--;
        i++;
    }
    reverse[i] = '\0';
}
