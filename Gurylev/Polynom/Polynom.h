#pragma once
#include "TMonom.h"
#include <string>

using namespace std;

class Polynom
{
private:
	TList<unsigned int, float>* polynom;
public:
	Polynom();
	Polynom(const string& str);
	Polynom(const Polynom& tmp); 
	Polynom(TList<unsigned int, float>* list);
	~Polynom();
	void SortPol();
	void Simplific();
	Polynom operator+(const Polynom&);
	Polynom operator-(const Polynom&);
	Polynom operator*(const Polynom&);
	bool operator==(const Polynom&) const;
	const Polynom& operator=(const Polynom&);
	Polynom operator-() const; 
	Polynom operator*(const TNode<unsigned int, float>& monom);
	friend ostream& operator<<(ostream& out, const Polynom& pol);
};

Polynom::Polynom()
{
	polynom = new TList<unsigned int, float>();
}

Polynom::Polynom(const string& str)
{
	polynom = new TList<unsigned int, float>();
	string s = str;
	float coeff = 1;
	int degree = 0;
	int i = 0;
	bool is_x = false;
	bool is_y = false;
	bool is_z = false;
	while (i < s.length())
	{
		do
		{
			if (s[i] == '^')
			{
				i++;
				continue;
			}
			if (isdigit(s[i]) && !is_x && !is_y && !is_z)
			{
				string c;
				while (isdigit(s[i]))
				{
					if (s[i + 1] == '.')
					{
						c += s[i];
						c += s[i + 1];
						i = i + 2;
					}
					else
					{
						c += s[i];
						i++;
					}
				}
				coeff *= (float)(atof(c.c_str()));
				continue;
			}
			if (s[i] == 'x')
			{
				i++;
				is_x = true;
				is_y = false;
				is_z = false;
			}
			if ((is_x == true) && ((s[i] == 'y') || (s[i] == 'z') || (s[i] == ' ')))
			{
				is_x = false;
				degree += 100;
			}
			if ((is_x == true) && (isdigit(s[i])))
			{
				if (isdigit(s[i + 1]))
					throw "The degree must not exceed 9";
				degree += ((int)s[i] - 48) * 100;
				is_x = false;
				i++;
				continue;
			}
			if (((i + 1) == s.length()) && (is_x == true))
			{
				is_x = false;
				degree += 100;
				i++;
			}
			if (s[i] == 'y')
			{
				i++;
				is_x = false;
				is_y = true;
				is_z = false;
			}
			if ((is_y == true) && ((s[i] == 'x') || (s[i] == 'z') || (s[i] == ' ')))
			{
				is_y = false;
				degree += 10;
			}
			if ((is_y == true) && (isdigit(s[i])))
			{
				if (isdigit(s[i + 1]))
					throw "The degree must not exceed 9";
				degree += ((int)s[i] - 48) * 10;
				is_y = false;
				i++;
				continue;
			}
			if (((i + 1) == s.length()) && (is_y == true))
			{
				is_y = false;
				degree += 10;
				i++;
			}
			if (s[i] == 'z')
			{
				i++;
				is_x = false;
				is_y = false;
				is_z = true;
			}
			if (((i + 1) == s.length()) && (is_z == true))
			{
				is_z = false;
				degree += 1;
				i++;
				continue;
			}
			if ((is_z == true) && !(isdigit(s[i])))
			{
				is_z = false;
				degree += 1;
			}
			if ((is_z == true) && (isdigit(s[i])))
			{
				if (isdigit(s[i + 1]))
					throw "The degree must not exceed 9";
				degree += ((int)s[i] - 48);
				is_z = false;
				i++;
				continue;
			}
			if ((s[i] == ' ') && (is_z == true))
			{
				is_z = false;
				degree += 1;
			}
			if (s[i] == '+')
			{
				i++;
				continue;
			}
			if (s[i] == '-')
			{
				i++;
				coeff *= (-1);
				continue;
			}
			if (s[i] == ' ')
			{
				i++;
				continue;
			}
		} while (!((s[i] == '+') || (s[i] == '-')) && (i != s.length()) && (!is_x || !is_y || !is_z));
		polynom->InsertEnd(degree, coeff);
		coeff = 1;
		degree = 0;
	}
	Simplific();
	SortPol();
}

Polynom::Polynom(const Polynom& tmp)
{
	polynom = new TList<unsigned int, float>(*tmp.polynom);
}

Polynom::Polynom(TList<unsigned int, float>* list)
{
	list->Reset();
	while (!list->IsEnded())
	{
		if (list->GetCurrent()->degree > 999 || list->GetCurrent()->degree < 0)
			throw"One of polynom's degree is wrong";
		list->Next();
	}
	polynom = new TList<unsigned int, float>(*list);
	Simplific();
	SortPol();
}

Polynom::~Polynom()
{
	delete polynom;
}

Polynom Polynom::operator+(const Polynom& pol)
{
	if (polynom->IsEmpty())
		return pol;
	if (pol.polynom->IsEmpty())
		return (*this);
	Polynom result;
	pol.polynom->Reset();
	polynom->Reset();
	while ((!pol.polynom->IsEnded()) && (!polynom->IsEnded()))
	{
		if (polynom->GetCurrent()->degree < pol.polynom->GetCurrent()->degree)
		{
			result.polynom->InsertEnd(polynom->GetCurrent()->degree, polynom->GetCurrent()->coeff);
			polynom->Next();
		}
		else if (polynom->GetCurrent()->degree > pol.polynom->GetCurrent()->degree)
		{
			result.polynom->InsertEnd(pol.polynom->GetCurrent()->degree, pol.polynom->GetCurrent()->coeff);
			pol.polynom->Next();
		}
		else
		{
			if ((polynom->GetCurrent()->coeff + pol.polynom->GetCurrent()->coeff) != 0)
			{
				result.polynom->InsertEnd(polynom->GetCurrent()->degree, polynom->GetCurrent()->coeff + pol.polynom->GetCurrent()->coeff);
			}
			polynom->Next();
			pol.polynom->Next();
		}
	}
	while (!polynom->IsEnded())
	{
		result.polynom->InsertEnd(polynom->GetCurrent()->degree, polynom->GetCurrent()->coeff);
		polynom->Next();
	}
	while (!pol.polynom->IsEnded())
	{
		result.polynom->InsertEnd(pol.polynom->GetCurrent()->degree, pol.polynom->GetCurrent()->coeff);
		pol.polynom->Next();
	}
	result.polynom->Reset();
	result.SortPol();
	result.Simplific();
	return result;
}

Polynom Polynom::operator-() const
{
	Polynom result(*this);
	while (!result.polynom->IsEnded())
	{
		result.polynom->GetCurrent()->coeff *= -1;
		result.polynom->Next();
	}
	result.polynom->Reset();
	return result;
}

Polynom Polynom::operator-(const Polynom& pol)
{
	return *this + (-pol);
}

Polynom  Polynom::operator*(const TNode<unsigned int, float>& monom)
{
	if (monom.coeff == 0)
		return polynom;
	Polynom result;
	TNode<unsigned int, float>* mon = new TNode<unsigned int, float>(monom);
	while (!polynom->IsEnded())
	{
		result.polynom->InsertEnd(polynom->GetCurrent()->degree, mon->coeff * polynom->GetCurrent()->coeff);
		polynom->Next();
	}
	Simplific();
	SortPol();
	return result;
}

Polynom Polynom::operator*(const Polynom& pol)
{
	Polynom result;
	polynom->Reset();
	while (!polynom->IsEnded())
	{
		pol.polynom->Reset();
		while (!pol.polynom->IsEnded())
		{
			TNode<unsigned int, float>* res;
			res = *polynom->GetCurrent() * *pol.polynom->GetCurrent();
			result.polynom->InsertEnd(res->degree, res->coeff);
			pol.polynom->Next();
		}
		polynom->Next();
	}
	result.Simplific();
	result.SortPol();
	return result;
}

bool Polynom::operator==(const Polynom& pol) const
{
	while (!pol.polynom->IsEnded() || !polynom->IsEnded())
	{
		if (polynom->GetCurrent() != pol.polynom->GetCurrent())
			return false;
	}
	if (!pol.polynom->IsEnded() || !polynom->IsEnded())
		return false;
	else
		return true;
}

const Polynom& Polynom::operator=(const Polynom& pol)
{
	if (*this == pol)
		return *this;
	if (!polynom->IsEnded())
	{
		delete polynom;
	}
	polynom = new TList<unsigned int, float>(*pol.polynom);
	return *this;
}

void Polynom::SortPol()
{
	if ((polynom->GetFirst() == nullptr) || (polynom->GetFirst()->pNext == nullptr))
		return;
	polynom->Reset();
	TNode<unsigned int, float>* node = polynom->GetFirst();
	TNode<unsigned int, float>* node_1 = polynom->GetFirst()->pNext;
	TNode<unsigned int, float>* prev_node = polynom->GetFirst(), * tmp;
	while (node->pNext != nullptr)
	{
		while (node_1 != nullptr)
		{
			if (node->degree < node_1->degree)
			{
				if (prev_node == node)
					polynom->pFirst = node_1;
				else
					prev_node->pNext = node_1;
				node->pNext = node_1->pNext;
				node_1->pNext = node;
				tmp = node;
				node = node_1;
				node_1 = tmp;
			}
			prev_node = node;
			node = node->pNext;
			node_1 = node_1->pNext;
		}
	}
}

void Polynom::Simplific()
{
	polynom->Reset();
	if (polynom->GetCurrent() == nullptr)
		return;
	while (!polynom->IsEnded())
	{
		TNode<unsigned int, float>* tmp = polynom->GetFirst();
		TNode<unsigned int, float>* tmp_1 = polynom->GetCurrent();
		while (tmp->degree != tmp_1->degree)
			tmp = tmp->pNext;
		if (tmp == tmp_1)
		{
			polynom->Next();
			continue;
		}
		polynom->GetCurrent()->coeff += tmp->coeff;
		polynom->Remove(tmp->degree);
		polynom->Next();
	}
	polynom->Reset();
}

ostream& operator<<(ostream& out, const Polynom& pol)
{
	unsigned int deg;
	float coef;
	pol.polynom->Reset();
	if (pol.polynom->IsEnded())
	{
		out << "0";
		return out;
	}
	while (!pol.polynom->IsEnded())
	{
		deg = pol.polynom->GetCurrent()->degree;
		coef = pol.polynom->GetCurrent()->coeff;
		int is_x = deg / 100;
		int deg_y = (deg % 100) / 10;
		int deg_z = deg % 10;
		if (coef == 0)
		{
			pol.polynom->Next();
			continue;
		}
		else
		{
			if (coef != 1 && coef != -1)
			{
				if (coef > 0)
					out << "+" << coef;
				if (coef < 0)
					out << coef;
			}
			if (coef == -1)
				out << "-";
			if (coef == 1)
				out << "+";
			if (is_x == 1)
				out << "x";
			if (deg_y == 1)
				out << "y";
			if (deg_z == 1)
				out << "z";
			if (is_x > 0 && is_x != 1)
				out << "x^" << is_x;
			if (deg_y > 0 && deg_y != 1)
				out << "y^" << deg_y;
			if (deg_z > 0 && deg_z != 1)
				out << "z^" << deg_z;
		}
		pol.polynom->Next();
	}
	return out;
}