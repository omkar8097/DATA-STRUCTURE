#include <stdio.h>
#include <stdlib.h>
#define R 5
#define C 3

int main()
 {
	 int arr[R][C];
	 int i=0;
	 int j=0;

	 printf("\n Enter the data in the matrix\n");
	 for(i=0; i<R; i++)
	 {
		 for(j=0; j<C; j++)
		 {
			 printf("arr[%d][%d]= ",i,j);
			 scanf("%d",*(arr+i)+j);
		 }
	 }
	  printf("\n Output in the matrix\n");
	 for(i=0; i<R; i++)
	 {
		 for(j=0; j<C; j++)
		 {
			 printf("%d\t",*(*(arr+i)+j));
			 
		 }
		 printf("\n");
	 }


	 return 0;
 }