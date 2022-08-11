#include "InheritedException.h"

const char* InheritedException::What() const throw()
{
    return "Exception: InheritedException: l<0";
}
