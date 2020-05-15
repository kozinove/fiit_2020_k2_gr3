#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "TreeNode.h"
#include <queue>

template <class TData>
class BinaryTree
{
private:
	TreeNode<TData>* root;
public:
	BinaryTree(TreeNode<TData>* _root = nullptr) : root(_root) {};

	TreeNode<TData>* Search(int key);
	TreeNode<TData>* SearchMax();
	TreeNode<TData>* SearchMin();
	TreeNode<TData>* SearchNext(TreeNode<TData>* curr);
	TreeNode<TData>* SearchPrev(TreeNode<TData>* curr);
	void Insert(TreeNode<TData>* node);
	void Remove(TreeNode<TData>* node);

	friend ostream& operator <<(ostream& out, const BinaryTree& B)
	{
		queue< TreeNode<TData>*> q;
		q.push(B.root);
		while (!q.empty())
		{
			TreeNode<TData>* tmp = q.front();
			out << *tmp;
			q.pop();
			if (tmp->GetLeft() != nullptr)
				q.push(tmp->GetLeft());
			if (tmp->GetRight() != nullptr)
				q.push(tmp->GetRight());
		}
		return out;
	};
};

template <class TData>
TreeNode<TData>* BinaryTree<TData>:: Search(int key)
{
	TreeNode<TData>* curr = this->root;
	while (curr != nullptr && curr->GetKey() != key)
	{
		if (key < curr->GetKey()) 
			curr = curr->GetLeft();
		else 
			curr = curr->GetRight();
	}
	return curr;
}

template <class TData>
TreeNode<TData>* BinaryTree<TData>::SearchMax()
{
	TreeNode<TData>* curr = this->root;
	while (curr->GetRight() != nullptr)
	{
		curr = curr->GetRight();
	}
	return curr;
}

template <class TData>
TreeNode<TData>* BinaryTree<TData>::SearchMin()
{
	TreeNode<TData>* curr = this->root;
	while (curr->GetLeft() != nullptr)
	{
		curr = curr->GetLeft();
	}
	return curr;
}

template <class TData>
TreeNode<TData>* BinaryTree<TData>::SearchNext(TreeNode<TData>* curr)
{
	TreeNode<TData>* res = nullptr;
	if (curr->GetRight() != nullptr)
	{

		res = SearchMin();

		return res;
	}
	res = curr->GetParent();
	TreeNode<TData>* tmp = curr;
	while (res != nullptr && tmp == res->GetRight())
	{
		tmp = res;
		res = res->GetParent();
	}
	return res;
}

template <class TData>
TreeNode<TData>* BinaryTree<TData>::SearchPrev(TreeNode<TData>* curr)
{
	TreeNode<TData>* res = nullptr;
	if (curr->GetLeft() != nullptr)
	{
		res = SearchMax();

		return res;
	}
	res = curr->GetParent();
	TreeNode<TData>* tmp = curr;
	while (res != nullptr && tmp == res->GetLeft())
	{
		tmp = res;
		res = res->GetParent();
	}
	return res;
}

template <class TData>
void  BinaryTree<TData>::Insert(TreeNode<TData>* node)
{
	if (this->root == nullptr)
	{
		root = node;
		return;
	}
	TreeNode<TData>* x = this->root, * y = x;
	while (x != nullptr)
	{
		y = x;
		if (node->GetKey() < x->GetKey())
			x = x->GetLeft();
		else 
			x = x->GetRight();
	}
	node->SetParent(y);
	if (node->GetKey() < y->GetKey())
		y->SetLeft(node);
	else 
		y->SetRight(node);
}

template <class TData>
void BinaryTree<TData>::Remove(TreeNode<TData>* z)
{
	TreeNode<TData>* y = nullptr, * x = nullptr;
	if (z->GetLeft() != nullptr && z->GetRight() != nullptr)
	{
		y = SearchNext(z); 
	}
	else
	{
		y = z; 
	}
	if (y->GetLeft() != nullptr)
	{
		x = y->GetLeft();
	}
	else
	{
		x = y->GetRight();
	}
	if (x != nullptr)
		x->SetParent(y->GetParent());
	if (y->GetParent() != nullptr)
	{
		if (y == y->GetParent()->GetLeft())
			y->GetParent()->SetLeft(x);
		else 
			y->GetParent()->SetRight(x);
	}
	if (y != z)
	{
		z->SetKey(y->GetKey());
		delete z->GetData();
		z->SetData(y->GetData());
	}
}
#endif
