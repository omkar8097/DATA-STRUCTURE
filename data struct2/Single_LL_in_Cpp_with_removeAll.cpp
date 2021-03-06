#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;
	Node(int value)
	{
		this->value=value;
		this->next =nullptr;
	}
};

class SingleLinkedList
{
private:
	Node *head;
	Node *tail;
public:
	SingleLinkedList():head(nullptr),tail(nullptr)
	{}
	void addtoback(int value)
	{
		Node *newnode=new Node(value);
		//newnode->value=value;
		//newnode->next=nullptr;
		if(nullptr==head)
			head=newnode;
		else
			tail->next=newnode;
		tail=newnode;
	}

	void addtofront(int value)
	{
		Node *newnode=new Node(value);
		//newnode->value=value;
		//newnode->next=nullptr;
		if(nullptr==head)
			tail=newnode;
		else
			newnode->next=head;
		head=newnode;
	}

	void printforward()
	{
		for(Node *current=head; current; current=current->next)
		{
			cout<<current->value<<"\t"<<endl;
		}
	}

	int removeAll()
	{
		int count=0;
		Node *temp;
		while(head)
		{
			temp=head;
			head=head->next;
			delete temp;
			count++;
		}
		tail=nullptr;
		return count;
	}
};

int main()
{
	SingleLinkedList s1;
	SingleLinkedList s2;

	int num;
	while(cout<<"Enter a value",cin>>num,num)
	{
		s1.addtoback(num);
		s2.addtofront(num);
	}

	cout<<"Output of object s1's Linked list"<<endl;
	s1.printforward();

	cout<<"Output of object s2's Linked list"<<endl;
	s2.printforward();

	cout<<"\nNo. of elements in Linked List to be removed of s1"<<endl;
	cout<<s1.removeAll()<<endl;

	cout<<"\nNo. of elements in Linked List to be removed of s2"<<endl;
	cout<<s2.removeAll()<<endl;
}

