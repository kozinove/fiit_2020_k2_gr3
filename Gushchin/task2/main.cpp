#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	int val;
	Node* l, * r;

	Node(int _val, Node* _l = NULL, Node* _r = NULL):
		val(_val), l(_l), r(_r) {}
};

class FTree
{
	Node* root;

	pair<Node*, stack<Node*>> findKey(int key)
	{
		pair<Node*, stack<Node*>> result;
		result.first = NULL;

		if (root == NULL) return result;
		
		Node* t = root;

		if (t->val == key)
		{
			result.first = root;
			return result;
		}

		while (true)
		{
			if (t == NULL) return result;

			if (key > t->val)
			{
				result.second.push(t);
				t = t->r;
			}
			else if (key < t->val)
			{
				result.second.push(t);
				t = t->l;
			}
			else
			{
				result.first = t;
				return result;
			}
		}

		return result;
	}

public:
	FTree()
	{
		root = NULL;
	}

	void add(int key)
	{
		pair<Node*, stack<Node*>> result = findKey(key);

		if (result.first != NULL) throw "Node already exists";

		Node* p = new Node(key);

		if (root == NULL)
		{
			root = p;
			return;
		}

		Node* t = result.second.top();

		if (key > t->val) t->r = p;
		else t->l = p;
	}

	void deleteNode(int key)
	{
		pair<Node*, stack<Node*>> result = findKey(key);

		if (result.first == NULL) throw "Node doesn't exist";


		if (result.first->r != NULL || result.first->l != NULL)
		{
			if (result.first->r == NULL)
			{
				if (result.second.empty())
				{
					root = result.first->l;
				}

				if (result.second.top()->l == result.first)
				{
					result.second.top()->l = result.first->l;
				}
				else
				{
					result.second.top()->r = result.first->l;
				}

				delete result.first;
			}
			else if (result.first->l == NULL)
			{
				if (result.second.empty())
				{
					root = result.first->r;
				}

				if (result.second.top()->l == result.first)
				{
					result.second.top()->l = result.first->r;
				}
				else
				{
					result.second.top()->r = result.first->r;
				}

				delete result.first;
			}
			else
			{
				//both not NULL
				Node* t = result.first->r;
				
				if (t->l == NULL)
				{
					result.first->val = t->val;
					result.first->r = t->r;
				}
				else
				{
					while (t->l != NULL) t = t->l;

					result.first->val = t->val;

					Node* prev = result.first->r;
					while (prev->l != t) prev = prev->l;

					prev->l = t->r;					
				}
				
				delete t;
			}

		}
		else
		{
			if (result.second.top()->l == result.first)
			{
				result.second.top()->l = NULL;
			}
			else
			{
				result.second.top()->r = NULL;
			}
			delete result.first;
		}

	}

	bool isContains(int key)
	{
		pair<Node*, stack<Node*>> result = findKey(key);
		return (result.first != NULL);
	}

	friend ostream& operator<<(ostream& ostr, FTree& tree);
};

void printLTR(ostream& ostr, Node* curr)
{
	if (curr == NULL) return;
	printLTR(ostr, curr->l);
	ostr << curr->val << " ";
	printLTR(ostr, curr->r);
}

ostream& operator<<(ostream& ostr, FTree& tree)
{
	printLTR(ostr, tree.root);
	ostr << endl;
	return ostr;
}


int main()
{
	FTree tree;

	tree.add(10);
	tree.add(4);
	tree.add(20);
	tree.add(-1);
	tree.add(8);
	tree.add(6);
	tree.add(7);
	tree.add(9);
	tree.add(17);
	tree.add(5);

	cout << tree;
	/*cout << tree.isContains(20) << endl;
	cout << tree.isContains(9) << endl;*/

	tree.deleteNode(4);
	cout << tree; 


	return 0;
}