#include "FuzzyNumberPublic.h"

FuzzyNumberPublic::FuzzyNumberPublic()
	:FuzzyNumber()
{
}

FuzzyNumberPublic::FuzzyNumberPublic(double x, double l, double r)
	: FuzzyNumber(x, l, r)
{
}

FuzzyNumberPublic::FuzzyNumberPublic(const FuzzyNumberPublic& v)
	:FuzzyNumber(v)
{
}

FuzzyNumberPublic& FuzzyNumberPublic::operator=(const FuzzyNumberPublic& n)
{
	FuzzyNumber::operator = (n);
	return *this;
}

FuzzyNumberPublic& FuzzyNumberPublic::operator--() throw(InheritedException)
{
	this->set_l(this->get_l() - 1);
	if (this->get_l() < 0)
		throw new InheritedException();
	return *this;
}

FuzzyNumberPublic& FuzzyNumberPublic::operator++() throw(Exception)
{
	this->set_r(this->get_r() + 1);
	if (this->get_r() > 10)
		throw Exception("Right coordinate bigger than 10");
	return *this;
}

FuzzyNumberPublic FuzzyNumberPublic::operator--(int) throw(InheritedException)
{
	FuzzyNumberPublic a(*this);
	this->set_l(this->get_l() - 1);
	if (this->get_l() < 0)
		throw InheritedException();
	return a;
}

FuzzyNumberPublic FuzzyNumberPublic::operator++(int) throw(logic_error)
{
	FuzzyNumberPublic a(*this);
	this->set_r(this->get_r() + 1);
	if (this->get_r() > 10)
		throw logic_error("Right coordinate bigger than 10");
	return a;
}

FuzzyNumberPublic operator+(const FuzzyNumberPublic a, const FuzzyNumberPublic b)
{
	FuzzyNumberPublic T;
	T.set_x(a.get_x() + b.get_x());
	T.set_l(a.get_x() + b.get_x() - a.get_l() - b.get_l());
	T.set_r(a.get_x() + b.get_x() + a.get_r() + b.get_r());
	return T;
}

FuzzyNumberPublic operator*(const FuzzyNumberPublic a, const FuzzyNumberPublic b)
{
	FuzzyNumberPublic N;
	N.set_x(a.get_x() * b.get_x());
	N.set_l(a.get_x() * b.get_x() - b.get_x() * a.get_l() - a.get_x() * b.get_l() - a.get_l() * b.get_l());
	N.set_r(a.get_x() * b.get_x() + b.get_x() * a.get_r() + a.get_x() * b.get_r() + a.get_r() * b.get_r());
	return N;
}
