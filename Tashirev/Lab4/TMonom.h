const int MAX_DEG = 999;

class TMonom
{
private:
	int coef;
	int deg;
public:
	TMonom(int d, int c);
	TMonom();
	TMonom(const TMonom &m);
	int GetDeg() { return deg; }
	int GetCoef() { return coef; }
	void SetDeg(int d) { deg = d; }
	void SetCoef(int c) { coef = c; }
	TMonom operator+(const TMonom &m);
	TMonom operator*(double c);
	TMonom& operator=(const TMonom &m);
	TMonom operator-(const TMonom &m);
	TMonom operator*(const TMonom &m);

	bool operator==(const TMonom &m) const;
	bool operator!=(const TMonom &m) const;
};