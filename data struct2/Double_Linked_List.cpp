#include <iostream>
using namespace std;

struct node 
{
	node *prev;
	int value;
	node *next;
	node(int value)
	{
		this->value=value;
		this->prev=nullptr;
		this->next=nullptr;
	}
};

class double_linked
{
private :
	node *head;
	node *tail;
public:
	double_linked():head(nullptr),tail(nullptr)
	{}
	void addToBack(int value)
	{
		node *newnode=new node(value);
		if(head==nullptr)
		{
			head=newnode;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
		}
		tail=newnode;
	}
	void addToFront(int value)
	{
		node *newnode=new node(value);
		if(head==nullptr)
		{
			tail=newnode;
		}
		else
		{
			newnode->next=head;
			head->prev=newnode;
		}
		head=newnode;
	}
	void printForward()
	{
		node *current;
		for(current=head; current; current=current->next)
		{
			cout<<current->value<<endl;
		}
	}
	void printBackward()
	{
		node *current;
		for(current=tail; current; current=current->prev)
		{
			cout<<current->value<<endl;
		}
	}
	int removeAll()
	{
		int count =0;
		node *temp;
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
	int num;
	double_linked d;
	
	while(cout<<"Enter the data for Linked List(press 0 to stop)"<<endl,
		  cin>>num,
		  num)
	{
		d.addToBack(num);
		d.addToFront(num);
	}
	cout<<"\noutput forward"<<endl;
	d.printForward();
	cout<<"\noutput backward"<<endl;
	d.printBackward();

	cout<<"\nNo. of elements in Linked List to be removed"<<endl;
	cout<<d.removeAll()<<endl;
}
