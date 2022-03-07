/***
 *
 * Program to print maximum, minimum limits of char, int, long using
 * calculation
 *
 ***/

/* The logic used is
* ~0 will give bits in 1s.
* (unsigned <type>) will cast it unsigned.
* >> 1 right shifts 1 bit to remove the sign bit.
* (<type>) casting it the required type again
*/


#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(void){
    /* ranges of various floating-point types from standard headers */
    printf("Ranges of various floating-point types from standard headers:\n");

    printf("Minimum Signed Char %d\n", SCHAR_MIN);
    printf("Maximum Signed Char %d\n", SCHAR_MAX);

    printf("Minimum Signed Short %d\n", SHRT_MIN);
    printf("Maximum Signed Short %d\n", SHRT_MAX);

    printf("Minimum Signed Int %d\n", INT_MIN);
    printf("Maximum Signed Int %d\n", INT_MAX);

    printf("Minimum Signed Long %ld\n", LONG_MIN);
    printf("Maximum signed Long %ld\n", LONG_MAX);

    /* Unsigned Maximum Values */

    printf("Maximum Unsigned Char %d\n", UCHAR_MAX);
    printf("Maximum Unsigned Short %d\n", USHRT_MAX);
    printf("Maximum Unsigned Int %u\n", UINT_MAX);
    printf("Maximum Unsigned Long %lu\n", ULONG_MAX);
    printf("\n");
        
    /* ranges of various floating-point types through calculation */
    printf("Ranges of various floating-point types through calculation:\n");
    
    printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));

    printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

    printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

    printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));

    /* Unsigned Maximum Values */
    printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
    printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
    printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
    printf("Maximum Unsigned Long %lu\n\n",(unsigned long)~0);
    return 0;
}


/*The ~ operator in C performs a bitwise NOT operation, all the 1 bits in operand are set to 0 and all 0 bits to 1. It creates the compliment of original number 
 * 10101000 11101001 // Original  (Binary for -22,295 in 16-bit two's complement)
 * 01010111 00010110 // ~Original (Binary for  22,294 in 16-bit two's complement)
 * The bitwise NOT operator has an interesting property that when applied on numbers represented by two's complement, it changes the number's sign and then subtracts one (as you can see in the above example).
 * 
 * unsigned char -> 1 byte -> 8 bits
 * ~0 -> 1
 * (unsigned char) 0 -> 00000000
 * (unsigned char)~0 -> 11111111
 * (unsigned char)~0 >> 1 -> 01111111
 *  - (char)((unsigned char)~0 >> 1) -> -127
 *  - (char)((unsigned char)~0 >> 1) - 1 -> -127 - 1 -> -128

 * */
