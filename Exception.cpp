#include "Exception.h"

Exception::Exception() throw()
	:message()
{
}

Exception::Exception(const string& m) throw()
	:message(m)
{
}
