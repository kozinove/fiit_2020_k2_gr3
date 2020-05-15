#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	int val;
	Node* l;
	Node* r;
	Node(int _key = 0, Node* _l = NULL, Node* _r = NULL) : val(_key), l(_l), r(_r) {}
};

void RTLprintR(ostream& o, Node* curr_t)
{
	if (curr_t == NULL) return;
	RTLprintR(o, curr_t->r);
	o << curr_t->val << " ";
	RTLprintR(o, curr_t->l);
}

class FTree
{
    Node* root;

    pair<Node*, stack<Node*>> findKey(int key)
    {
        pair<Node*, stack<Node*>> res;
        res.first = NULL;
        if (root == NULL) return res;
        Node* t;
        t = root;
        if (t->val == key)
        {
            res.first = root;
            return res;
        }
        while (true)
        {
            if (t == NULL) return res;
            if (key > t->val)
            {
                res.second.push(t);
                t = t->r;
            }
            else if (key == t->val)
            {
                res.first = t;
                return res;
            }
            else
            {
                res.second.push(t);
                t = t->l;

            }
        }
        return res;
    }

public:

    FTree()
    {
        root = NULL;
    }

    bool contain(int key)
    {
        pair<Node*, stack<Node*>> res = findKey(key);
        return res.first != NULL;
    }

    void add(int key)
    {
        pair<Node*, stack<Node*> > res = findKey(key);
        if (res.first != NULL) throw - 1;
        Node* p = new Node(key);
        if (root == NULL)
        {
            root = p;
            return;
        }
        Node* t = res.second.top();
        if (key > t->val)
        {
            t->r = p;
        }
        else
        {
            t->l = p;
        }
    }

	void del(int _key)
	{
		pair<Node*, stack<Node*> > res = findKey(_key);
		Node* Ntd = res.first;

		if ((Ntd->l == NULL) && (Ntd->r == NULL))
		{
			if (res.second.top()->l == res.first)
			{
				res.second.top()->l = NULL;
			}
			else
			{
				res.second.top()->r = NULL;
			}
			delete Ntd;
		}
		else if ((Ntd->l != NULL) && (Ntd->r == NULL))
		{
			if (res.second.top()->l == res.first)
			{
				res.second.top()->l = res.first->l;
			}
			else
			{
				res.second.top()->r = res.first->l;
			}
			delete Ntd;
		}
		else if ((Ntd->l == NULL) && (Ntd->r != NULL))
		{
			if (res.second.top()->l == res.first)
			{
				res.second.top()->l = res.first->r;
			}
			else
			{
				res.second.top()->r = res.first->r;
			}
			delete Ntd;
		}
		else
		{
			Node* t = Ntd->l;
			Node* tm1 = Ntd;
			while (t->r != NULL)
			{
				tm1 = t;
				t = t->r;
			}
			int max = t->val;
			Ntd->val = max;
			tm1->r = t->l;
			t->l = NULL;
			delete t;
		}
	}

    friend ostream& operator << (ostream& o, FTree& t);
};

ostream& operator << (ostream& o, FTree& t)
{
	RTLprintR(o, t.root);
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
	cout << "tree.contain(-1)" << tree.contain(-1) << endl;
	cout << "tree.contain(6)" << tree.contain(6) << endl;
	tree.del(20);
	cout << tree;
	return 0;
}