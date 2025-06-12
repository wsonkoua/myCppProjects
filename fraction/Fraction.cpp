#include "Fraction.h"
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
Fraction :: Fraction()
{
 numerator=0;
 denominator=1;
}
Fraction :: Fraction(int num, int denom)
{
 numerator=(num>0)? num:0;
 denominator=(denom>1)? denom:1;
}

string Fraction::toString() const {
    
stringstream Output;

Output  << ""<<numerator << "/" <<"" << denominator<< endl;

return Output.str();

}


void Fraction::read () {
cout<<"Zaehler : ";
    cin >> numerator;
    cout<<"Nenner : ";
cin >> denominator;
while (denominator==0)
{
cout<<"Nenner darf nicht Null sein!";
cout << "Nenner: ";
    cin >> denominator;
}
}

int Fraction::gcd(int p, int q) {
int r;
r = p % q;
while (r != 0)
{
p = q;
q = r;
r = p % q;
}
return q;
}
void Fraction::cancel() {
int gcdNumDenom = gcd(numerator, denominator);
numerator /= gcdNumDenom;
denominator /= gcdNumDenom;
}

void Fraction::format() {
if (denominator < 0) {
denominator = -1 * denominator;
numerator = -1 * numerator;
}
}

Fraction Fraction::add(const Fraction& f) {
Fraction newr;
newr.numerator = numerator*f.denominator + denominator*f.numerator;
 newr.denominator = denominator*f.denominator;
return newr;
}

Fraction Fraction::subtract(const Fraction& f) {
Fraction newr;
newr.numerator= numerator*f.denominator - denominator*f.numerator;
newr.denominator  = denominator*f.denominator;
return newr;

}

Fraction Fraction::multiply(const Fraction& f) {
 Fraction newr;
newr.numerator = numerator*f.numerator;
 newr.denominator = denominator*f.denominator;
return newr;
}
Fraction Fraction::divide(const Fraction& f) {
Fraction newr;
newr.numerator= numerator*f.denominator;
     newr.denominator = denominator*f.numerator;
     
return newr;


}
ostream& operator<<(ostream&  output , const Fraction& myfraction){
    
    Fraction newfraction= myfraction;
   
    newfraction.cancel();
     newfraction.format();
    //myfraction.toString();
    output<<newfraction.numerator<<"/"<<newfraction.denominator;
    
    return output;
    
    
}

istream& operator>>(istream& input , Fraction& myfraction){
   
   cout<< "Geben Sie den zähler ein: ";
   input>>ws;
   input>> myfraction.numerator;
   input.ignore();
   cout<< "Geben Sie den Nenner ein: ";
   input>> myfraction.denominator;
   while(myfraction.denominator==0){
       cout<<"Geben Sie nochmal den Nenner ein: ";
       input>> myfraction.denominator;
   }
   return input;
    
}


 Fraction  operator+(Fraction& myFraction1, Fraction& myFraction2){
    Fraction myResult;
    myResult=myFraction1.add(myFraction2);
    
    return myResult;
    
 }
 Fraction operator-(Fraction& myFraction1, Fraction& myFraction2){
     Fraction myResult;
     myResult=myFraction1.subtract(myFraction2);
     
     return myResult;
 }
 Fraction operator*(Fraction& myFraction1, Fraction& myFraction2){
     Fraction myResult;
     myResult=myFraction1.multiply(myFraction2);
     
     return myResult;
 }
 
 Fraction operator/(Fraction& myFraction1, Fraction& myFraction2){
     Fraction myResult;
     myResult=myFraction1.divide(myFraction2);
     
     return myResult;
 }
 

 
 bool Fraction::operator<(const Fraction& myfraction){
     
     double left= static_cast<double>(numerator)/denominator;
     double right= static_cast<double>(myfraction.numerator)/myfraction.denominator;
     
     return left<right;
 }