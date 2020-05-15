#include <iostream> 
#include <stack>
using namespace std;

struct Node
{
    int val;
    Node* l, * r;
    Node(int _val, Node* _l = NULL, Node* _r = NULL) : val(_val), l(_l), r(_r) {}
};

void printLTR(ostream& o, Node* c)
{
    if (c == NULL) return;
    printLTR(o, c->l);
    cout << c->val << " ";
    printLTR(o, c->r);
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

    Node* minimumKey(Node* curr)
    {
        while (curr->l != nullptr)
        {
            curr = curr->l;
            return curr;
        }
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


    void deleteNode(int key)
    {
        Node* parent = nullptr;
        Node* curr = root;
        pair<Node*, stack<Node*> > res = findKey(key);
        curr = res.first;
        if (!res.second.empty())
        parent = res.second.top();
        if (curr == nullptr)
            return;
        if (curr->l == nullptr && curr->r == nullptr)
        {
            if (curr != root)
            {
                if (parent->l == curr)
                    parent->l = nullptr;
                else
                    parent->r = nullptr;
            }
            else
                root = nullptr;
            free(curr);
        }
        else if (curr->l && curr->r)
        {
            Node* successor = minimumKey(curr->r);
            int val = successor->val;
            deleteNode(successor->val);
            curr->val = val;
        }
        else
        {
            Node* child = (curr->l) ? curr->l : curr->r;
            if (curr != root)
            {
                if (curr == parent->l)
                    parent->l = child;
                else
                    parent->r = child;
            }
            else
                root = child;
            free(curr);
        }
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


    friend ostream& operator << (ostream& o, FTree& t);
};

ostream& operator << (ostream& o, FTree& t)
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
    cout << "tree.contain(-1)" << tree.contain(-1) << endl;
    cout << "tree.contain(6)" << tree.contain(6) << endl;
    tree.deleteNode(10);
    cout << tree;
    return 0;
}