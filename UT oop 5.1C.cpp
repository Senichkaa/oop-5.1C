#include "pch.h"
#include "CppUnitTest.h"
#include "../oop 5.1C/FuzzyNumberPublic.cpp"
#include "../oop 5.1C/FuzzyNumberPrivate.cpp"
#include "../oop 5.1C/FuzzyNumber.cpp"
#include "../oop 5.1C/InheritedException.cpp"
#include "../oop 5.1C/Exception.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UToop51C
{
	TEST_CLASS(UToop51C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FuzzyNumberPrivate A1(4, 1, 7), B1(6, 3, 9);
			FuzzyNumberPrivate Sum = A1 + B1;
			Assert::AreEqual(Sum.get_x(), 10.0);
		}
	};
}
