#include "kontaktmanager.h"
#include<math.h> 

void KontaktManager::dateiEinlesen(const string kontaktListe)
{
  ifstream file_obj(kontaktListe);
  string kontaktZeile;

  int id=0;
  int ID;
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

  string kontaktelement;
  int kontaktelmtcounter = 0;
  int idcounter=0;
  int counter = 0;
  int start=0;
  int i;
  // Opening file in input mode
  while (getline(file_obj, kontaktZeile))
  {
    //cout<<kontaktZeile<<endl;
    for (i = 0; i < kontaktZeile.size(); i++)
    {

      if (!(kontaktZeile[i] == ' '))
      {
        kontaktelmtcounter++;
        idcounter++;
      }
      else
      {
        if(start=i-kontaktelmtcounter>0){
            start=i-kontaktelmtcounter;
            kontaktelement.append(kontaktZeile,start,kontaktelmtcounter);
        }
        counter++;
        
          switch (counter)
          {
    
          case 1:
          
            for(int k=0; k<idcounter; k++)
            {
                id += (kontaktZeile[k]-'0')*pow(10,idcounter-k-1);
            }
            kontaktelement.clear();
            ID=id;
            id=0;
            break;
    
          case 2:
            vorname=kontaktelement;
            kontaktelement.clear();
            break;
    
          case 3:
            nachname=kontaktelement;
            kontaktelement.clear();
            break;
    
          case 4:
            geburtsdatum=kontaktelement;
            kontaktelement.clear();
            break;
    
          case 5:
            strasse=kontaktelement;
            kontaktelement.clear();
         
            break;
    
          case 6:

            hausnummer=kontaktelement;
            kontaktelement.clear();
            break;
    
          case 7:
            plz=kontaktelement;
            kontaktelement.clear();
            
            break;
    
          case 8:
            ort=kontaktelement;
            kontaktelement.clear();
            break;
    
          case 9:
            geschlecht=kontaktelement;
            kontaktelement.clear();
            break;
    
          case 10:
    
            //cout<<start<<endl;
            
            telefonnummer=kontaktelement;
            //cout<<telefonnummer<<endl<<endl;
            kontaktelement.clear();
            //cout<<counter<<endl;
            break;
    
          case 11:

            //cout<<counter<<endl;
            //cout<<start<<endl;
            
            mobilnummer=kontaktelement;
            //cout<<mobilnummer<<endl<<endl;
            kontaktelement.clear();
            start=i;
            break;
          }
       kontaktelmtcounter = 0; 
       }
    }
        
        kontaktelement.append(kontaktZeile,start,kontaktZeile.size()-start+1);
        emailAdresse=kontaktelement;
        kontaktelement.clear();
        counter=0;
        idcounter=0;

    Kontakt kontakt(ID, vorname, nachname, geburtsdatum, strasse, hausnummer, 
    plz, ort, geschlecht, telefonnummer, mobilnummer, emailAdresse);
    this->kontakte.push_back(kontakt);
  }
}

void KontaktManager::kontakteAnzeigen() const
{
   for(auto kontakt: kontakte){
     kontakt.dataAusgeben();
   }
}