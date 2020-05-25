#ifndef ITERATOR_H
#define ITERATOR_H

#include"TreeNode.h"
#include <stack>

template <class TData>
class Iterator
{
private:
	stack<TreeNode<TData>*> st;
public:
	Iterator(TreeNode<TData>* root)
	{
		st.push(root);
	}

	bool hasNext()
	{
		return !st.empty();
	}

	int Next()
	{
		TreeNode<TData>* tmp = st.top();
		st.pop();
		int val = tmp->GetKey();
		if (tmp->GetRight() != nullptr)
			st.push(tmp->GetRight());
		if (tmp->GetLeft() != nullptr)
			st.push(tmp->GetLeft());
		return val;
	}
};

#endif
