#pragma once
#include "Node.h"
#include <stack>

class BinaryTree
{
private:
	Node* root;
public:
	BinaryTree(Node* _root = nullptr) : root(_root) {};

	void print_itr();//обход дерева в прямом порядке
};
