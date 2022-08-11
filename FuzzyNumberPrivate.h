#pragma once
#include "FuzzyNumber.h"
class FuzzyNumberPrivate: private FuzzyNumber
{
public:
	using FuzzyNumber::get_x;
	using FuzzyNumber::get_l;
	using FuzzyNumber::get_r;

	using FuzzyNumber::set_x;
	using FuzzyNumber::set_l;
	using FuzzyNumber::set_r;

	using FuzzyNumber::FuzzyNumber;

	FuzzyNumberPrivate();
	FuzzyNumberPrivate(double x, double l, double r);
	FuzzyNumberPrivate(const FuzzyNumberPrivate& v);

	FuzzyNumberPrivate& operator =(const FuzzyNumberPrivate& n);
	operator string() const;

	FuzzyNumberPrivate& operator --() throw (InheritedException);
	FuzzyNumberPrivate& operator ++() throw (Exception);
	FuzzyNumberPrivate operator --(int) throw (InheritedException);
	FuzzyNumberPrivate operator ++(int) throw (logic_error);

	friend FuzzyNumberPrivate operator + (const FuzzyNumberPrivate a, const FuzzyNumberPrivate b);
	friend FuzzyNumberPrivate operator * (const FuzzyNumberPrivate a, const FuzzyNumberPrivate b);

	friend ostream& operator << (ostream& out, const FuzzyNumberPrivate& a);
	friend istream& operator >> (istream& in, FuzzyNumberPrivate& a) throw(logic_error);
};

