#pragma once
#include <string>
#include <sstream>

using namespace std;

class Exception
{
private:
	string message;
public:
	Exception() throw();
	Exception(const string& m) throw();
	string What() const throw() { return message; }
	virtual ~Exception() {};
};

