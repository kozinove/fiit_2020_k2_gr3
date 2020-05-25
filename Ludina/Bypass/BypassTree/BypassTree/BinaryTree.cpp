#include "BinaryTree.h"


void BinaryTree::print_itr()
{
	if (root == nullptr)
		return;
	stack<Node*> s;
	s.push(root);
	while (!s.empty())
	{
		Node* tmp = s.top();
		s.pop();
		cout << tmp->getkey() << " ";
		if (tmp->getRight() != nullptr)
			s.push(tmp->getRight());
		if (tmp->getLeft() != nullptr)
			s.push(tmp->getLeft());
	}
}