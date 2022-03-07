#include<stdio.h>

struct array1 { 
    int a[2]; 
};

void f1(struct array1 arg) {
    arg.a[0] = 1;
}

void pass_by_ref(int b[2]){
    b[0] = 10;
}

int main() {
    int b[2] = {50, 60};
    struct array1 x = {{100, 101}};
    f1(x);
    printf("%d\n", x.a[0]); // prints 100

    pass_by_ref(b);
    printf("%d\n", b[0]); // prints 10
    return 0;
}
