#include <stdio.h>
#include <stdlib.h>

//define node
struct node
{
	int value;
	struct node *next;
};

//define global pointer head and tail
struct node *head;
struct node *tail;

//function for push back
void addToBack(int value)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=value;
	newnode->next=NULL;

	if (NULL == head)
		head=newnode;
	else 
		tail->next=newnode;
	tail=newnode;
}

//function for push forward
void addToFront(int value)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=value;
	newnode->next=NULL;

	if (NULL == head)
		tail=newnode;
	else 
		newnode->next=head;
	head=newnode;
}

//print linkedd list
void printforward()
{
	struct node *current;
	printf("\nOutput\n");
	for (current = head ; current ; current=current->next)
	{
		printf("%d\t",current->value);
	}
}

int main ()
{
	int num;
	
	//pass the value to store in linked list
	while(printf("Enter the value (0 to terminate)\n"),
		  scanf("%d",&num),
		  num)
	{
		addToBack(num);
		addToFront(num);
	}

	//call the function to print the linked list
	printforward();

	return 0;
}
