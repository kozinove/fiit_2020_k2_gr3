#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
	Node* parent;

	Node();
	Node(int key_);
	Node(const Node& node);
	~Node();

	Node* getLeft() const;
	Node* getRight() const;
	Node* getParent() const;

	void setLeft(Node* left_);
	void setRight(Node* right_);
	void setParent(Node* parent_);

	friend ostream& operator<<(ostream& out, const Node& root);
};