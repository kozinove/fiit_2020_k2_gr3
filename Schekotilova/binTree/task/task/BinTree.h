#pragma once
#include <iostream>
#include"treenode.h"
#include <time.h>

class BinTree
{
	treeNode* root;
public:
	BinTree(treeNode* rt = nullptr) : root(rt) {};
	treeNode* getRoot() const;
	static treeNode* search(treeNode*, int);
	treeNode* searchMin(treeNode*);
	treeNode* searchNxt(treeNode*);	
	static void insertNode(treeNode*, treeNode*);
	void deleteNode(treeNode*);
	static void print(const treeNode*);
	friend ostream& operator<<(ostream& out, const BinTree& btree)
	{
		if (btree.root != nullptr) BinTree::print(btree.root);
			return out;
	}
};
