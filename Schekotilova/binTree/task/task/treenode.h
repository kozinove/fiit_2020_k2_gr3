#pragma once
#include <iostream>

using namespace std;

struct treeNode
{
	int key;
	treeNode *left, *right, *parent;

	treeNode();
	treeNode(int key);
	treeNode(const treeNode& node);
	~treeNode() { left = nullptr; right = nullptr; }

	treeNode* getL() const;
	treeNode* getR() const;
	treeNode* getPrnt() const;

	void setL(treeNode*);
	void setR(treeNode*);
	void setPrnt(treeNode*);

	friend ostream& operator<<(ostream& out, const treeNode& root)
	{
		out << " " << root.key << "	";
		return out;
	}
};

treeNode::treeNode()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
};
treeNode::treeNode(int key)
{
	this->key = key;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
};

treeNode::treeNode(const treeNode& n)
{
	key = n.key;
	left = n.left;
	right = n.right;
	parent = n.parent;
};

treeNode* treeNode::getR() const
{
	return right;
};

treeNode* treeNode::getPrnt() const
{
	return parent;
};

void treeNode::setL(treeNode* left)
{
	this->left = left;
};

void treeNode::setR(treeNode* right)
{
	this->right = right;
};

void treeNode::setPrnt(treeNode* parent)
{
	this->parent = parent;
};
