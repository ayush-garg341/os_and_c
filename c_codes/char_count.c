#include<stdio.h>

main(){
    double nc;
    int ch;
    printf("EOF: %d\n", EOF);
    for(nc=0; (ch=getchar())!=EOF; ++nc)
        /*;*/
        printf("%c", ch);
    printf("%.0f\n", nc);
}

/*
 
; -> The isolated semi-colon , called a null statement is there to satisfy a requirement. Since the body of for loop can not be empty.

%.0f -> suppresses printing of decimal point and fractional part which is zero. 

\n -> counts as a valid char and decmial value is 10.

EOF -> Ctrl+D or Ctrl+z
*/
