#pragma once
#include "Node.h"
#include <stack>

class Iterat
{
private:
	stack<Node*> s;
public:
	Iterat(Node* root)
	{
		s.push(root);
	}

	bool HasNext()
	{
		return !s.empty();
	}

	int Next()
	{
		Node* tmp = s.top();
		s.pop();
		int val = tmp->getkey();
		if (tmp->getRight() != nullptr)
			s.push(tmp->getRight());
		if (tmp->getLeft() != nullptr)
			s.push(tmp->getLeft());
		return val;
	}
};