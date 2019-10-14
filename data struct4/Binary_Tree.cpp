#include <iostream>
using namespace std;

class Binary
{
public:
	struct Node
	{
		Node *left ;
		Node *right;
		int value;

		Node(int value):left(nullptr),right(nullptr),value(value)
		{}
	};
	int count;

	Node *head;
	Binary():head(nullptr),count(0)
	{}
	Node* addNode(Node *node,int value)
	{
		if(nullptr == node)
			return new Node(value);
		if(value > node->value)
			node->right=addNode(node->right,value);
		else
			node->left=addNode(node->left,value);
		return node;
	}

	void printInOrder(Node *node)
	{
		if(node)
		{
			printInOrder(node->left);
			cout<<node->value<<"\t";
			printInOrder(node->right);

		}
	}

	void printPreOrder(Node*node)
	{
		if(node)
		{
			cout<<node->value<<"\t";
			printPreOrder(node->left);
			printPreOrder(node->right);

		}
	}

	void printPostOrder(Node*node)
	{
		if(node)
		{
			printPostOrder(node->left);
			printPostOrder(node->right);
			cout<<node->value<<"\t";

		}
	}

};

int main()
{
	Binary b1;
	b1.head=nullptr;
	int num;
	while(cout<<"Enter value to store in tree (press 0to STOP)  ",
		cin>>num,
		num)
	{
		b1.head=b1.addNode(b1.head,num);
	}
	cout<<"\nin Order print"<<endl;
	b1.printInOrder(b1.head);
	cout<<"\nPreOrder print"<<endl;
	b1.printPreOrder(b1.head);
	cout<<"\nPostOrder print"<<endl;
	b1.printPostOrder(b1.head);
}
