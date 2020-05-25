#pragma once
#include<stack>
#include"trnode.h"

class Itr
{
	stack<treenode*> st;
public:
	bool hasNext();
	int next();
	Itr(treenode*);
};

Itr::Itr(treenode* root)
{
	st.push(root);
}

bool Itr::hasNext()
{
	return !st.empty();
}

int Itr::next()
{
	treenode* curr_t = st.top();
	st.pop();
	int key = curr_t->key;
	if (curr_t->right != NULL)
		st.push(curr_t->right);
	if (curr_t->left != nullptr)
		st.push(curr_t->left);
	return key;
}