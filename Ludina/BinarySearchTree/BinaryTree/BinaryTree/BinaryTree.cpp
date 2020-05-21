#include "BinaryTree.h"

Node* BinaryTree::Min(Node* root)
{
	Node* curr = root;
	while (curr->getLeft() != nullptr)
		curr = curr->getLeft();
	return curr;
}

Node* BinaryTree::Search(int _key)
{
	Node* curr = this->root;
	while (curr != nullptr && curr->getkey() != _key)
	{
		if (_key < curr->getkey())
			curr = curr->getLeft();
		else
			curr = curr->getRight();
	}
	return curr;
}

Node* BinaryTree::SearchMin()
{
	Node* curr = this->root;
	while (curr->getLeft() != nullptr)
		curr = curr->getLeft();
	return curr;
}

Node* BinaryTree::SearchNext(Node* curr)
{
	Node* res = nullptr;
	if (curr->getRight() != nullptr)
	{
		res = Min(curr->getRight());
		return res;
	}
	res = curr->getParent();
	Node* tmp = curr;
	while (res != nullptr && tmp == res->getRight())
	{
		tmp = res;
		res = res->getParent();
	}
	return res;
}

void BinaryTree::insert(Node* node)
{
	if (this->root == nullptr)
	{
		root = node;
		return;
	}
	Node* x = this->root;
	Node* y = x;
	while (x != nullptr)
	{
		y = x;
		if (node->getkey() < x->getkey())
			x = x->getLeft();
		else
			x = x->getRight();
	}
	if (node->getkey() < y->getkey())
	{
		y->setLeft(new Node());
		y->getLeft()->setkey(node->getkey());
		y->getLeft()->setParent(y);

		y->getLeft()->setLeft(nullptr);
		y->getLeft()->setRight(nullptr);
	}
	else
	{
		y->setRight(new Node());
		y->getRight()->setkey(node->getkey());
		y->getRight()->setParent(y);

		y->getRight()->setLeft(nullptr);
		y->getRight()->setRight(nullptr);
	}
}

void BinaryTree::remove(Node* z)
{

	Node* y = nullptr;
	Node* x = nullptr;
	if (z->getLeft() != nullptr && z->getRight() != nullptr)
		y = SearchNext(z);
	else
		y = z;
	if (y->getLeft() != nullptr)
		x = y->getLeft();
	else
		x = y->getRight();
	if (x != nullptr)
		x->setParent(y->getParent());
	if (y->getParent() != nullptr)
	{
		if (y == y->getParent()->getLeft())
			y->getParent()->setLeft(x);
		else
			y->getParent()->setRight(x);
	}
	if (y != z)
	{
		z->setkey(y->getkey());
	}
}

void BinaryTree::print(const Node* root)
{
	if (root != nullptr)
	{
		print(root->getLeft());
		cout << " " << root->getkey();
		print(root->getRight());
	}
}

ostream& operator<<(ostream& out, const BinaryTree& Tree)
{
	if (Tree.root != nullptr)
		BinaryTree::print(Tree.root);
	return out;
}