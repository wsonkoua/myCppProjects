#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "MastermindDigits.h"

MastermindDigits::MastermindDigits(){
    digits=new int[4];
    makeDigitsToGuess();
  
}

MastermindDigits::MastermindDigits(int geheimzahl){
  
   setDigits(geheimzahl);
    
}
MastermindDigits::~MastermindDigits(){
    delete []digits;
}

void MastermindDigits::setDigits(int geheimz)
{
    
   int p=1000,q;
   digits=new int[4];
   for (int n=0;n<=3;++n){
   digits[n] = geheimz/p;
   q= geheimz/p;
   
   geheimz= (geheimz-p*q);
   
   p/=10;
   
   
   }
    
} 

void MastermindDigits::makeDigitsToGuess(){
  
   srand( (unsigned)time( NULL ) ); 
    for (int i = 0; i <=3; ++i ){
    digits[ i ]  =1 + rand()%6; 
    }
   
   }

int MastermindDigits::locationRight(const MastermindDigits& z){
    
    int i;
    int counterright; 
    counterright=0;
    for (i=0;i<=3;++i){
        if(digits[i]==z.digits[i]){
            counterright=counterright+1;
        }
    }
    
    return counterright;
}
int MastermindDigits::locationWrong(const MastermindDigits& z){
 int counterwrong=0;
 MastermindDigits tocompare;
 

 for(int i=0;i<=3;++i){
     tocompare.digits[i]=digits[i];
 }
      
for(int counter=0; counter<=3; ++counter){
        if (digits[counter] == z.digits[counter]) {
            z.digits[counter] = 0;
            tocompare.digits[counter] = 0;
        }
    }
   
    for(int n=0 ;n<=3;++n){
       for(int m=0;m<=3;++m){
           if ((z.digits[n] == digits[m] )&&(tocompare.digits[m] != 0)) {
                
                    counterwrong++;
                    tocompare.digits[m]=0;
                    z.digits[n]=0;
                
            }
       }
                 
            
             
    
    }
   
   
 return counterwrong;
    
}

bool MastermindDigits::isEqual(const MastermindDigits& z){
    
    int pruefer=0;
    for( int i=0;i<=3;++i){
        if(digits[i] == z.digits[i]){
            //return false;
            ++pruefer;
        }
    }
    if(pruefer==4){
    return true;
    }
    else{
        return false;
    }
}

