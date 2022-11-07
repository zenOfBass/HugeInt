#include <iostream>
#include "HugeInt.h"

using std::ostream;
using std::istream;
using std::string;

using namespace std;

void HugeInt::computeSize()
{
	//Set the size of the number of an HugeInt object
	long i = 0;
	for (i = 0; i < 30; i++) if (this->number[i] != 0) break;
	this->size = (30 - i);
}

HugeInt::HugeInt()
{
	cout << "HugeInt() called" << endl;

	size = 0;
	capacity = 30;
	number = new char[capacity];
}

HugeInt::HugeInt(long value)
{
	cout << "HugeInt(long) called" << endl;
	
	capacity = 30;
	number = new char[capacity];
	for (int i = 0; i < capacity; i++) number[i] = 0;

	//extract each digit as a number and store it 
	int count = capacity -1;
	int quotient = value;
	while (quotient > 0)
	{
		char digit = quotient % 10;
		quotient /= 10;
		number[count] = digit;
		count--;
	}
	size = capacity - count;

	computeSize();
}

HugeInt::HugeInt(const char* c)
{
	cout << "HugeInt(const char*) called" << endl;
	
	capacity = 30;
	number = new char[capacity];
	for (int i = 0; i < capacity; i++) number[i] = 0;
	int i = 0;

	/*while (c[i] != '\0')
	{
		number[] = c[i] - '0';
	}*/

	string s = c;
	size = s.length();

	for (int i = size - 1; i >= 0; i--) {
		number[capacity - size + i] = s[i] - '0';
	}

	computeSize();
}

HugeInt::HugeInt(const HugeInt& copy)
{
	cout << "HugeInt(const HugeInt&) called" << endl;
	
	capacity = 30;
	number = copy.number;
	size = copy.size;
}

HugeInt::~HugeInt()
{
	cout << "~HugeInt() called" << endl;
}

HugeInt& HugeInt::operator=(const HugeInt& right)
{
	cout << "operator=(const HugeInt&) called" << endl;
	
}

HugeInt  HugeInt::operator+(const HugeInt& right)
{
	cout << "operator+(const HugeInt&)" << endl;
	
	HugeInt temp; // temporary result
	int carry = 0;

	for (int i = 29; i >= 0; i--)
	{
		temp.number[i] =
			number[i] + right.number[i] + carry;

		// determine whether to carry a 1
		if (temp.number[i] > 9)
		{
			temp.number[i] %= 10;  // reduce to 0-9
			carry = 1;
		} // end if
		else // no carry 
			carry = 0;
	} // end for

	return temp;

	// you don't need to carry the last digit
}

HugeInt HugeInt::operator-(const HugeInt& right)
{
	cout << "operator-(const HugeInt&)" << endl;

	//don't worray about neative numbers
}

HugeInt HugeInt::operator*(const HugeInt& right)
{
	cout << "operator*(const HugeInt&)" << endl;

}

HugeInt HugeInt::operator/(const HugeInt& right)
{
	cout << "operator/(const HugeInt&)" << endl;
}

HugeInt HugeInt::operator%(const HugeInt&)
{
	cout << "operator%(const HugeInt&)" << endl;
}

HugeInt& HugeInt::operator++()
{
	cout << "operator++()" << endl;
}

HugeInt HugeInt::operator++(int)
{
	cout << "operator+(int)" << endl;
}

bool HugeInt::operator<<(const HugeInt&)
{
	cout << "operator<<(const HugeInt&)" << endl;
}

char& HugeInt::operator[](int)
{
	cout << "operator[](int)" << endl;
}

HugeInt::operator long double()
{
	cout << "operator long doubl()" << endl;
}