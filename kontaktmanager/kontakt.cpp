#include "kontakt.h"


Kontakt::Kontakt(const int ID_,
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
            const string emailAdresse_):ID(ID_),
                                       vorname(vorname_),
                                       nachname(nachname_),
                                       geburtsdatum(geburtsdatum_),
                                       strasse(strasse_),
                                       hausnummer(hausnummer_),
                                       plz(plz_),
                                       ort(ort_),
                                       geschlecht(geschlecht_),
                                       telefonnummer(telefonnummer_),
                                       mobilnummer(mobilnummer_),
                                       emailAdresse(emailAdresse_){

}


   void Kontakt::dataAusgeben() const{
      cout<<"------------------------------"<<endl;
      cout<<"ID: "<<this->getID()<<endl;
      cout<<"Vorname: "<<this->getVorname()<<endl;
      cout<<"Nachname: "<<this->getNachname()<<endl;
      cout<<"Geburtsdatum: "<<this->getGeburtsdatum()<<endl;
      cout<<"Adresse: "<<this->getStrasse()<<" "<<this->getHausnummer()<<", "<<this->getPlz()<<" "<<this->getOrt()<<endl;
      cout<<"Geschlecht: "<<this->getGeschlecht()<<endl;
      cout<<"Telefon: "<<this->getTelefonnummer()<<endl;
      cout<<"Mobil: "<<this->getMobilnummer()<<endl;
      cout<<"E-Mail: "<<this->getEmailAdresse()<<endl;
   }

   int Kontakt::getID() const{
      return ID;
   }

    string Kontakt::getVorname() const{
       return vorname;
    }

    string Kontakt::getNachname() const{
        return nachname;
    }

    string Kontakt::getGeburtsdatum() const{
       return geburtsdatum;
    }

    string Kontakt::getStrasse() const{
       return strasse;
    } 

    string Kontakt::getHausnummer() const{
       return hausnummer;
    } 

    string Kontakt::getPlz() const{
     return plz;
    }

    string Kontakt::getOrt() const{
        return ort;
    }

    string Kontakt::getTelefonnummer() const{
        return telefonnummer;
    }

    string Kontakt::getMobilnummer() const{
       return mobilnummer;
    }

    string Kontakt::getGeschlecht() const{
       return this->getGeschlechtLiteral(geschlecht);
    }

    string Kontakt::getEmailAdresse() const{
       return emailAdresse;
    }

   string Kontakt::getGeschlechtLiteral(const string geschlechtKuerzel) const{
       string geschlecht;
       if("m"== geschlechtKuerzel){
          geschlecht="männlich";
       }

       if("w"== geschlechtKuerzel){
          geschlecht= "weiblich";
       }

       if("u"== geschlechtKuerzel){
          geschlecht="undefiniert";
       }
       
       return geschlecht;
   }