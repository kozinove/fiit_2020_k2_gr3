#pragma once
#include "trnode.h"
#include<stack>
#include<queue>
#include <iostream>

using namespace std;

class binTree
{
public:
	treenode* root;
	binTree(treenode* rt = nullptr) : root(rt) {};
	treenode* getRoot() const { return root; }
	//static void insertNode(treenode*, treenode*);
	void workaround();
};

//void binTree::insertNode(treenode* root, treenode* node)
//{
//	if (root == nullptr)
//	{
//		root->key = node->key;
//		root->left = nullptr;
//		root->right = nullptr;
//		root->parent = nullptr;
//		return;
//	}
//
//	treenode* a = root;
//	treenode* tmp = a;
//	while (a != nullptr)
//	{
//		tmp = a;
//		if (node->key < a->key) a = a->left;
//		else a = a->right;
//	}
//
//	if (node->key < tmp->key)
//	{
//		tmp->left = new treenode();
//		tmp->left->key = node->key;
//		tmp->left->parent = tmp;
//		tmp->left->left = nullptr;
//		tmp->left->right = nullptr;
//	}
//
//	else
//	{
//		tmp->right = new treenode();
//		tmp->right->key = node->key;
//		tmp->right->parent = tmp;
//		tmp->right->left = nullptr;
//		tmp->right->right = nullptr;
//	}
//}
//


void binTree::workaround()
{
	if (root == 0)
		return;

	queue<treenode*> q;
	q.push(root);
	while (!q.empty())
	{
		treenode* tmp = q.front();
		q.pop();
		cout << *tmp;
		if (tmp->left != 0)
			q.push(tmp->left);
		if (tmp->right != 0)
			q.push(tmp->right);
	}
}