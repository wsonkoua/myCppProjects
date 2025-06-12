#include "kontaktmanager.h"

int main()
{

    char MenueWahl;

    KontaktManager kontaktmanager;

    cout << "----------------------" << endl;

    cout << "(1) Kontaktliste einlesen" << endl;

    cout << "(2) Kontaktliste ausgeben" << endl;

    cout << "(x) Programm beenden" << endl
         << endl
         << endl;

    cout << "Menü-Wahl:" << endl;

    cout << "----------------------" << endl;

    cin >> MenueWahl;

    while (1)
    {

        switch (MenueWahl)
        {
        case '1':

            kontaktmanager.dateiEinlesen("kontakt.txt");

            break;

        case '2':

         kontaktmanager.kontakteAnzeigen();

         break;

        case 'x':

            return 0;
            break;
        }
        
        cin >>MenueWahl;
    }
}