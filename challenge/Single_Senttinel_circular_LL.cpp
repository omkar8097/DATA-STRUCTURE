#include <iostream>
using namespace std;

class circular
{
	struct node
	{
		int value;
		node *next;
	public:
		node(int value)
		{
			this->value = value;
			next = nullptr;
		}
	};
	node *head = nullptr;
	node *p;
public:
	circular()
	{
		head = new node(0);
		head->next = nullptr;
	}

	void insert(int value)
	{
		node *newnode = new node(value);
		if (head->next==nullptr)
		{
			head->next = newnode;
			newnode->next = head;
		}
		else
		{
			newnode->next = head;
			p->next = newnode;
		}
		p = newnode;
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

	void delete_LL(int num)
	{
		node* p ;
			for (p = head; p->next != head; p = p->next)
			{

				if (p->next->value == num)
				{
					node*temp = p->next;
					p->next= p->next->next;
					delete temp;
				}


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
	
	for (int i = 0; i < 10; i++)
	{
		cout << "\nenter value to delete" << endl;
		cin >> num;
		c.delete_LL(num);
		c.print_LL();
	}
	cin >> num;
	return 0;
}