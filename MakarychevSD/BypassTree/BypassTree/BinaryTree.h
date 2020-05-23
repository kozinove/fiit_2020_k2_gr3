#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "TreeNode.h"
#include <queue>
#include <stack>

template <class TData>
class BinaryTree
{
private:
	TreeNode<TData>* root;
public:
	BinaryTree(TreeNode<TData>* _root = nullptr) : root(_root) {};

	void BypassLTR();
	void BypassInOrder();
	void BypassInWidth();

};

template <class TData>
void BinaryTree<TData> ::BypassLTR()
{
	if (this->root == nullptr)
	{
		cout << "Tree is empty " << endl;
		return;
	}
	cout << "BypassLTR" << endl;
	stack<TreeNode<TData>*> st;
	TreeNode<TData>* tmp = this->root;

	while (!st.empty() || tmp != nullptr)
	{
		while (tmp != nullptr)
		{
			st.push(tmp);
			tmp = tmp->GetLeft();
		}
		cout << st.top()->GetKey() << ' ';
		tmp = st.top()->GetRight();
		st.pop();
	}
}

template <class TData>
void BinaryTree<TData>::BypassInOrder()
{
	if (this->root == nullptr)
	{
		cout << "Tree is empty " << endl;
		return;
	}
	cout << "BypassInOrder" << endl;
	stack<TreeNode<TData>*> s;
	s.push(this->root);
	while (!s.empty())
	{
		TreeNode<TData>* tmp = s.top();
		s.pop();
		cout << tmp->GetKey() << " ";
		if (tmp->GetRight() != nullptr)
			s.push(tmp->GetRight());
		if (tmp->GetLeft() != nullptr)
			s.push(tmp->GetLeft());
	}
}

template <class TData>
void BinaryTree<TData>::BypassInWidth()
{
	if (this->root == nullptr)
	{
		cout << "Tree is empty " << endl;
		return;
	}
	cout << "BypassInWidth" << endl;
	queue< TreeNode<TData>*> q;
	q.push(this->root);
	while (!q.empty())
	{
		TreeNode<TData>* tmp = q.front();
		cout << tmp->GetKey() << " ";
		q.pop();
		if (tmp->GetLeft() != nullptr)
			q.push(tmp->GetLeft());
		if (tmp->GetRight() != nullptr)
			q.push(tmp->GetRight());
	}
}

#endif

