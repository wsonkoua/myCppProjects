#include <iostream>
#include <fstream>

using namespace std;
class Kontakt{

    public: 

    //Kontakt(const Kontakt& obj);

    Kontakt(const int ID_,
            const string vorname_,
            const string nachname_,
            const string geburtsdatum_,
            const string strasse_,
            const string hausnummer_,
            const string plz_,
            const string ort_,
            const string geschlecht_,
            const string telefonnummer_,
            const string mobilnummer_,
            const string emailAdresse_);
            
    void dataAusgeben() const;

    int getID() const;

    string getVorname() const;

    string getNachname() const; 

    string getGeburtsdatum() const;

    string getStrasse() const;

    string getHausnummer() const; 

    string getPlz() const;

    string getOrt() const;

    
    string getTelefonnummer() const;

    string getMobilnummer() const;

    string getGeschlecht() const;

    string getEmailAdresse() const;


    private:

    string getGeschlechtLiteral(const string geschlechtKuerzel) const;

    const int ID;
    string vorname; 
    string nachname;
    string geburtsdatum;
    string strasse;
    string hausnummer;
    string plz;
    string ort;
    string geschlecht;
    string telefonnummer;
    string mobilnummer;
    string emailAdresse;
};






