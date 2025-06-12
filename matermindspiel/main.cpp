#include <iostream>
using namespace std;
#include "MastermindDigits.h"

int main(){
    int test; 
    int count=0;
    bool gewonnen;
    
    
    
cout<< "Testen(1) oder Spielen(2) :";
cin>> test;
if (test==1){
    int Testzahl;
    MastermindDigits zahl2;
    cout<<"Testzahl eingeben: ";
    cin>> Testzahl;
       do {
count++;
cout << "\n" << count<<"."<<" Versuch; gib Zahl: ";


       
       int newzahl1;
       int resultright;
       int resultwrong;
      
        MastermindDigits zahl1(Testzahl);
        
        cin>>newzahl1;
        zahl2.setDigits(newzahl1);
        resultright=zahl1.locationRight(zahl2);
        resultwrong=zahl1.locationWrong(zahl2);
        cout<<resultright<<" an der richtigen Stelle"<<endl;
        cout<<"sonst "<<resultwrong<< " richtig"<<endl;
        
        gewonnen = zahl1.isEqual(zahl2);
    if (gewonnen == true) 
     {
      cout << "Gratuliere!! " << endl;
      cout << "\nTesten (1) oder Spielen (2) oder beenden (0) : ";
     }
     } while (gewonnen != true);

}
     if (test==2){
         
        do {
count++;
cout << "\n" << count<<"."<<" Versuch; gib Zahl: ";


        MastermindDigits Geheimzahl;
        MastermindDigits zahl2;
        int newzahl1;
        int resultright;
        int resultwrong;
        
        cin>>newzahl1;
        zahl2.setDigits(newzahl1);
        resultright=Geheimzahl.locationRight(zahl2);
        resultwrong=Geheimzahl.locationWrong(zahl2);
        cout<<resultright<<" an der richtigen Stelle"<<endl;
        cout<<"sonst "<<resultwrong<< " richtig";
       
      
        gewonnen = Geheimzahl.isEqual(zahl2);
if (gewonnen == true) 
{
cout << "Gratuliere!! " << endl;
cout << "\nTesten (1) oder Spielen (2) oder beenden (0) : ";
}
} while (gewonnen != true);
    
    
     }  
}

