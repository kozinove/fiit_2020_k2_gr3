#pragma once
#include "TNode.h"
#include <iostream>

using namespace std;

template<class TKey, class TData>
class TList
{
public:
	TNode<TKey, TData>* pFirst; // Указатель на начало списка
	TNode<TKey, TData>* pCurrent;
	TNode<TKey, TData>* pPrevious;
	TNode<TKey, TData>* pNext;
	TList(); // Создает пустой список
	TList(const TList&); // Копирует содержимое создаваемого списка в пустой список
	TList(TNode<TKey, TData>* node); // Копирует укзаатель на первый элмент списка
	~TList(); // Последователно удаляет элементы списка
	TNode<TKey, TData>* Search(TKey); // Поиск по ключу
	void InsertBegin(TKey, TData);
	void InsertEnd(TKey, TData);
	void InsertAfter(TKey, TNode<TKey, TData>*);
	void InsertBefore(TKey, TNode<TKey, TData>*);
	void Remove(TKey); // Удаляет элменты с заданным ключом
	bool IsEmpty() const;
	bool IsEnded() const;
	void Reset();
	void Next(); // Передвигает указатель на след элемент
	TNode<TKey, TData>* GetFirst() const;
	TNode<TKey, TData>* GetCurrent() const;
	TNode<TKey, TData>* GetNext() const;
	TNode<TKey, TData>* GetPrevious() const;
};

template<typename TKey, typename TData>
TList<TKey, TData>::TList()
{
	pFirst = NULL;
	pPrevious = NULL;
	pCurrent = NULL;
	pNext = NULL;
}

template<typename TKey, typename TData>
TList<TKey, TData>::TList(const TList<TKey, TData>& list)
{
	pCurrent = NULL;
	pPrevious = NULL;
	pNext = NULL;
	if (!list.pFirst)
	{
		pFirst = NULL;
	}
	else
	{
		pFirst = new TNode<TKey, TData>(*list.pFirst);
		TNode<TKey, TData>* node = pFirst;
		TNode<TKey, TData>* tmp = list.pFirst;
		while (tmp->pNext != NULL)
		{
			node->pNext = new TNode<TKey, TData>(*(tmp->pNext));
			node = node->pNext;
			tmp = tmp->pNext;
		}
		Reset();
	}
}

template<typename TKey, typename TData>
TList<TKey, TData>::TList(TNode<TKey, TData>* node)
{
	pCurrent = NULL;
	pPrevious = NULL;
	pNext = NULL;
	if (node == NULL)
		pFirst == NULL;
	else
	{
		pFirst = new TNode<TKey, TData>(*node);
		TNode<TKey, TData>* node1 = pFirst;
		TNode<TKey, TData>* tmp = node->pNext;
		while (tmp->pNext != NULL)
		{
			node1->pNext = new TNode<TKey, TData>(*(tmp->pNext));
			node1 = node1->pNext;
			tmp = tmp->pNext;
		}
		Reset();
	}
}

template<typename TKey, typename TData>
TList<TKey, TData>::~TList()
{
	pCurrent = NULL;
	pPrevious = NULL;
	pNext = NULL;
	while (!IsEnded())
	{
		pNext = pFirst->pNext;
		delete pFirst;
		pFirst = pNext;
	}
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::Search(TKey key)
{
	if (pFirst == NULL)
		throw "List is empty";
	TNode<TKey, TData>* tmp = pFirst;
	while ((tmp != NULL) && (tmp->degree != key))
		tmp = tmp->pNext;
	if (tmp == NULL)
		cout << "The key does not exist";
	return tmp;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertBegin(TKey key, TData data)
{
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(key, data);
	tmp->pNext = pFirst;
	if (pCurrent == pFirst)
		pPrevious = tmp;
	pFirst = tmp;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertEnd(TKey key, TData data)
{
	if (pFirst == NULL)
	{
		InsertBegin(key, data);
		return;
	}
	TNode<TKey, TData>* new_node = new TNode<TKey, TData>(key, data);
	TNode<TKey, TData>* tmp = pFirst;
	while (tmp->pNext != NULL)
		tmp = tmp->pNext;
	tmp->pNext = new_node;
	if (pCurrent == tmp)
		pNext = new_node;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertAfter(TKey key, TNode<TKey, TData>* node)
{
	if (pFirst == NULL)
		throw "List is empty";
	TNode<TKey, TData>* prev = pPrevious;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurrent;
	Reset();
	TNode<TKey, TData>* tmp = Search(key);
	if (tmp == NULL)
		throw "The key does not exist";
	while (pCurrent != tmp)
		Next();
	TNode<TKey, TData>* node_1 = new TNode<TKey, TData>(node->key, node->pData);
	pCurrent->pNext = node_1;
	if (curr == pCurrent)
		pNext = node_1;
	else
		pNext = next;
	if (curr == pNext)
		pPrevious = node_1;
	else
		pPrevious = prev;
	pCurrent = curr;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::InsertBefore(TKey key, TNode<TKey, TData>* node)
{
	if (pFirst == NULL)
		throw "List is empty";
	if (pFirst->key == key)
	{
		InsertBegin(node->key, node->pData);
		return;
	}
	TNode<TKey, TData>* prev = pPrevious;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurrent;
	Reset();
	TNode<TKey, TData>* tmp = Search(key);
	if (tmp == NULL)
		throw "The key does not exist";
	while (pCurrent != tmp)
		Next();
	TNode<TKey, TData>* node_1 = new TNode<TKey, TData>(node->key, node->pData);
	pPrevious->pNext = node_1;
	if (curr == pCurrent)
		pPrevious = node_1;
	else
		pPrevious = prev;
	if (curr == pPrevious)
		pNext = node_1;
	else
		pNext = next;
	pCurrent = curr;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Remove(TKey key)
{
	if (pFirst == NULL)
		throw "List is empty";
	if (pFirst->degree == key)
	{
		if (pCurrent == pFirst)
		{
			pCurrent = pNext;
			if (pNext != NULL)
				pNext = pNext->pNext;
			else
				pNext = NULL;
			delete pFirst;
			return;
		}
		if (pCurrent == pFirst->pNext)
		{
			pPrevious = NULL;
			delete pFirst;
			pFirst = pCurrent;
			return;
		}
	}
	TNode<TKey, TData>* prev = pPrevious;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurrent;
	Reset();
	TNode<TKey, TData>* tmp = Search(key);
	if (tmp == NULL)
		throw "The key does not exist";
	while (pCurrent != tmp)
		Next();
	pPrevious->pNext = pNext;
	if (curr == pCurrent)
	{
		pCurrent = pNext;
		pNext = pCurrent->pNext;
		delete tmp;
		return;
	}
	if (curr == pNext)
	{
		pCurrent = pNext;
		pNext = pCurrent->pNext;
		delete tmp;
		return;
	}
	if (curr == pPrevious)
	{
		pCurrent = pPrevious;
		pPrevious = prev;
		pNext = pCurrent->pNext;
		delete tmp;
		return;
	}
	pNext = next;
	pCurrent = curr;
	delete tmp;
	return;
}

template<typename TKey, typename TData>
bool TList<TKey, TData>::IsEmpty() const
{
	return (pFirst == NULL);
}

template<typename TKey, typename TData>
bool TList<TKey, TData>::IsEnded() const
{
	return (pCurrent == NULL);
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Reset()
{
	pCurrent = pFirst;
	pPrevious = NULL;
	if (pFirst != NULL)
		pNext = pCurrent->pNext;
	else
		pNext = NULL;
}

template<typename TKey, typename TData>
void TList<TKey, TData>::Next()
{
	if (IsEnded())
		throw "List is ended";
	pPrevious = pCurrent;
	pCurrent = pNext;
	if (pNext != NULL)
		pNext = pNext->pNext;
	else
		pNext = NULL;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::GetFirst() const
{
	return pFirst;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData>::GetCurrent() const
{
	return pCurrent;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetNext()const
{
	return pNext;
}

template<typename TKey, typename TData>
TNode<TKey, TData>* TList<TKey, TData> ::GetPrevious()const
{
	return  pPrevious;
}