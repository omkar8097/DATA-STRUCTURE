#include <iostream>
using namespace std;

class Sentinel
{

	struct Node
	{
		Node *prev;
		int value;
		Node *next;
		Node(int value)
		{
			this->prev=nullptr;
			this->value=value;
			this->next=nullptr;
		}
	};
	
	Node *head;
	Node *tail;
public:
	Sentinel()
	{
		head=new Node(0);
		tail=new Node(0);
		head->next=tail;
		tail->prev=head;
	}
	void insert(Node *current,int value)
	{
		Node *newnode=new Node(value);
		newnode->next=current;
		newnode->prev=current->prev;
		//current->prev=current->prev->next=newnode;
		newnode->next->prev=newnode->prev->next=newnode;
	}

	void addToBack(int value)
	{
		insert(tail,value);
	}

	void addToFront(int value)
	{
		insert(head->next,value);
	}

	int insertAfter(int search,int value)
	{
		for(Node *p=head->next;p!=tail;p=p->next)
		{
			if(search==p->value)
			{
				insert(p->next,value);
				return 1;
			}
		}
		return 0;
	}

	int insertBefore(int search,int value)
	{
		for(Node *p=tail->prev;p!=head;p=p->prev)
		{
			if(search==p->value)
			{
				insert(p,value);
				return 1;
			}
		}
		return 0;
	}
	void printForward()
	{
		for(Node *p=head->next;p!=tail;p=p->next)
		{
			cout<<p->value<<"  ";
		}

	}
};

int main()
{
	Sentinel s;
	int num;
	int search;
	while(cout<<"Enter the elements : ",
		cin>>num,
		num)
	{
		s.addToBack(num);
	}

	cout<<"\n Original List "<<endl;
	s.printForward();

	while(cout<<"\n search element inserting Before " ,
		cin>>search>>num,
		num)
	{
		s.insertBefore(search,num);
	}

	cout<<"\n After Inserting"<<endl;
	s.printForward();


	while(cout<<"\n search element inserting After " ,
		cin>>search>>num,
		num)
	{
		s.insertAfter(search,num);
	}

	cout<<"\n After Inserting"<<endl;
	s.printForward();


return 0;
}

