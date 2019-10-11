#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

int main()
{
	int num;
	struct node *head=NULL;
	struct node *temp=NULL;
	while(1)
	{
	printf("enter a num to save in linked list\n");
	scanf("%d",&num);
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->value= num;
	newnode->next = NULL;
	if(NULL==head)
	{
		head=newnode;
	}
	else
	{
		temp->next=newnode;
		temp=newnode->next;
	}
	}
	return 0;
}