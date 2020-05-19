#pragma once
#include <iostream>

using namespace std;

template<typename TKey, typename TData>
class TNode
{
public:
	TKey key;
	TData pData;
	TNode<TKey, TData>* pNext;
	TNode();
	TNode(TKey, TData, TNode<TKey, TData>*);
	TNode(const TNode<TKey, TData>&);
	~TNode();
};

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode()
{
	key = 0;
	pNext = NULL;
}

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode(TKey key, TData pData, TNode<TKey, TData> * pNext)
{
	this->key = key;
	this->pData = pData;
	pNext = NULL;
}

template<typename TKey, typename TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& node)
{
	this->key = node.key;
	this->pData = node.pData;
	pNext = NULL;
}

template<typename TKey, typename TData>
TNode<TKey, TData>::~TNode()
{
	pNext = NULL;
}
