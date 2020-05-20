#include "BinTree.h"


treeNode* BinTree::searchMin(treeNode* root)
{
	treeNode* curr = root;
	while (curr->left != nullptr) curr = curr->left;
	return curr;
}

treeNode* BinTree::searchNext(treeNode* curr)
{
	treeNode* r = NULL;
	if (curr->right != NULL)
	{
		r = searchMin(curr);
		return r;
	}
	r = curr->parent;
	treeNode* tmp = curr;
	while (res != NULL && tmp == r->right)
	{
		tmp = r;
		r = r->parent;
	}
	return r;
}

treeNode* BinTree::search(treeNode* root, int k)
{
	if (root == nullptr) return 0;
	if (root->key == k) return root;
	if (k < root->key) return searchNode(root->left, k);
	else return searchNode(root->right, k);
}

treeNode* BinTree::getRoot() const
{
	return root;
}

void BinTree::insertNode(treeNode* root, treeNode* node)
{
	if (root == nullptr)
	{
		root->key = node->key;
		root->left = root->right = root->parent = nullptr;
		return;
	}
	treeNode* x = root;
	treeNode* y = x;
	while (x != nullptr)
	{
		y = x;
		if (node->key < x->key) x = x->left;
		else x = x->right;
	}
	if (node->key < y->key)
	{
		y->left = new treeNode();
		y->left->key = node->key;
		y->left->parent = y;
		y->left->left = nullptr;
		y->left->right = nullptr;
	}
	else
	{
		y->right = new treeNode();
		y->right->key = node->key;
		y->right->parent = y;
		y->right->left = nullptr;
		y->right->right = nullptr;
	}
}

void BinTree::deleteNode(treeNode* a)
{
	if ( a->right == nullptr && a->left == nullptr)
	{
		if (a->parent != nullptr)
		{
			if (a == a->parent->left) a->parent->left = nullptr;
			else a->parent->right = nullptr;
		}
		else a = nullptr;
	}
	else if (a->left == nullptr && a->right != nullptr ||a->left != nullptr && a->right == nullptr)
	{
		if (a->left == nullptr)
		{
			a->right->parent = a->parent;
			if (a->parent->left == a) a->parent->left = a->right;
			else a->parent->right = a->right;
		}
		else if (a->right == nullptr)
		{
			a->left->parent = a->parent;
			if (a->parent->left == a) a->parent->left = a->left;
			else a->parent->right = a->left;
		}
		a = nullptr;
	}
	else
	{
		treeNode* y = nullptr;
		y = searchNext(a);
		a->key = y->key;
		removeNode(y); 
	}
}

void BinTree::print(const treeNode* root)
{
	if (root != nullptr)
	{
		print(root->left);
		cout << *root << endl;
		print(root->right);
	}
}
