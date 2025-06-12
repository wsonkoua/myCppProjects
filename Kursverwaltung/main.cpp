/**************************************************************************

#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>

using namespace std; 

class Student
{
   private:
   string Nachname;
   string Vorname;
   int Matrikelnummer=0;
   Student* Neuerstudent;
   
   public:
   
   Student()
   {
       
   }
   
   Student(string vorname, string nachname, int matrikelnummer)
   {
     Nachname=nachname;
     Vorname=vorname;
     Matrikelnummer=matrikelnummer;
    
   }
   
   void NeuerStudentSetzen(Student* neuer_student)
   {
     Neuerstudent=neuer_student; 
   }
   
   Student* NeuerStudentGeben()
   {
     return Neuerstudent;
   }
   
   void informationAusgeben()
   {
       cout<< Vorname<< " " <<Nachname<<  " " <<Matrikelnummer<<endl;
   }
};


class Kurs
{
    //string Kursname;
    Student* aktuellstudent;
    
    public:
    
    Kurs()
    {
      aktuellstudent=0;  
    }
    
    void Einfuegen(Student* neuerstudent_)
    {
        if(aktuellstudent==0)
        {
            aktuellstudent=neuerstudent_;
        }
        else
        {
           neuerstudent_->NeuerStudentSetzen(aktuellstudent);
           aktuellstudent=neuerstudent_;
           
        }
    }
    
    void Entfernen()
    {
        if(aktuellstudent!=0)
        {
            Student* neuer_aktuell=0;
            if(aktuellstudent->NeuerStudentGeben()!=0)
            {
                neuer_aktuell=aktuellstudent->NeuerStudentGeben();
            }
            
            delete aktuellstudent;
            aktuellstudent=neuer_aktuell;
        }
    }
    
    void informationAusgeben()
    {
        if(aktuellstudent!=0)
        {
          Student* tmp=aktuellstudent;
          while(tmp->NeuerStudentGeben()!=0)
          {
          tmp->informationAusgeben();
          tmp=tmp->NeuerStudentGeben();
          }  
          
          //tmp->informationAusgeben();
        }
    }
    
};


int main()
{
    
    Kurs newkurs;
    string Kursname, prenom, nom;
    int Matrikelnummer=0;
    cout<<"Geben Sie den Namen den Kurs an:";
    cin>> Kursname;
    
    srand((unsigned)time(NULL));
    
    while(true)
    {
        cout<< "Geben Sie den Vor- und Nachnamen: ";
        cin>> prenom;
        cin>> nom;
        
        do
        {
          Matrikelnummer=rand()%1000000;
        }while(Matrikelnummer<100000);
        
        
        if(prenom=="entfernen")
        {
            newkurs.Entfernen();
            newkurs.informationAusgeben();
        }
        
        else
        {
        Student* student=new Student(prenom,nom,Matrikelnummer);
        newkurs.Einfuegen(student);
        newkurs.informationAusgeben();
        }
        
        
    }

    return 0;
}
