#pragma once
#include "Node.h"

class BinaryTree
{
private:
	Node* root;
	Node* Min(Node* root);
public:
	BinaryTree(Node* _root = nullptr) : root(_root) {};

	void remove(Node* z);//удаление вершины
	Node* SearchNext(Node* curr);
	Node* SearchMin();
	Node* Search(int _key);
	void insert(Node* node);

	static void print(const Node* root);
	friend ostream& operator<<(ostream& out, const BinaryTree& Tree);
};