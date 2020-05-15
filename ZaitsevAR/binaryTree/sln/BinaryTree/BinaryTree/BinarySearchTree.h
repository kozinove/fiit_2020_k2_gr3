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

	Node* searchMin(Node* root); // поиск минимального элемента
	Node* searchNext(Node* curr); // поиск следующего элемента
	static Node* searchNode(Node* root, int key_); // поиск элемента по ключу

	static void insertNode(Node* root, Node* node);
	void removeNode(Node* z);

	Node* getRoot() const;

	static void print(const Node* root);
	friend ostream& operator<<(ostream& out, const BinaryTree& tree);
};