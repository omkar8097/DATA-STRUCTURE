#include <iostream>
using namespace std;

class circular
{
	struct node
	{
		node *prev;
		int value;
		node *next;
	public:
		node(int value)
		{
			this->value = value;
			prev = nullptr;
			next = nullptr;
		}
	};
	node *head = nullptr;
public:
	circular()
	{
		head = new node(0);
		head->next = nullptr;
		head->prev = nullptr;
	}
	void insert(int value)
	{
		node *newnode = new node(value);
		if (head->next==nullptr)
		{
			head->next = newnode;
			head->prev = newnode;
			newnode->next = head;
			newnode->prev = head;
		}
		else
		{
			newnode->prev = head->prev;
			newnode->next = head;
			newnode->next->prev = newnode->prev->next = newnode;
		}
	}

	void print_LL()
	{
		node *p = head->next;
		while (p != head)
		{
			cout << p->value << "\t";
			p = p->next;
		}
	}

};

int main()
{
	circular c;
	for (int i = 0; i < 10; i++)
		c.insert(i);
	
	c.print_LL();
	int num;
	cin >> num;
}