#pragma once
#include <exception>
#include <iostream>

using namespace std;

class InheritedException : public exception
{
public:
	virtual const char* What() const throw();
};

