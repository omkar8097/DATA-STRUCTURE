#include <iostream>
using namespace std;

class SentinelList
{
private:
	struct Node
	{
		Node *prev;
		int value;
		Node *next;
		Node(int value)
		{
			this->value=value;
			this->prev=nullptr;
			this->next=nullptr;
		}
	};
	Node *head;
	Node *tail;
public:
	SentinelList()
	{
		head=new Node(0);
		tail=new Node(0);
		head->next=tail;
		tail->prev=head;

	}
	void addToBack(int value)
	{
		Node *newnode=new Node(value);
		newnode->prev=tail->prev;
		newnode->next=tail;
		tail->prev=tail->prev->next=newnode;
	}
	void addToFront(int value)
	{
		Node *newnode=new Node(value);
		newnode->prev=head;
		newnode->next=head->next;
		head->next=head->next->prev=newnode;
	}
	void printForward()
	{
		for(Node *p=head->next; p!=tail; p=p->next )
		{
			cout<<p->value<<"\t";
		}
	}
	int remove(int value)
	{
		Node*p=head->next;
		for(; p!=tail; p=p->next)
		{
			if(p->value == value)
			{
				p->prev->next=p->next;
				p->next->prev=p->prev;
				delete p;
				return 1;
			}
		}
		return 0;
	}

};

int main()
{
	SentinelList s1;
	int num;
	while(cout<<"enter the data which u want to add( press 0to stop)=",
		cin>>num,
		num)
	{
		s1.addToBack(num);
	}

	cout <<"\n  Output  "<<endl;
	s1.printForward();

	cout<<"\nadd to front "<<endl;
	s1.addToFront(66);
	cout<<"\nafter add 66 at front"<<endl;
	s1.printForward();

	while(cout<< "\n enter no. to remove"<<endl,
		cin >> num,
		num)
	{
		s1.remove(num);
		cout<<"after remove"<<endl;
		s1.printForward();
	}

	cout<<"after remove"<<endl;
	s1.printForward();

	return 0;

}