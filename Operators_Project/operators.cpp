#include <iostream>
#include "Number.h"
using namespace std;
int main()
{
	cout << "OBS: Bazele de numeratie pot fi intre 2 si 16! \n";
	Number n1("10B", 16);
	Number n2("234", 10);
	Number n3 = n2; //COPY CONSTRUCTOR
	n3 = n2; // EXAMPLE OF COPY ASSIGNMENT
	cout << "n3 are valoarea: ";
	n3.Print();
	cout << '\n';
	cout << "Numerele sunt :";
	n1.Print();
	cout << " ";
	n2.Print();
	cout << "\n si au "<<n1.GetDigitsCount()<<", respectiv, "<<n2.GetDigitsCount()<<" cifre \n";
	cout << "Numarul 1 are baza : " << n1.GetBase() << '\n';
	cout << "Numarul 2 are baza: " << n2.GetBase() << '\n';

	Number n4 = std::move(n3);
	cout << "Am mutat numarul 3 in numarul 4 \n";
    Number n8("124", 10);
	n8 = std::move(n4);
	cout << "Am folosit operatorul de mutare, l-am mutat in n8 pe n4 \n";
	
	--n1;
	cout << "Pre-decrementam n1 : ";
	n1.Print();
	cout << "\n";
	
	n2--;
	cout << "Post-decrementam n2 : ";
	n2.Print();
	cout << "\n";
	
	if (n2 < n1) {
		cout << "True! \n";
	}
	else {
		cout << "False! \n";
	}
	if (n2 >= n1) {
		cout << "True! \n";
	}
	else {
		cout << "False! \n";
	}
	if (n2 == n8) {
		cout << "Equal \n";
	}
	else cout << "n2 not equal to n4 \n";
	
	Number n5 = n1 - n2;
	cout << "Scaderea dintre n1 si n2 da: ";
	n5.Print();
	cout << '\n';
	Number n6 = n1 + n2;
	n1.Print();
	cout << "\n";
	n2.Print();
	cout << "\n";
	cout << "Adunarea dintre n1 si n2 da: ";
	n6.Print();
	return 0;
}