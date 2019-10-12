#include <iostream>
using namespace std;

template<class u>
class Sentinel
{
	//template<class u>
	struct Node
	{
		Node<u> *prev;
		u value;
		Node<u> *next;
		Node(u value)
		{
			this->prev=nullptr;
			this->value=value;
			this->next=nullptr;
		}
	};
	
	Node<u> *head;
	Node<u> *tail;
public:
	Sentinel()
	{
		head=new Node<u>(0);
		tail=new Node<u>(0);
		head->next=tail;
		tail->prev=head;
	}
	void insert(Node<u> *current,u value)
	{
		Node<u> *newnode=new Node<u>(value);
		newnode->next=current;
		newnode->prev=current->prev;
		//current->prev=current->prev->next=newnode;
		newnode->next->prev=newnode->prev->next=newnode;
	}

	void addToBack(u value)
	{
		insert(tail,value);
	}

	void addToFront(u value)
	{
		insert(head->next,value);
	}

	int insertAfter(u search,u value)
	{
		for(Node<u> *p=head->next;p!=tail;p=p->next)
		{
			if(search==p->value)
			{
				insert(p->next,value);
				return 1;
			}
		}
		return 0;
	}

	int insertBefore(u search,u value)
	{
		for(Node<u> *p=tail->prev;p!=head;p=p->prev)
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
		for(Node<u> *p=head->next;p!=tail;p=p->next)
		{
			cout<<p->value<<"  ";
		}

	}
};

int main()
{
	Sentinel<double> s;
	double num;
	double search;
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

