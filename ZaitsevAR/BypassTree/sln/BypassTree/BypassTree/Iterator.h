#pragma once
#include "Node.h"
#include <stack>

class Iterator
{
private:
	stack<Node*> s;
public:
	Iterator(Node* root)
	{
		s.push(root);
	}

	bool hasNext()
	{
		return !s.empty();
	}

	int next()
	{
		Node* tmp = s.top();
		s.pop();
		int key_ = tmp->getKey();
		if (tmp->getRight() != nullptr)
			s.push(tmp->getRight());
		if (tmp->getLeft() != nullptr)
			s.push(tmp->getLeft());
		return key_;
	}
};