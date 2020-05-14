#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

struct Node
{
	int val;
	Node* l, *r;
	Node(int _val, Node* _l = NULL, Node* _r = NULL):val(_val),l(_l),r(_r){}
};

void printLTR(ostream& o, Node* c)
{
	if (c == NULL) return;
	printLTR(o, c->l);
	cout << c->val << ' ';
	printLTR(o, c->r);
}

class FTree
{
	Node* root;

	pair <Node*, stack<Node*>> findKey(int key)
	{
		pair <Node*, stack<Node*>> res;
		res.first = NULL;
		if (root == NULL) return res;
		Node *t;
		t = root;

		if (t->val == key) { res.first = root; return res; }

		while (true)
		{
			if (t == NULL) return res; 
			if (key > t->val)
			{
				res.second.push(t);
				t = t->r;
			}
			else if (key == t->val) { res.first = t; return res; }
			else
			{
				res.second.push(t);
				t = t->l;
			}
		}
		return res;
	}

public:
	FTree() { root = NULL; };

	bool contain(int key)
	{
		pair <Node*, stack<Node*>> res = findKey(key);
		return res.first != NULL;
	}

	void deleteNode(int key)
	{
		pair<Node*, stack<Node*>> res = findKey(key);
		if (res.first == NULL) throw -1;

		if (res.first->r != NULL || res.first->l != NULL)
		{
			if (res.first->r == NULL)
			{
				if (res.second.top()->l == res.first)
				{
					res.second.top()->l = res.first->l;
				}
				else
				{
					res.second.top()->r = res.first->l;
				}

				delete res.first;
			}
			else if (res.first->l == NULL)
			{
				if (res.second.top()->l == res.first)
				{
					res.second.top()->l = res.first->r;
				}
				else
				{
					res.second.top()->r = res.first->r;
				}

				delete res.first;
			}
			else
			{
				Node* t = res.first->r;

				if (t->l == NULL)
				{
					res.first->val = t->val;
					res.first->r = t->r;
				}
				else
				{
					while (t->l != NULL) t = t->l;

					res.first->val = t->val;

					Node* p = res.first->r;
					while (p->l != t) p = p->l;

					p->l = t->r;
				}

				delete t;
			}

		}
		else
		{
			if (res.second.top()->l == res.first)
			{
				res.second.top()->l = NULL;
			}
			else
			{
				res.second.top()->r = NULL;
			}
			delete res.first;
		}

	}


	void add(int key)
	{
		pair <Node*, stack<Node*>> res = findKey(key);
		if (res.first != NULL) throw - 1;

		Node *p = new Node(key);

		if (root == NULL) { root = p; return; }

		Node* t = res.second.top();
		if (key > t->val) t->r = p;
		else t->l = p;
	}

	friend ostream& operator << (ostream& o, FTree & t);

};

ostream& operator << (ostream& o, FTree & t)
{
	printLTR(o, t.root);
	o << endl;
	return o;
}

int main()
{
	FTree tree;

	tree.add(10);
	tree.add(5);
	tree.add(20);
	tree.add(-1);
	tree.add(8);

	cout << tree;

	cout << "tree.contain(5) " << tree.contain(5) << endl;	

	tree.deleteNode(5);

	cout << tree;

	cout << "tree.contain(5) " << tree.contain(5) << endl;



	system("pause");
	return 0;
}