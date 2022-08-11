#pragma once
#pragma pack(1)
#include "Exception.h"
#include "InheritedException.h"

class FuzzyNumber
{
private:
	double x, l, r;
public:
	FuzzyNumber();
	FuzzyNumber(double x, double l, double r) throw(logic_error);
	FuzzyNumber(const FuzzyNumber& v);

	double get_x() const { return x; }
	double get_l() const { return l; }
	double get_r() const { return r; }

	void set_x(double value) { x = value; }
	void set_l(double value) { l = value; }
	void set_r(double value) { r = value; }

	FuzzyNumber& operator = (const FuzzyNumber& n);
	operator string() const;

	FuzzyNumber& operator --() throw (InheritedException);
	FuzzyNumber& operator ++() throw (Exception);
	FuzzyNumber operator --(int) throw (InheritedException);
	FuzzyNumber operator ++(int) throw (logic_error);

	friend FuzzyNumber operator +(const FuzzyNumber a, const FuzzyNumber b);
	friend FuzzyNumber operator *(const FuzzyNumber a, const FuzzyNumber b);

	friend ostream& operator << (ostream& out, const FuzzyNumber& a);
	friend istream& operator >> (istream& in, FuzzyNumber& a) throw(logic_error);
};


