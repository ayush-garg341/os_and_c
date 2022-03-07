/*Proper caution needs to be taken since in input every tab must be replaced by spaces in output. And hence output string size will get increased*/
#include<stdio.h>

#define TAB 8
#define MAXLINE 1000

int getLine(char line[], int maxline);
int detab(char line[], char detabLine[]);

int main(){
    int len;
    char line[MAXLINE];
    char detabLine[MAXLINE];
    while((len=getLine(line, MAXLINE))>0){
        int detabLen = detab(line, detabLine);
        printf("%s\n", detabLine);
    }
    return 0;
}


int getLine(char line[], int maxline){
    int c,i;
    for(i=0; i<maxline-1 && (c=getchar())!=EOF && c!='\n'; ++i){
        line[i] = c;
    }
    if(c=='\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}


int detab(char line[], char detabLine[]){
    int i = 0;
    int j = 0;
    int count = 0;
    while(line[i]!='\0'){
        if(line[i]=='\t'){
            int num_space = TAB - count%TAB;
            for(int k=0; k<num_space; k++){
                detabLine[j] = ' ';
                j++;
            }
            i++;
            count = 0;
        }
        else{
            detabLine[j] = line[i];
            i++;
            j++;
            count++;
        }
    }
    detabLine[j++] = '\0';
    return j;
}
