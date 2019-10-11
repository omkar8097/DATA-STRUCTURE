#include<iostream>
using namespace std;

int main()
{
	int i = 5;
	int a[3]={5,7,1};
	printf("i= %d\n",i);
	printf("&i= %d\n",&i);
	printf("*&i= %d\n",*&i);
	printf("(&i)[0]= %d\n",(&i)[0]);
	printf("0[&i]= %d\n",0[&i]);
	printf("a= %d\n",a);
	printf("a[0]= %p\n",a[0]);
	printf("a+1= %d\n",a+1);
	printf("a[1]= %p\n",a[1]);
	printf("*(a+1)= %d\n",*(a+1));
	printf("a[1]= %d\n",a[1]);

	printf("(&*(a+1))[-1]= %d\n",(&*(a+1))[-1]);
	//printf("*(&*(a+1))[-1]= %d\n",*(&*(a+1))[-1]);
}