#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Number

{
	char* number;
	int base;

public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& t); //copy constructor
	~Number();
	Number(Number&& t) noexcept; //move constructor

	Number& operator = (const Number&);

	Number& operator = (Number&& t) noexcept; //move assignment operator

	friend Number operator + (const Number& t1, const Number& t2);

	friend Number operator - (const Number& t1, const Number& t2);

	char& operator [] (int index);

	bool operator < (const Number& t);

	bool operator >= (const Number& t);

	bool operator == (const Number& t);

	void operator -- (); //pre-decrement
	void operator -- (int); //post-decrement

	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

};

