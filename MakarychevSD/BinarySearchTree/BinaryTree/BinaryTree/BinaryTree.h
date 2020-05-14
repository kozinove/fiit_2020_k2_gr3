#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "TreeNode.h"

template <class TData>
class BinaryTree
{
private:
	TreeNode<TData>* root;
public:
	BinaryTree(TreeNode<TData>* _root = nullptr) : root(_root) {};

	TreeNode<TData>* Search(TreeNode<TData>* root, int key);
	TreeNode<TData>* SearchMax(TreeNode<TData>* root);
	TreeNode<TData>* SearchMin(TreeNode<TData>* root);
	TreeNode<TData>* SearchNext(TreeNode<TData>* curr);
	TreeNode<TData>* SearchPrev(TreeNode<TData>* curr);
	void Insert(TreeNode<TData>** root, TreeNode<TData>* node);
	void Remove(TreeNode<TData>* node);

};

template <class TData>
TreeNode<TData>* BinaryTree<TData>:: Search(TreeNode<TData>* root, int key)
{
	TreeNode<TData>* curr = root;
	while (curr != nullptr && curr->key != key)
	{
		if (key < curr->key) 
			curr = curr->pLeft;
		else 
			curr = curr->pRight;
	}
	return curr;
}

template <class TData>
TreeNode<TData>* BinaryTree<TData>::SearchMax(TreeNode<TData>* root)
{
	TreeNode<TData>* curr = root;
	while (curr->pRight != nullptr)
	{
		curr = curr->pRight;
	}
	return curr;
}

template <class TData>
TreeNode<TData>* BinaryTree<TData>::SearchMin(TreeNode<TData>* root)
{
	TreeNode<TData>* curr = root;
	while (curr->pLeft != nullptr)
	{
		curr = curr->pLeft;
	}
	return curr;
}

template <class TData>
TreeNode<TData>* BinaryTree<TData>::SearchNext(TreeNode<TData>* curr)
{
	TreeNode<TData>* res = nullptr;
	if (curr->right != nullptr)
	{

		res = SearchMin(curr);

		return res;
	}
	res = curr->pParent;
	TreeNode<TData>* tmp = curr;
	while (res != nullptr && tmp == res->pRight)
	{
		tmp = res;
		res = res->pParent;
	}
	return res;
}

template <class TData>
TreeNode<TData>* BinaryTree<TData>::SearchPrev(TreeNode<TData>* curr)
{
	TreeNode<TData>* res = nullptr;
	if (curr->pLeft != nullptr)
	{
		res = SearchMax(curr);

		return res;
	}
	res = curr->pParent;
	TreeNode<TData>* tmp = curr;
	while (res != nullptr && tmp == res->pLeft)
	{
		tmp = res;
		res = res->pParent;
	}
	return res;
}

template <class TData>
void  BinaryTree<TData>::Insert(TreeNode<TData>** root, TreeNode<TData>* node)
{
	if (*root == nullptr)
	{
		*root = node;
		return;
	}
	TreeNode<TData>* x = *root, * y;
	while (x != nullptr)
	{
		y = x;
		if (node->key < x->key) 
			x = x->pLeft;
		else 
			x = x->pRight;
	}
	node->pParent = y;
	if (node->key < y->key) 
		y->pLeft = node;
	else 
		y->pRight = node;
}

template <class TData>
void BinaryTree<TData>::Remove(TreeNode<TData>* z)
{
	TreeNode<TData>* y = nullptr, * x = nullptr;
	if (z->pLeft != nullptr && z->pRight != nullptr)
	{
		y = SearchNext(z); 
	}
	else
	{
		y = z; 
	}
	if (y->pleft != nullptr)
	{
		x = y->pLeft;
	}
	else
	{
		x = y->pRight;
	}
	if (x != nullptr)
		x->pParent = y->pParent;
	if (y->parent != nullptr)
	{
		if (y == y->pParent->pLeft) 
			y->pParent->pLeft = x;
		else 
			y->pParent->pRight = x;
	}
	if (y != z)
	{
		z->key = y->key;
		delete z->dpDta;
		z->pData = y->pData;
	}
}
#endif
