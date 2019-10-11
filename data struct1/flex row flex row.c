#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **pp;
	int row;
	int *col;
	int i,j;
	printf("enter the rows");
	scanf("%d",&row);
	col=(int*)malloc(row*sizeof(int));
	
	pp=(int**)malloc(row*sizeof(int*));
	for(i=0; i<row; i++)
	{
		printf("enter no. of columns in row %d\n",i);
		scanf("%d",&col[i]);
		pp[i]=(int *)malloc(col[i]*sizeof(int));
	}

	for(i=0; i<row; i++)
	{
	for(j=0; j<col[i]; j++)
		{
			printf("pp[%d][%d]= ",i,j);
			scanf("%d",&pp[i][j]);
		}
	}

	printf("\nOutput\n");
	for(i=0; i<row; i++)
	{
		for(j=0; j<col[i]; j++)
		{
			printf("%d\t",pp[i][j]);
		}
		printf("\n");
	}
	for(i=0; i<row; i++)
		free(pp[i]);
	free(pp);
	free(col);
	return 0;
}