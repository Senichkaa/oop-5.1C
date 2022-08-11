#pragma once
#include "FuzzyNumber.h"
class FuzzyNumberPublic : public FuzzyNumber
{
public:
	FuzzyNumberPublic();
	FuzzyNumberPublic(double x, double l, double r);
	FuzzyNumberPublic(const FuzzyNumberPublic& v);

	FuzzyNumberPublic& operator =(const FuzzyNumberPublic& n);

	FuzzyNumberPublic& operator --() throw(InheritedException);
	FuzzyNumberPublic& operator ++() throw(Exception);
	FuzzyNumberPublic operator --(int) throw(InheritedException);
	FuzzyNumberPublic operator ++(int) throw(logic_error);

	friend FuzzyNumberPublic operator +(const FuzzyNumberPublic a, const FuzzyNumberPublic b);
	friend FuzzyNumberPublic operator *(const FuzzyNumberPublic a, const FuzzyNumberPublic b);
};

