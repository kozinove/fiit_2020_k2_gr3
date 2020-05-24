#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

class BinaryTree
{
private:
	Node* root;
public:
	BinaryTree(Node* root_ = nullptr) : root(root_) {};

	static void insertNode(Node* root, Node* node);

	Node* getRoot() const;

	void print_direct_order(); // node - left - right
	void print_reverse_order(); // left - right - node
	void print_in_width(); // print level by level
};