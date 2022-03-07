#include<stdio.h>

int main(){
    int c;
    c = getchar();
    printf("%d\n", c);

    while(c!=EOF){
        putchar(c);
        c = getchar();
        printf("%d\n", c);
    }


    return 0;
}


/*
getchar -> reads the next input character from text stream and return that as a value.
*/

/*
putchar -> prints a character each time it is called. Prints the content of integer variable c as a character.
*/


/*\n -> decimal value is 10.*/
