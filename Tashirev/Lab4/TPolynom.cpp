#include"TPolynom.h"

bool TPolynom::IsFigure(char & c)
{
	if (c >= '0' && c <= '9') return true;
	else return false;
}

bool TPolynom::IsChar(char & c)
{
	if (c >= 'a' && c <= 'z') return true;
	else return false;
}

void TPolynom::CreatePolinom(string str)
{
	TMonom m;
	Polynom.InSertFirst(m);
	int deg;
	int coef = 1;;
	int a, b, c;
	a = b = c = 0;
	int j = 0;
	char fordeg[1];
	char forcoef[8];
	int i = 0;
	bool flag = false;
	while (i < str.length())
	{
		if (i != 0 && str[i - 1] == '-')
		{
			flag = true;
		}
		if (i == 0)
		{
			if (str[0] == '-')
			{
				flag = true;
				i++;
			}
		}
		if (IsFigure(str[i]))
		{
			while (str[i] != 'x' && str[i] != 'y' && str[i] != 'z' && str[i] != '+' && str[i] != '-' && i < str.length())
			{
				forcoef[j++] = str[i];
				i++;
			}
			forcoef[j] = '\0';
			j = 0;
			if (flag == true)
			{
				coef = atoi(forcoef);
				coef *= -1;
				flag = false;
			}
			else
			{
				coef = atoi(forcoef);
				flag = false;
			}
		}
		while (str[i] != '-' && str[i] != '+' && i < str.length())
		{
			if (str[i] == 'x')
			{
				if (IsFigure(str[i + 1]))
				{
					fordeg[0] = str[i + 1];
					a = atoi(fordeg);
					i += 2;

				}
				else
				{
					a = 1;
					i++;
				}
			}

			if (str[i] == 'y')
			{
				if (IsFigure(str[i + 1]))
				{
					fordeg[0] = str[i + 1];
					b = atoi(fordeg);
					i += 2;
				}
				else
				{
					b = 1;
					i++;
				}
			}
			if (str[i] == 'z')
			{
				if (IsFigure(str[i + 1]))
				{
					fordeg[0] = str[i + 1];
					c = atoi(fordeg);
					i += 2;
				}
				else
				{
					c = 1;
					i++;
				}
			}
		}
		deg = a * p*p + b * p + c;
		a = b = c = 0;
		if (flag == true)
		{
			coef *= -1;
			flag = false;
		}
		TMonom m(deg, coef);
		if (coef != 0) Polynom.InSertLast(m);
		coef = 1;
		i++;
	}
	Sort();//сортировка
	BringingSimilar();//приведение подобных
}


TPolynom::TPolynom()
{
	TMonom m;
	Polynom.InSertFirst(m);
}

TPolynom::TPolynom(string str)
{
	CreatePolinom(str);
}

TPolynom::TPolynom(char *str)
{
	string stroka = string(str);
	CreatePolinom(stroka);
}

TPolynom::TPolynom(const TPolynom & p)
{
	for (int i = 0; i < p.GetSize(); i++)
	{
		Polynom.InSertLast(p.GetMonom(i));
	}
}

TPolynom::~TPolynom()
{
	Polynom.DeleteAll();
}

void TPolynom::BringingSimilar()
{
	for (int i = 1; i < Polynom.GetSize(); i++)
	{
		for (int j = 2; j < Polynom.GetSize(); j++)
		{
			if (Polynom.GetElem(i).GetDeg() == Polynom.GetElem(j).GetDeg() && (i != j))
			{
				Polynom.SetElem(i, Polynom.GetElem(i) + Polynom.GetElem(j));
				Polynom.Delete(j);
				j--;
			}
		}
		if(Polynom.GetElem(i).GetCoef()==0)
		{
			Polynom.Delete(i);
			i = 0;
			continue;
		}
	}
	Sort();
	bool fl = false;
	for (int i = 2; i < Polynom.GetSize(); i++)
	{
		if (Polynom.GetElem(i - 1).GetDeg() == Polynom.GetElem(i).GetDeg())
		{
			Polynom.SetElem(i - 1, Polynom.GetElem(i - 1) + Polynom.GetElem(i));
			Polynom.Delete(i);
			fl = true;
		}
		if (Polynom.GetElem(i - 1).GetCoef() == 0)
			Polynom.Delete(i - 1);
		if (fl) i = i - 1;
		fl = false;
	}
}

void TPolynom::Sort()
{
	TMonom tmp_one;
	TMonom tmp_two;
	for (int i = 1; i < Polynom.GetSize() - 1; i++)
	{
		for (int j = 1; j < Polynom.GetSize() - 1; j++)
		{
			tmp_one = Polynom.GetElem(j + 1);
			if (Polynom.GetElem(j).GetDeg() < Polynom.GetElem(j + 1).GetDeg())
			{
				tmp_two = Polynom.GetElem(j);
				Polynom.SetElem(j, tmp_one);
				Polynom.SetElem(j + 1, tmp_two);
			}
		}
	}
}

bool TPolynom::operator==(const TPolynom & p) const
{
	if (Polynom.GetSize() != p.GetSize()) return false;
	for (int i = 1; i < Polynom.GetSize(); i++)
	{
		if (Polynom.GetElem(i) != p.GetMonom(i))
		{
			return false;
		}
	}
	return true;
}

bool TPolynom::operator!=(const TPolynom & p) const
{
	if (*this == p) return false;
	else return true;
}

TPolynom & TPolynom::operator=(const TPolynom & p)
{
	Polynom.DeleteAll();
	for (int i = 0; i < p.GetSize(); i++)
	{
		Polynom.InSertLast(p.GetMonom(i));
	}
	return *this;
}

TPolynom TPolynom::operator*(const TPolynom & p)
{
	TPolynom res;
	TMonom tmp;
	for (int i = 1; i < Polynom.GetSize(); i++)
	{
		for (int j = 1; j < p.GetSize(); j++)
		{
			tmp = Polynom.GetElem(i)*p.GetMonom(j);
			res.InSLast(tmp);
		}
	}
	res.Sort();
	res.BringingSimilar();
	return res;
}

TPolynom TPolynom::operator*(double c)
{
	TPolynom res;
	int deg;
	double coef;
	for (int i = 1; i < Polynom.GetSize(); i++)
	{
		deg = Polynom.GetElem(i).GetDeg();
		coef = Polynom.GetElem(i).GetCoef();
		TMonom tmp(deg, coef*c);
		res.InSLast(tmp);
	}
	return res;
}

TPolynom TPolynom::operator+(const TPolynom  &p)
{
	TPolynom res;
	int j = 1;
	for (int i = 1; i < Polynom.GetSize(); i++)
	{
		if (j < p.GetSize())
		{
			if (Polynom.GetElem(i).GetDeg() == p.GetMonom(j).GetDeg())
			{
				if (Polynom.GetElem(i).GetCoef() + p.GetMonom(j).GetCoef() != 0)
				{
					res.InSLast(Polynom.GetElem(i) + p.GetMonom(j));
				}
				j++;
			}
			else
			{
				res.InSLast(Polynom.GetElem(i));
				res.InSLast(p.GetMonom(j));
				j++;
			}
		}
		else
		{
			res.InSLast(Polynom.GetElem(i));
		}
	}
	while (j < p.GetSize())
		res.InSLast(p.GetMonom(j++));
	if (res.Polynom.GetSize() > 2)
	{
		res.Sort();
		res.BringingSimilar();
	}
	return res;
}

TPolynom TPolynom::operator-(const TPolynom & p)
{
	TPolynom res(p);
	return *this + (res*(-1));
}

double TPolynom::ComputationAtPoint(const double x, const double y, const double z)
{
	double res = 0;
	int a, b, c, coef, tmp;
	a = b = c = 0;
	for (int i = 1; i < Polynom.GetSize(); i++)
	{
		coef = Polynom.GetElem(i).GetCoef();
		tmp = Polynom.GetElem(i).GetDeg();
		a = tmp / 100;
		b = (tmp - a * 100) / 10;
		c = tmp - a * 100 - b * 10;
		res = res + coef * powl(x, a)*powl(y, b)*powl(z, c);
	}
	return res;
}

TPolynom TPolynom::diff()
{
	TPolynom res;
	TMonom m;
	int tmp_d, tmp_c, a, b, c, deg, coef;
	for (int i = 1; i < Polynom.GetSize(); i++)
	{
		tmp_d = Polynom.GetElem(i).GetDeg();
		a = tmp_d / 100;
		b = (tmp_d - a * 100) / 10;
		c = tmp_d - a * 100 - b * 10;
		tmp_c = Polynom.GetElem(i).GetCoef();
		//diff on x
		if (a > 0)
		{
			deg = (a - 1)*p*p + b * p + c;
			coef = tmp_c * a;
			m.SetCoef(coef);
			m.SetDeg(deg);
			res.InSLast(m);
		}
		//diff on y
		if (b > 0)
		{
			deg = a * p*p + (b - 1)*p + c;
			coef = tmp_c * b;
			m.SetCoef(coef);
			m.SetDeg(deg);
			res.InSLast(m);
		}
		//diff on z
		if (c > 0)
		{
			deg = a * p*p + b * p + (c - 1);
			coef = tmp_c * c;
			m.SetCoef(coef);
			m.SetDeg(deg);
			res.InSLast(m);
		}
	}
	res.BringingSimilar();
	return res;
}

TPolynom TPolynom::Integrate()
{
	return *this;
}

string TPolynom::ToString()
{
	string str;
	TMonom m;
	int a, b, c, tmp;
	a = b = c = 0;
	if (Polynom.GetSize() > 1)
	{
		for (int i = 1; i < Polynom.GetSize(); i++)
		{
			m = Polynom.GetElem(i);
			tmp = m.GetDeg();
			if (i != 1 && m.GetCoef() > 0)
				str.push_back('+');
			if (m.GetCoef() == -1 || m.GetCoef() == 1)
			{
				if (m.GetCoef() < 0)
					str.push_back('-');
			}
			else 	str = str + to_string((int)m.GetCoef());
			a = tmp / 100;
			b = (tmp - a * 100) / 10;
			c = tmp - a * 100 - b * 10;
			if (a > 0)
			{
				str.push_back('x');
				if (a > 1) str = str + to_string(a);
			}
			if (b > 0)
			{
				str.push_back('y');
				if (b > 1) str = str + to_string(b);
			}
			if (c > 0)
			{
				str.push_back('z');
				if (c > 1) str = str + to_string(c);
			}
		}
	}
	else
	{
		str = to_string(0);
	}
	return str;
}

ostream & operator<<(ostream & out, TPolynom & p)
{
	string res;
	res = p.ToString();
	out << res;
	return out;
}
