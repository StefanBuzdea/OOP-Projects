#include <iostream>
#include "Canvas.h"
using namespace std;
int main()
{
    int x1, x2, y1, y2, numar=0;
    int raza;
    char c;
    // initializare dimensiuni matrice (constructor)
    Canvas canv(20, 20);
	cout << "Scrieti coordonatele primului punct (aceleasi coordonate se folosesc si pentru centrul cercului): ";
	cin >> x1 >> y1;
    cout << '\n';
	cout << "Scrieti coordonatele celui de-al doilea punct: ";
	cin >> x2 >> y2;
    cout << '\n';
	cout << "Scrieti lungimea razei (numar intreg): ";
	cin >> raza;
    cout << '\n';
    cout << "Tastati caracterul cu care sa se deseneze: ";
    cin >> c;
    cout << '\n';
    while (numar != 7) {
        cout << "Alegeti ce doriti sa desenati: \n";
        cout << "1. Un cerc gol \n";
        cout << "2. Un cerc plin \n";
        cout << "3. Un patrat gol \n";
        cout << "4. Un patrat plin \n";
        cout << "5. Un punct \n";
        cout << "6. O linie \n";
        cout << "7. Iesire \n";
        cin >> numar;
        switch (numar) {
        case 1:
            canv.DrawCircle(x1, y1, raza, c);
            canv.Print();
            canv.Clear();
            break;
        case 2:
            canv.FillCircle(x1, y1, raza, c);
            canv.Print();
            canv.Clear();
            break;
        case 3:
            canv.DrawRect(x1, y1, x2, y2, c);
            canv.Print();
            canv.Clear();
            break;
        case 4:
            canv.FillRect(x1, y1, x2, y2, c);
            canv.Print();
            canv.Clear();
            break;
        case 5:
            canv.SetPoint(x1, y1, c);
            canv.Print();
            canv.Clear();
            break;
        case 6:
            canv.DrawLine(x1, y1, x2, y2, c);
            canv.Print();
            canv.Clear();
            break;
        case 7:
            cout << "Goodbye! \n";
            break;
        default:
            cout << "Nu s-a introdus un numar corect! \n";
        }
    }
}

