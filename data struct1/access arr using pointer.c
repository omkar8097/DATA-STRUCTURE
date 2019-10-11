#include <stdio.h>

int main()
{
		int i;
	int a[3];
	int *p;
	p=a;

	printf("Enter 3 no in an array\n");
	
	for(i=0; i<3; i++)
	{
		scanf("%d", p+i);
	}

	printf("Content of array\n");
	for(i=0; i<3; i++)
	{
		printf("a[%d]=  %d\n",i,*(p+i));
	}
	return 0;
}