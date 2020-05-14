#include "BinaryTree.h"

Node::Node()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

Node::Node(int key_)
{
	key = key_;
	left = right = parent = nullptr;
}

Node::~Node()
{
	left = nullptr;
	right = nullptr;
}

Node* Node::searchMin(Node* root)
{
	Node* curr = root;
	while (curr->left != nullptr)
		curr = curr->left;
	return curr;
}

Node* Node::searchNext(Node* curr)
{
	Node* res = nullptr;
	if (curr->right != nullptr)
	{
		res = searchMin(curr->right);
		return res;
	}
	res = curr->parent;
	Node* tmp = curr;
	while (res != nullptr && tmp == res->right)
	{
		tmp = res;
		res = res->parent;
	}
	return res;
}

Node* Node::searchNode(Node* root, int key_)
{
	if (root == nullptr)
		return NULL;
	if (root->key == key_)
		return root;
	if (key_ < root->key)
		return searchNode(root->left, key_);
	else
		return searchNode(root->right, key_);
}

void Node::insertNode(Node* root, Node* node)
{
	if (root == nullptr)
	{
		root->key = node->key;
		root->left = root->right = root->parent = nullptr;
		return;
	}
	Node* x = root;
	Node* y = x; // äëÿ parent

	while (x != nullptr)
	{
		y = x;
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	if (node->key < y->key)
	{
		y->left = new Node();
		y->left->key = node->key;
		y->left->parent = y;

		y->left->left = nullptr;
		y->left->right = nullptr;
	}
	else
	{
		y->right = new Node();
		y->right->key = node->key;
		y->right->parent = y;

		y->right->left = nullptr;
		y->right->right = nullptr;
	}
}

void Node::removeNode(Node* z)
{
	if (z->left == nullptr && z->right == nullptr)
	{
		if (z->parent != nullptr)
		{
			if (z == z->parent->left)
				z->parent->left = nullptr;
			else
				z->parent->right = nullptr;
		}
		else
			z = nullptr;
	}
	else if ((z->left == nullptr && z->right != nullptr) ||
		(z->left != nullptr && z->right == nullptr))
	{
		if (z->left == nullptr)
		{
			z->right->parent = z->parent;
			if (z->parent->left == z)
				z->parent->left = z->right;
			else
				z->parent->right = z->right;
		}
		else if (z->right == nullptr)
		{
			z->left->parent = z->parent;
			if (z->parent->left == z)
				z->parent->left = z->left;
			else
				z->parent->right = z->left;
		}
		z = nullptr;
	}
	else
	{
		Node* y = nullptr;

		y = searchNext(z);
		z->key = y->key;

		removeNode(y);
	}
}

void Node::print(const Node* root)
{
	if (root != nullptr)
	{
		print(root->left);
		cout << " " << root->key << "\t";
		print(root->right);
	}
}

ostream& operator<<(ostream& out, const Node& root)
{
	if (&root != nullptr)
		Node::print(&root);

	return out;
}