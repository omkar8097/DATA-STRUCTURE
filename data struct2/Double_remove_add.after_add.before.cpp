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
	bool remove(int value)
	{
		node *p=head;
		while(p)
		{
			if(p->value==value)
			{
				//1. p == head,tail
				if(p==head && p==tail)
				{
					p->prev = nullptr;
					p->next = nullptr;
					delete p;
					return 1;
				}

				//2. p==head
				if(p == head)
				{
					head=head->next;
					head->prev->next=nullptr;
					head->prev =nullptr;
					delete p;
					return 1;
				}

				//3. p == tail
				if(p == tail)
				{
					tail=tail->prev;
					tail->next->prev=nullptr;
					tail->next=nullptr;
					delete p;
					return 1;
				}

				//4. p == in between
				p->next->prev=p->prev;
				p->prev->next=p->next;
				delete p;
				return 1;

			}
			p=p->next;
		}
		return 0;
	}
	bool insertAfter(int search,int value)
	{
		node *p=head;
		node *newnode = new node(value); 
		while(p != nullptr)
		{
			if(p->value == search)
			{
				// 1.p == tail
				if(p == tail)
				{
					tail=newnode;
					p->next=newnode;
					newnode->prev=p;
					return 1;

				}
				// 2.p == in between 
				newnode->prev = p;
				newnode->next = p->next;
				newnode->prev->next=newnode;
				newnode->next->prev=newnode;
				return 1;
			}
			p=p->next;
		}
			return 0;
		} s
	bool insertBefore(int search,int value)
	{
		node *p=head;
		node *newnode = new node(value); 
		while(p)
		{
			if(p->value == search)
			{
			// 1. p == head
			if(p == head)
			{
				head = newnode;
				head->next = p;
				p->prev = newnode;
				return 1;
			}
			// 2. p == in between
			newnode->prev = p->prev;
			newnode->next = p;
			newnode->prev->next = newnode;
			newnode->next->prev = newnode;
			return 1;
			}
			p=p->next;
		}
		return 0;
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
		//d.addToFront(num);
	}
	cout<<"\noutput forward"<<endl;
	d.printForward();
	//cout<<"\noutput backward"<<endl;
	//d.printBackward();

	int rem;
	cout<<"enter the no which u want remove"<<endl;
	cin>>rem;
	cout<<d.remove(rem)<<endl;
	cout<<"after remove" <<endl;
	d.printForward();

	int search,add;
	cout<<"\n\nenter the no which u want search and insert after value"<<endl;
	cin>>search;
	cin>>add;
	cout<<d.insertAfter(search,add)<<endl;
	cout<<"after add" <<endl;
	d.printForward();

	cout<<"\n\nenter the no which u want search and insert before value"<<endl;
	cin>>search;
	cin>>add;
	cout<<d.insertBefore(search,add)<<endl;
	cout<<"after add" <<endl;
	d.printForward();


}
