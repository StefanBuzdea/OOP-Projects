#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"

Number::Number(const char* value, int base) {
	// where base is between 2 and 16
	this->base = base;
	number = new char[strlen(value) + 1];
	strcpy(number, value);
}


Number::~Number() {
	delete[] number;
	number = nullptr;
	base = 0;
} // delete object



Number::Number(const Number& t) {
	base = t.base;
	delete[] number;
	number = nullptr;
	number = new char[strlen(t.number) + 1];
	strcpy(number, t.number);
}


Number::Number(Number&& t) noexcept {
	number = t.number;
	base = t.base;
	t.number = nullptr;
	t.base = 0;
}

//-- pre-decrement
void Number::operator--() {
	int len = strlen(number);
	int i, nr;
	for (i = 1; i <= len-1; i++) {
		number[i - 1] = number[i];
	}
	number[len - 1] = '\0';
	//eliminate the useless zero's
	i = 0;
	nr = 0;
	len--;
	while (number[i] == '0') {
		nr++;
		i++;
	}
	for (i = 0; i <= len-nr; i++) {
		number[i] = number[i + nr];
	}
	number[len - nr + 1] = '\0';
}
//-- post-decrement
void Number::operator--(int) {
	int len = strlen(number);
	number[len - 1] = '\0';
}

// = copy assignment operator
Number& Number::operator = (const Number& t)
{
	if (number != nullptr)
	{
		delete[] number;
		number = nullptr;
	}
	number = new char[strlen(t.number) + 1];
	memcpy(number, t.number, strlen(t.number) + 1);
	base = t.base;
	return *this;
}

// = move operator
Number& Number::operator = (Number&& t) noexcept{
	delete[] number;
	number = t.number;
	base = t.base;
	t.number = nullptr;
	t.base = 0;
	return *this;
}


// + operator
Number operator + (const Number& t1, const Number& t2) {
	int number1, number2, i, len, r, aux;
	char reVal;
	Number n1 = t1;
	Number n2 = t2;
	//maximum base
	int b = n2.base;
	if (n1.base > n2.base) {
		b = n1.base;
	}
	n1.SwitchBase(10);
	n2.SwitchBase(10);
	//convert to int number
	i = 0;
	number1 = 0;
	while (n1.number[i]) {
		number1 = number1 * 10 + (n1.number[i] - '0');
		i++;
	}
	i = 0;
	number2 = 0;
	while (n2.number[i]) {
		number2 = number2 * 10 + (n2.number[i] - '0');
		i++;
	}
	number1 += number2;
	number2 = number1;
	r = 0;
	while (number2) {
		number2 /= 10;
		r++;
	}
	char* auxChar = new char[r+2];
	//convert back to char
	len = 0;
	number2 = number1;
	//if number2 = 0?
	if (!number2) {
		auxChar[len] = '0';
		len++;
	}
	else {
		while (number2) {
			r = number2 % 10;
			reVal = (char)(r + '0');
			auxChar[len] = reVal;
			len++;
			number2 /= 10;
		}
	}
	auxChar[len] = '\0';
	//reverse number to be properly
	for (i = 0; i < len / 2; i++) {
		aux = auxChar[i];
		auxChar[i] = auxChar[len - 1 - i];
		auxChar[len - 1 - i] = aux;
	}
	//switch to bigger base
	Number n3(auxChar, 10);
	n3.SwitchBase(b);
	return n3;
}


// - operator
Number operator - (const Number& t1, const Number& t2) {
	int number1, number2, i, len, r, aux;
	char reVal;
	Number n1 = t1;
	Number n2 = t2;
	//maximum base
	int b = n2.base;
	if (n1.base > n2.base) {
		b = n1.base;
	}
	n1.SwitchBase(10);
	n2.SwitchBase(10);
	//convert to int number
	i = 0;
	number1 = 0;
	while (n1.number[i]) {
		number1 = number1 * 10 + (n1.number[i] - '0');
		i++;
	}
	i = 0;
	number2 = 0;
	while (n2.number[i]) {
		number2 = number2 * 10 + (n2.number[i] - '0');
		i++;
	}
	//substraction (absolute value)
	if (number1 < number2) {
		aux = number1;
		number1 = number2;
		number2 = aux;
	}
	number1 -= number2;
	number2 = number1;
	r = 0;
	while (number2) {
		number2 /= 10;
		r++;
	}
	char* auxChar = new char[r+2];
	len = 0;
	number2 = number1;
	//if number2 = 0?
	if (!number2) {
		auxChar[len] = '0';
		len++;
	}
	else {
		while (number2) {
			r = number2 % 10;
			reVal = (char)(r + '0');
			auxChar[len] = reVal;
			len++;
			number2 /= 10;
		}
	}
	auxChar[len] = '\0';
	//reverse number to be properly
	for (i = 0; i < len / 2; i++) {
		aux = auxChar[i];
		auxChar[i] = auxChar[len - 1 - i];
		auxChar[len - 1 - i] = aux;
	}
	//switch to bigger base
	Number n3(auxChar, 10);
	delete[] auxChar;
	n3.SwitchBase(b);;
	return n3;
}


//index operator
char& Number::operator [] (int index) {
	if (index >= GetDigitsCount()) {
		cout << "Array index out of bound! \n";
		exit(0);
	}
	return number[index];
}


// < operator
bool Number::operator < (const Number& t) {
	Number n1 = (*this);
	Number n2 = t;
	n1.SwitchBase(10);
	n2.SwitchBase(10);
	if (strcmp(n1.number, n2.number) < 0) {
		return true;
	}
	return false;
}


// >= operator
bool Number::operator >= (const Number& t) {
	Number n1 = (*this);
	Number n2 = t;
	n1.SwitchBase(10);
	n2.SwitchBase(10);
	if (strcmp(n1.number, n2.number) >= 0) {
		return true;
	}
	return false;
}


// == operator
bool Number::operator == (const Number& t) {
	Number n1 = (*this);
	Number n2 = t;
	n1.SwitchBase(10);
	n2.SwitchBase(10);
	if (strcmp(n1.number, n2.number) == 0) {
		return true;
	}
	return false;
}


//switch base
void Number::SwitchBase(int newBase) {
	int i = 0;
	if (number[i]) {
		int p, base10, len, c, r, aux;
		char reVal;
		p = 1;
		base10 = 0;
		len = strlen(number);
		//convert from current base to base 10 
		for (i = len - 1; i >= 0; i--) {
			if (number[i] >= '0' && number[i] <= '9') {
				c = number[i] - '0';
			}
			else {
				c = number[i] - 'A' + 10;
			}
			base10 = base10 + c * p;
			p = p * base;
		}
		i = 1;
		delete[] number;
		number = (char*)malloc(i);
		//convert from base 10 to new base 
		if (base10 == 0) {
			number[i - 1] = '0';
			i++;
			number = (char*)realloc(number, i);
		}
		else {
			while (base10) {
				r = base10 % newBase;
				if (r <= 9) {
					reVal = (char)(r + '0');
				}
				else {
					reVal = (char)((r - 10) + 'A');
				}
				number[i - 1] = reVal;
				i++;
				base10 = base10 / newBase;
				number = (char*)realloc(number, i);
			}
		}
		number[i - 1] = '\0';
		len = strlen(number);
		//reverse number to be properly
		for (i = 0; i < len / 2; i++) {
			aux = number[i];
			number[i] = number[len - 1 - i];
			number[len - 1 - i] = aux;
		}
	}
	base = newBase;
}


void Number::Print() {
	cout << number;
}


int  Number::GetDigitsCount() {
	int len = strlen(number);
	return len;
	// returns the number of digits for the current number
}


int  Number::GetBase() {
	return base;
	// returns the current base
}
