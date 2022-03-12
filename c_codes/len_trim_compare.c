#include<stdio.h>

int length(char *s){
    char *start = s;
    while(*s){
        s++;
    }
    return s - start;
}

void trim(char *s){
    while(*s != 0){
        s++;
    }
    while(*s == ' ' || *s == 0 || *s == '\n'){
        s--;
    }
    *(s+1) = '\0';
}

int compare(char *s, char *t){
    while(*s - *t == 0 && *s != 0 && *t != 0){
        s++;
        t++;
    }
    return *s - *t;
}


int main(){
    int len = 0;
    char str[100];
    printf("Enter the string: \n");
    fgets(str, 100, stdin); // read from stdin
    puts(str); // print read content out to stdout , also takes into account \n newline char

    len = length(str);
    printf("Length of string is %d\n", len);
    trim(str);
    printf(">%s<\n", str);

    printf("%d\n", compare("appliance", "application"));
    printf("%d\n", compare("application", "appliance"));
    printf("%d\n", compare("apple", "apple"));
    printf("%d\n", compare("apple", "applet"));

    return 0;
}
