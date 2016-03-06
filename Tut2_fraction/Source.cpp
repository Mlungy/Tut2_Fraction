// Fraction class with operator overloading

#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;
int gcd(int, int);

// Class fraction declaration and definition

class fraction
{
public:
	fraction();   //constructor
	friend fraction operator+(fraction, fraction);
	friend fraction operator-(fraction, fraction);
	friend fraction operator*(fraction, fraction);
	friend fraction operator/(fraction, fraction);
private:
	int num;  // Numerator
	int den;  // Denominator

};

// The constructor

fraction::fraction()
{
	num = den = 0;
}

// Overloading Addition sign (+)

fraction operator+(fraction  f1, fraction f2)
{
	fraction temp;
	if (f1.den == f2.den)
	{
		temp.num = f1.num + f2.num;
		temp.den = f1.den;
	}
	else if (f1.den != f2.den)
	{
		temp.num = (f1.num*f2.den) + (f2.num*f1.den);
		temp.den = f1.den*f2.den;
	}
	return temp;
}

// Overloading subraction sign (-)

fraction operator-(fraction  f1, fraction f2)
{
	fraction temp;
	if (f1.den == f2.den)
	{
		temp.num = f1.num - f2.num;
		temp.den = f1.den;
	}
	else if (f1.den != f2.den)
	{
		temp.num = (f1.num*f2.den) - (f2.num*f1.den);
		temp.den = f1.den*f2.den;
	}
	return temp;
}

// OverLoading multiplication sign (*)

fraction operator*(fraction  f1, fraction f2)
{
	fraction temp;
	temp.num = f1.num * f2.num;
	temp.den = f1.den * f2.den;
	return temp;
}

//Overloading Division sign
fraction operator/(fraction  f1, fraction f2)
{
	fraction temp;
	temp.num = f1.num * f2.den;
	temp.den = f1.den * f2.num;
	return temp;
}

int main()
{
	fraction r1, r2, rA, rS, rM, rD;
	cout << "enter fraction1 in the form 3/4\n";
	cin >> r1;

	cout << "enter fraction2 int the form 3/4\n";
	cin >> r2;

	cout << "\nAddition:\n";
	rA = r1 + r2;
	cout << rA << endl;
	cout << "Subtraction:\n";
	rS = r1 - r2;
	cout << rS << endl;

	cout << "Multiplication:\n";
	rM = r1*r2;
	cout << rM << endl;

	cout << "Division\n";
	rD = r1 / r2;
	cout << rD << endl;
	system("pause");
	return 0;
}

int gcd(int a, int b)    //Greatest common divisor function
{
	int c = a % b;            // Euclids Algorithm
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

