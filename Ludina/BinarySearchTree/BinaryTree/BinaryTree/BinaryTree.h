#pragma once
#include "Node.h"

class BinaryTree
{
private:
	Node* root;
public:
	BinaryTree(Node* _root = nullptr) : root(_root) {};

	void remove(Node* z);//удаление вершины
	Node* SearchNext(Node* curr);
	Node* SearchMin(Node* root);
	static Node* Search(Node* root, int _key);
	static void insert(Node* root, Node* node);

	Node* getRoot() const { return root; }
	static void print(const Node* root);
	friend ostream& operator<<(ostream& out, const BinaryTree& Tree);
};