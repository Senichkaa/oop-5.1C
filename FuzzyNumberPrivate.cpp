#include "FuzzyNumberPrivate.h"

FuzzyNumberPrivate::FuzzyNumberPrivate()
	:FuzzyNumber()
{
}

FuzzyNumberPrivate::FuzzyNumberPrivate(double x, double l, double r)
	: FuzzyNumber(x, l, r)
{
}

FuzzyNumberPrivate::FuzzyNumberPrivate(const FuzzyNumberPrivate& v)
	: FuzzyNumber(v)
{
}

FuzzyNumberPrivate& FuzzyNumberPrivate::operator=(const FuzzyNumberPrivate& n)
{
	FuzzyNumber::operator = (n);
	return *this;
}

FuzzyNumberPrivate::operator string() const
{
	stringstream ss;
	ss << "(" << get_l() << "; " << get_x() << "; " << get_r() << ")" << endl;
	return ss.str();
}

FuzzyNumberPrivate& FuzzyNumberPrivate::operator--() throw(InheritedException)
{
	this->set_l(this->get_l() - 1);
	if (this->get_l() < 0)
		throw new InheritedException();
	return *this;
}

FuzzyNumberPrivate& FuzzyNumberPrivate::operator++() throw(Exception)
{
	this->set_r(this->get_r() + 1);
	if (this->get_r() > 10)
		throw Exception("Right coordinate bigger than 10");
	return *this;
}

FuzzyNumberPrivate FuzzyNumberPrivate::operator--(int) throw(InheritedException)
{
	FuzzyNumberPrivate a(*this);
	this->set_l(this->get_l() - 1);
	if (this->get_l() < 0)
		throw InheritedException();
	return a;
}

FuzzyNumberPrivate FuzzyNumberPrivate::operator++(int) throw(logic_error)
{
	FuzzyNumberPrivate a(*this);
	this->set_r(this->get_r() + 1);
	if (this->get_r() > 10)
		throw logic_error("Right coordinate bigger than 10");
	return a;
}

FuzzyNumberPrivate operator+(const FuzzyNumberPrivate a, const FuzzyNumberPrivate b)
{
	FuzzyNumberPrivate T;
	T.set_x(a.get_x() + b.get_x());
	T.set_l(a.get_x() + b.get_x() - a.get_l() - b.get_l());
	T.set_r(a.get_x() + b.get_x() + a.get_r() + b.get_r());
	return T;
}

FuzzyNumberPrivate operator*(const FuzzyNumberPrivate a, const FuzzyNumberPrivate b)
{
	FuzzyNumberPrivate N;
	N.set_x(a.get_x() * b.get_x());
	N.set_l(a.get_x() * b.get_x() - b.get_x() * a.get_l() - a.get_x() * b.get_l() - a.get_l() * b.get_l());
	N.set_r(a.get_x() * b.get_x() + b.get_x() * a.get_r() + a.get_x() * b.get_r() + a.get_r() * b.get_r());
	return N;
}

ostream& operator<<(ostream& out, const FuzzyNumberPrivate& a)
{
	return out << string(a);
}

istream& operator>>(istream& in, FuzzyNumberPrivate& a) throw(logic_error)
{
	double x, l, r;
	cout << "x = "; in >> x;
	cout << "l = "; in >> l;
	cout << "r = "; in >> r;

	if (!(x > (x - l) && (x + r) > x))
		throw logic_error("Condition is not met");

	a.set_x(x); a.set_l(x - l); a.set_r(x + r);
	return in;
}
