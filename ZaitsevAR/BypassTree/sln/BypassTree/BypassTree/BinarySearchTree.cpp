#include "BinarySearchTree.h"
#include <stack>
#include <queue>

void BinaryTree::insertNode(Node* root, Node* node)
{
	if (root == nullptr)
	{
		root->key = node->key;
		root->left = root->right = root->parent = nullptr;
		return;
	}
	Node* x = root;
	Node* y = x; // для parent

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

void BinaryTree::print_direct_order()
{
	if (root == 0)
		return;

	stack<Node*> s;
	s.push(root);
	while (!s.empty())
	{
		Node* tmp = s.top();
		s.pop();
		cout << *tmp;
		if (tmp->right != 0)
			s.push(tmp->right);
		if (tmp->left != 0)
			s.push(tmp->left);
	}
	cout << endl;
}

void BinaryTree::print_reverse_order()
{
	if (root == 0)
		return;

	stack<Node*> s1;
	stack<Node*> s2;

	s1.push(root);
	while (!s1.empty())
	{
		Node* tmp = s1.top();
		s1.pop();
		s2.push(tmp);
		if (tmp->left != 0)
			s1.push(tmp->left);
		if (tmp->right != 0)
			s1.push(tmp->right);
	}

	while (!s2.empty())
	{
		Node* tmp = s2.top();
		s2.pop();
		cout << *tmp;
	}
	cout << endl;
}

void BinaryTree::print_in_width()
{
	if (root == 0)
		return;

	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* tmp = q.front();
		q.pop();
		cout << *tmp;
		if (tmp->left != 0)
			q.push(tmp->left);
		if (tmp->right != 0)
			q.push(tmp->right);
	}
	cout << endl;
}

Node* BinaryTree::getRoot() const { return root; }