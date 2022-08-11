#include "FuzzyNumberPrivate.h"
#include "FuzzyNumberPublic.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

void Call_Bad() throw(int)
{
	throw 'x';
}

int main()
{
	set_unexpected(_unexpected_to_bad);

	try
	{
		FuzzyNumberPrivate A1;
		cin >> A1;
		cout << A1;

		cout << "Size of private class: " << sizeof(A1) << endl;

		FuzzyNumberPrivate B1(5, 1, 7);
		cout << B1 << endl;

		FuzzyNumberPrivate C1 = A1 + B1;
		cout << "C1 = " << C1 << endl;

		FuzzyNumberPrivate D1 = A1 * B1;
		cout << "D1 = " << D1 << endl;
		try
		{
			A1--;
		}
		catch (InheritedException a)//за замовчуванням
		{
			cerr << a.What() << endl << endl;
		}
		catch (InheritedException* a)//вказівник
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	FuzzyNumberPrivate N1;
	cin >> N1;
	cout << N1;

	try
	{
		N1++;
	}
	catch (Exception& a)//посилання
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		FuzzyNumberPublic A2;
		cin >> A2;
		cout << A2;

		cout << "Size of public class: " << sizeof(A2) << endl;

		FuzzyNumberPublic B2(4, 1, 5);
		cout << B2 << endl;

		FuzzyNumberPublic C2 = A2 + B2;
		cout << "C2 = " << C2 << endl;

		FuzzyNumberPublic D2 = A2 * B2;
		cout << "D2 = " << D2 << endl;
		try
		{
			A2--;
		}
		catch (InheritedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (InheritedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	FuzzyNumberPublic N2;
	cin >> N2;
	cout << N2;

	try
	{
		N2++;
	}
	catch (Exception& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception) //стандарт
	{
		cerr << "catch (bad_exception)" << endl;
	}
}