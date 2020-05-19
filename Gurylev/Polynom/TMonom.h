#pragma once
#include "TList.h"
#include <iostream>

using namespace std;

template<>
class TNode<unsigned int, float>
{
public:
	unsigned int degree;
	float coeff;
	TNode<unsigned int, float>* pNext;
	TNode();
	TNode(const TNode<unsigned int, float>&);
	TNode(unsigned int deg, float coef, TNode<unsigned int, float>* node = NULL);
	~TNode();
	bool operator<(const TNode&) const;
	bool operator!=(const TNode& monom) const;
	bool operator==(const TNode& monom) const;
	TNode<unsigned int, float>* operator*(const TNode<unsigned int, float>& monom);
};

TNode<unsigned int, float>::TNode()
{
	degree = 0;
	coeff = 0;
	pNext = NULL;
}

TNode<unsigned int, float>::TNode(const TNode<unsigned int, float>& n)
{
	degree = n.degree;
	coeff = n.coeff;
	pNext = NULL;
}

TNode<unsigned int, float>::TNode(unsigned int deg, float coef, TNode<unsigned int, float>* node)
{
	degree = deg;
	coeff = coef;
	pNext = node;
}

TNode<unsigned int, float>::~TNode()
{
	degree = 0;
	coeff = 0;
	pNext = NULL;
}

bool TNode<unsigned int, float>::operator <(const TNode& monom) const
{
	return(this->degree < monom.degree);
}

bool TNode<unsigned int, float>::operator!=(const TNode& monom) const
{
	return(this->degree != monom.degree);
}

bool TNode<unsigned int, float>::operator==(const TNode& monom) const
{
	return((this->degree == monom.degree) && (this->coeff == monom.coeff));
}

TNode<unsigned int, float>* TNode<unsigned int, float>::operator*(const TNode<unsigned int, float>& monom)
{
	TNode<unsigned int, float>* result = new TNode<unsigned int, float>();

	unsigned int deg_x1 = monom.degree / 100;
	unsigned int deg_y1 = (monom.degree % 100) / 10;
	unsigned int deg_z1 = monom.degree % 10;

	unsigned int deg_x2 = this->degree / 100;
	unsigned int deg_y2 = (this->degree % 100) / 10;
	unsigned int deg_z2 = this->degree % 10;

	if ((deg_x1 + deg_x2 > 9) || (deg_y1 + deg_y2 > 9) || (deg_z1 + deg_z2 > 9))
		throw "Degree is greater 9";
	result->degree = this->degree + monom.degree;
	result->coeff = this->coeff * monom.coeff;
	return result;
}