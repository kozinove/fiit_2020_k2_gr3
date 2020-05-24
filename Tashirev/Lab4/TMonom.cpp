#include"TMonom.h"

TMonom::TMonom(int d, int c)
{
	if (d < -1 || d > MAX_DEG) throw("Incorrect deg");
	deg = d;
	coef = c;
}

TMonom::TMonom()
{
	deg = -1;
	coef = 0;
}

TMonom::TMonom(const TMonom & m)
{
	deg = m.deg;
	coef = m.coef;
}

TMonom TMonom::operator+(const TMonom & m)
{
	if (deg == -1 || m.deg == -1) return *this;
	if (deg != m.deg) throw("different degs in operation add");

	TMonom tmp;
	tmp.coef = coef + m.coef;
	tmp.deg = deg;

	return tmp;
}

TMonom TMonom::operator*(double c)
{
	if (deg == -1)  throw("Error.zero monomial");
	TMonom tmp;
	tmp.deg = deg;
	tmp.coef = coef * c;
	return tmp;
}


TMonom& TMonom::operator=(const TMonom & m)
{
	deg = m.deg;
	coef = m.coef;
	return *this;
}

TMonom TMonom::operator-(const TMonom & m)
{
	if (deg == -1 || m.deg == -1) return *this;
	if (deg != m.deg) throw("different degs in operation add");

	TMonom tmp;
	tmp.coef = coef - m.coef;
	tmp.deg = deg;

	return tmp;
}

TMonom TMonom::operator*(const TMonom & m)
{
	TMonom tmp;
	tmp.deg = deg + m.deg;
	tmp.coef = coef * m.coef;
	if (tmp.deg > MAX_DEG) throw("This is big deg");
	return tmp;
}

bool TMonom::operator==(const TMonom & m) const
{
	return (deg == m.deg && coef == m.coef);
}

bool TMonom::operator!=(const TMonom & m) const
{
	if (*this == m) return false;
	else return false;
}