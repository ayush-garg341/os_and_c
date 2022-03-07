#include<stdio.h>

int power(int base, int n); // function prototype/declaration

int main(){ 
    int i;
    for(i=0; i<5; i++){
        printf("%d\n", power(2, i)); // function arguemnts
    }
    return 0;
}

// function definition
/*int power(int base, int n){ // call by value, params*/
    /*int p=1, i;*/
    /*for(i=0; i<n; i++){*/
        /*p*=base;*/
    /*}*/
    /*return p;*/
/*}*/


// more optimized power function in terms of memory, since call by value directly modifying n, copy of original argument
int power(int base, int n){
    int p;
    for(p=1; n>0; --n){
        p*=base;
    }
    return p;
}


// story is different for arrays, always passed as a reference. When the name of an array is used as an argument, the value passed to the function is the location or address of the beginning of array.
