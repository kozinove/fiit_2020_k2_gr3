#pragma once
#pragma once
#include <iostream>
#include <string.h>

using namespace std;

template<class ValueType>
class TStack
{
private:
	ValueType* elems;
	int size;
	int top;
public:
	TStack(int size);
	TStack(const TStack& c);
	~TStack();
	bool IsEmpty() const;
	bool IsFull() const;
	void Push(ValueType c);
	ValueType Pop();
	ValueType getTop() const;
};

template <class ValueType>
TStack <ValueType>::TStack(int size)
{
	this->size = size;
	this->top = -1;
	elems = new ValueType[size];
}

template <class ValueType>
TStack<ValueType>::TStack(const TStack<ValueType>& s)
{
	this->size = s.size;
	this->top = s.top;
	for (int i; i, top; i++)
		elems[i] = s.elems[i];
}

template<typename ValueType>
TStack<ValueType>::~TStack()
{
	top = 0;
	size = 0;
	delete[] elems;
}

template <class ValueType>
bool TStack <ValueType>::IsEmpty() const
{
	return (top == -1);
}

template <class ValueType>
bool TStack <ValueType>::IsFull() const
{
	return (top == size - 1);
}

template <class ValueType>
void TStack <ValueType>::Push(ValueType c)
{
	if (IsFull())
		throw "error";
	elems[++top] = c;
}

template <class ValueType>
ValueType TStack<ValueType>::Pop()
{
	if (IsEmpty())
		throw "error";
	return elems[top--];
}

template <class ValueType>
ValueType TStack<ValueType>::getTop() const
{
	return elems[top];
}