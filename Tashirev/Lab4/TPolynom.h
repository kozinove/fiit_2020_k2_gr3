#include"TList.h"
#include<iostream>
#include<string>
#include"TMonom.h"
#include<math.h>

using namespace std;
const int p = 10;

class TPolynom
{
private:
	TList <TMonom> Polynom;
	bool IsFigure(char &c);
	bool IsChar(char &c);
	void CreatePolinom(string str);

public:
	TPolynom();
	TPolynom(string str);
	TPolynom(char *str);
	TPolynom(const TPolynom &p);
	~TPolynom();
	int GetSize() const { return Polynom.GetSize(); }
	void Insert(const int pos, const TMonom &m) { Polynom.InSertInPos(pos, m); }
	TMonom GetMonom(const int pos) const { return Polynom.GetElem(pos); }
	void InSLast(const TMonom &m) { Polynom.InSertLast(m); }
	void SetMonom(const int pos, const TMonom &m) { Polynom.SetElem(pos, m); }
	void BringingSimilar();
	void Sort();

	bool operator==(const TPolynom &p) const;
	bool operator!=(const TPolynom &p) const;
	TPolynom& operator=(const TPolynom &p);

	TPolynom operator*(const TPolynom &p);
	TPolynom operator*(double c);
	TPolynom operator+(const TPolynom &p);
	TPolynom operator-(const TPolynom &p);
	double ComputationAtPoint(const double x, const double y, const double z);
	TPolynom diff();
	TPolynom Integrate();

	string ToString();
	friend ostream& operator<<(ostream &out, TPolynom &p);
};