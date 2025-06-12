#include <iostream>
#include <fstream>

#include <vector>

#include "kontakt.h"

using namespace std;

class KontaktManager{

    public:

    void dateiEinlesen(const string kontaktListe);

    void kontakteAnzeigen()const;

    private:
 
    vector<Kontakt> kontakte;
};