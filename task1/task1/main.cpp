#include <iostream>
#include "TStack.h"

using namespace std;

struct Node
{
	int val;
	Node* l;
	Node* r;
	Node(int _val = 0.0, Node* _l = NULL, Node* _r = NULL) :val(_val), l(_l), r(_r) {}
};

void print(Node *curr_t)
{
	if (curr_t == NULL) return;
	print(curr_t->l);
	cout << curr_t->val << ' ';
	print(curr_t->r);
}

void printItr(Node *root)
{
	TStack<Node*> stack(20);
	while (!stack.isEmpty() || root != NULL)
	{
		if (root != NULL)
		{
			stack.sPush(root);
			root = root->l;
		}
		else
		{
			root = stack.sTop();
			stack.Pop();
			cout << root->val << ' ';
			root = root->r;
		}
	}
}

class task
{
	int value;
	TStack<Node*>st{20};
	Node *node;
public:
	task(Node *root) 
	{
		node = root;
		value = 0;
	}
	bool hasNext()
	{
		if (node != NULL) return 1;
		if (!st.isEmpty()) return 1;
		else return 0;
	}
	int next()
	{
		if (node != NULL)
		{
			st.sPush(node);
			node = node->l;
		}
		else
		{
			node = st.sTop();
			int value = node->val;
			st.Pop();
			node = node->r;
			cout << value << ' ';
		}
		return value;
	}
};

class Itr
{
private:
	TStack<Node*> st{20};
public:
	Itr(Node* root)
	{
		st.sPush(root);
	}
	bool hasNext()
	{
		return !st.isEmpty();
	}
	int next()
	{
		Node* curr_t = st.sTop();
		st.Pop();
		int val = curr_t->val;
		if (curr_t->r != NULL) st.sPush(curr_t->r);
		if (curr_t->l != NULL) st.sPush(curr_t->l);
		return val;
	}
};

int main()
{
	Node * p1 = new Node(3);
	Node* p2 = new Node(5);
	Node* p3 = new Node(6);
	Node* p4 = new Node(4,p2,p3);
	Node* p5 = new Node(2,p1,p4);
	Node* p6 = new Node(1,p5,NULL);
	Node *root = p6;
	//Node * p1 = new Node(4);
	//Node* p2 = new Node(6);
	//Node* p3 = new Node(3);
	//Node* p4 = new Node(5,NULL,p2);
	//Node* p5 = new Node(2,p1,p4);
	//Node* p6 = new Node(1,p5,p3);
	//Node *root = p6;
	print(root);
	cout << '\n';
	printItr(root);
	cout << '\n';
	task t(root);
	while (t.hasNext())
	{
		if(t.next()!=0) cout << t.next() << ' ';
	}
	system("pause");
	return 0;
}