#include "Node.h"

Node::Node()
{
	key = 0;
	parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}

Node::Node(int _key)
{
	key = _key;
	parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}

Node::~Node()
{
	key = 0;
	parent = nullptr;
	Left = nullptr;
	Right = nullptr;
};

Node* Node::Search(Node* root, int _key)
{
	if (root == nullptr)
		return NULL;
	if (root->key == _key)
		return root;
	if (_key < root->key)
		return Search(root->Left, _key);
	else
		return Search(root->Right, _key);
}

Node* Node::SearchMin(Node* root)
{
	Node* curr = root;
	while (curr->Left != nullptr)
		curr = curr->Left;
	return curr;
}

Node* Node::SearchNext(Node* curr)
{
	Node* res = nullptr;
	if (curr->Right != nullptr)
	{
		res = SearchMin(curr->Right);
		return res;
	}
	res = curr->parent;
	Node* tmp = curr;
	while (res != nullptr && tmp == res->Right)
	{
		tmp = res;
		res = res->parent;
	}
	return res;
}

void Node::insert(Node* root, Node* node)
{
	if (root == nullptr)
	{
		root->key = node->key;
		root->Left = root->Right = root->parent = nullptr;
		return;
	}
	Node* x = root;
	Node* y = x;
	while (x != nullptr)
	{
		y = x;
		if (node->key < x->key)
			x = x->Left;
		else
			x = x->Right;
	}
	if (node->key < y->key)
	{
		y->Left = new Node();
		y->Left->key = node->key;
		y->Left->parent = y;

		y->Left->Left = nullptr;
		y->Left->Right = nullptr;
	}
	else
	{
		y->Right = new Node();
		y->Right->key = node->key;
		y->Right->parent = y;

		y->Right->Left = nullptr;
		y->Right->Right = nullptr;
	}
}

void Node::remove(Node* z)
{

	Node* y = nullptr;
	Node* x = nullptr;
	if (z->Left != nullptr && z->Right != nullptr)
		y = SearchNext(z);
	else
		y = z;
	if (y->Left != nullptr)
		x = y->Left;
	else
		x = y->Right;
	if (x != nullptr)
		x->parent = y->parent;
	if (y->parent != nullptr)
	{
		if (y == y->parent->Left)
			y->parent->Left = x;
		else
			y->parent->Right = x;
	}
	if (y != z)
	{
		z->key = y->key;
	}
}

void Node::print(const Node* root)
{
	if (root != nullptr)
	{
		print(root->Left);
		cout << " " << root->key;
		print(root->Right);
	}
}

ostream& operator<<(ostream& out, const Node& root)
{
	if (&root != nullptr)
		Node::print(&root);
	return out;
}