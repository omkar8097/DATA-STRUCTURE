#include <stdio.h>
#include <stdlib.h>
#define r 3

int main()
{
	int *ap[r];
	int col[r];
	int i,j;
	
	for(i=0; i<r; i++)
	{
		printf("enter how many columns you need for row %d\n",i);
		scanf("%d",&col[i]);
		ap[i]=(int(*))malloc(col[i]*sizeof(int));
	}	
    for(i=0; i<r; i++)
	{
		for(j=0; j<col[i]; j++)
		{
			printf("ap[%d][%d]= ",i,j);
			scanf("%d",&ap[i][j]);
		}
	}
	for(i=0; i<r; i++)
	{
		for(j=0; j<col[i]; j++)
		{
			printf("%d\t",ap[i][j]);
		}
		printf("\n");
	}
	return 0;
}