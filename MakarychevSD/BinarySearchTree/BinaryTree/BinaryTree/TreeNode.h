#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;

template <class TData>
class TreeNode
{
private:
	int key;
	TData* pData;
	TreeNode<TData>* pLeft;
	TreeNode<TData>* pRight;
	TreeNode<TData>* pParent;
public:
	TreeNode<TData>(int key = 0, TData* pData = nullptr, TreeNode<TData>* pLeft = nullptr, TreeNode<TData>* pRight = nullptr,
		TreeNode<TData>* pParent = nullptr);
	TreeNode<TData>(const TreeNode<TData>& copyNode);
	~TreeNode<TData>() {};

	TreeNode<TData>* GetLeft()const;
	TreeNode<TData>* GetRight()const;
	TreeNode<TData>* GetParent()const;
	TData* GetData()const { return pData; };
	int GetKey()const { return key; };

	void SetLeft(TreeNode<TData>* _pLeft) { pLeft = _pLeft; };
	void SetRight(TreeNode<TData>* _pRight) { pRight = _pRight; };
	void SetParent(TreeNode<TData>* _pParent) { pParent= _pParent; };
	void SetKey(int _key) { key = _key; };
	void SetData(TData* _pData) { pData = _pData; };

	friend ostream& operator <<(ostream& out, const TreeNode& T)
	{
		out << "key = " << T.key << endl;
		return out;
	};
};

template<class TData>
TreeNode<TData> ::TreeNode(int key, TData* pData, TreeNode<TData>* pLeft, TreeNode<TData>* pRight,
	TreeNode<TData>* pParent)
{
	this->key = key;
	this->pData = pData;
	this->pLeft = pLeft;
	this->pRight = pRight;
	this->pParent = pParent;
}

template <class TData>
TreeNode<TData> ::TreeNode(const TreeNode<TData>& copyNode)
{
	key = copyNode->key;
	pData = copyNode->pData;
	pLeft = copyNode->pLeft;
	pRight = copyNode->pRight;
	pParent = copyNode->pParent;
}

template <class TData>
TreeNode<TData>* TreeNode<TData>::GetLeft()const
{
	return pLeft;
}

template <class TData>
TreeNode<TData>* TreeNode<TData>::GetRight()const
{
	return pRight;
}

template <class TData>
TreeNode<TData>* TreeNode<TData>::GetParent()const
{
	return pParent;
}

#endif
