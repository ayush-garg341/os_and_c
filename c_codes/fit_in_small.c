#include<stdio.h>

int main(void){
    unsigned short y = 258;
    unsigned char x = y;
    printf("%d\n", x);
    return 0;
}


/*The computer uses base 256 instead of base 10. Two adjacent bytes can represent numbers between 0 and 255\times256+255 = 65535 = 2^{16}-1255×256+255=65535=2^16 - 1*/

/*Note that all values of a smaller unsigned integer type can fit in any larger unsigned integer type. When a value of a larger unsigned integer type is placed in a smaller unsigned integer object, however, not every value fits; for instance, the unsigned short value 258 doesn’t fit in an unsigned char x. When this occurs, the C++ abstract machine requires that the smaller object’s value equals the least-significant bits of the larger value (so x will equal 2).*/
