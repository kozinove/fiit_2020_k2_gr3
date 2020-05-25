#pragma once
#include <iostream>

using namespace std;

class treenode
{
public:
	int key;
	treenode* left, * right, * parent;

	treenode();
	//treenode(int);
	treenode(const treenode&);
	treenode(int, treenode *, treenode*,treenode*);
	~treenode() { left = nullptr; right = nullptr; }
	
	void setL(treenode*);
	void setR(treenode*);
	void setPrnt(treenode*);
	treenode* getL() const;
	treenode* getR() const;
	treenode* getPrnt() const;
	friend ostream& operator<<(ostream& out, const treenode& root)
	{
		out << " " << root.key << "	";
		return out;
	}
};

treenode::treenode()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
};

//treenode::treenode(int key)
//{
//	this->key = key;
//	left = nullptr;
//	right = nullptr;
//	parent = nullptr;
//};

treenode::treenode(const treenode& n)
{
	key = n.key;
	left = n.left;
	right = n.right;
	parent = n.parent;
};

treenode::treenode(int key = 0, treenode * left = nullptr, treenode * right = nullptr, treenode * parent = nullptr)
{
	this->key = key;
	this->left = left;
	this->right = right;
	this->parent = parent;
}

treenode* treenode::getR() const
{
	return right;
};

treenode* treenode::getPrnt() const
{
	return parent;
};

void treenode::setL(treenode* left)
{
	this->left = left;
};

void treenode::setR(treenode* right)
{
	this->right = right;
};

void treenode::setPrnt(treenode* parent)
{
	this->parent = parent;
};