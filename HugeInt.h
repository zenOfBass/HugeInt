#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>

using std::ostream;
using std::istream;
using std::string;

class HugeInt 
{
private:
    char*  number;   //number = new char[capacity]
    int    size;     //e.g. 765321 size = 6
    int    capacity; //30: the capacity of an array that holds the actual number by digit
    void   computeSize();
    
public:
    HugeInt();
    HugeInt(long);
    HugeInt(const char*);
    HugeInt(const HugeInt&);
    ~HugeInt();

    HugeInt& operator=(const HugeInt&);
    HugeInt  operator+(const HugeInt&);
    HugeInt  operator-(const HugeInt&);
    HugeInt  operator*(const HugeInt&); 
    HugeInt  operator/(const HugeInt&);
    HugeInt  operator%(const HugeInt&);
    
    HugeInt& operator++(); // pre-increment
    HugeInt  operator++(int); // post-increment, int is a dummy to distinguish for overloading
    bool     operator<<(const HugeInt&);
    char&    operator[](int); // index operator, index operator
    operator long double();

    friend ostream& operator<<(ostream&, const HugeInt &);
    friend istream& operator>>(istream&, HugeInt&);
};

#endif
