#include<stdio.h>
#define N 20
#define TAB 8

int main(){
    int c;
    int count=0;
    int line_len = N;
    while((c=getchar())!=EOF){
        if(c==10){
            putchar(c);
            count = 0;
        }
        else if(c==9){
            int num_space = TAB - count%TAB;
            int temp = count;
            temp += num_space;
            if(temp > line_len){
                int actual_space = line_len - count;
                int left_over_space = temp - line_len;
                /*printf("count = %d, actual space = %d, left over space = %d", count, actual_space, left_over_space);*/
                for(int j =0; j < actual_space; j++){
                    putchar(32);
                }
                putchar(10);
                for(int j = 0; j < left_over_space; j++){
                    putchar(32);
                }
                count = left_over_space;
            }
            else{
                for(int j = 0; j < num_space; j++){
                    putchar(32);
                    count++;
                }
            }
        }
        else if(count==line_len){
            putchar(10);
            putchar(c);
            count = 1;
        }
        else{
            count++;
            putchar(c);
        }
    }
    return 0;
}
