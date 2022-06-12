#include<stdio.h>

int main()
{
  int v1=0;
  int v2=0;
  printf("\n Enter v1: ");
  scanf("%d",&v1);
  printf("\n Enter v2: ");
  fflush(stdin);
  scanf("%d",&v2);
  printf("\n v1+v2=%d ",v1+v2);
}



/*
 * fflush(stdin) is needed to flush or clear the input buffer.
 * It is beneficial to clear the input buffer with fflush(stdin) before taking the input using the scanf() statement.
 * using fflush() on an input stream doesn't work on all platforms; for example it doesn't generally work on Linux.
 * use int ch; while ((ch = getchar()) != '\n' && ch != EOF);
 */
