/*
 * A buffer is temporary storage used to store input and output commands.
 * All input and output commands are buffered in the operating system’s buffer.
 * C uses a buffer to output or input variables.
 * The buffer stores the variable that is supposed to be taken in (input) or sent out (output) of the program.
 * A buffer needs to be cleared before the next input is taken in.
 */


#include<stdio.h>

int main()
{
  int v1,v2;
  printf("\n Enter v1: ");
  scanf("%d",&v1);
  printf("\n Enter v2: ");
  scanf("%d",&v2);
  printf("\n v1+v2=%d\n ",v1+v2);
}

/*
 * Enter v1: 10
 * Enter v2: 20
 * v1+v2=30
 *
 * Enter v1: 10 20
 * Enter v2:
 * v1+v2=30
 *
 * v2 is automatically taken from the previous run by the buffer.
 */
