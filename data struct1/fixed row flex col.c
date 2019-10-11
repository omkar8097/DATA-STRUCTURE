#include <stdio.h>
#include <stdlib.h>
#define c 3

int main()
{
	int (*pa)[c];
	int rows;
	int i,j;

	printf("enter the number of rows\n");
	scanf("%d",&rows);

	pa=(int (*)[c])malloc(rows*sizeof(int[c]));
	printf("enter the data in matrix\n");
			
	for(i=0; i<rows; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("pa[%d][%d]= ",i,j);
			scanf("%d",&pa[i][j]);
		}
	}
	
	printf("\n-----------------------\n");
	for(i=0; i<rows; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("%d\t",pa[i][j]);
			
		}
		printf("\n-----------------------\n");
	}
	
	free(pa);
	return 0;

}