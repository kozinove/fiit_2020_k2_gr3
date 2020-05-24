#pragma once
#include "binary.h"
#include <iostream>

using namespace std;

class BinTree
{
private:
	Node* root;
public:
	BinTree(Node* _root = nullptr) : root(_root) {};
	Node* getRoot() const;

	static void insertauto(Node* root, Node* cpy);
	void BinTree::it1();
	//void insertman(Node* root,
	//void remove();
	//Node* search();
};