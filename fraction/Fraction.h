
#include <iostream>
using namespace std;

#ifndef Fraction_H

#define Fraction_H

class Fraction {
    
friend  ostream& operator<<(ostream&, const Fraction&);
friend  istream& operator>>(istream&, Fraction&);

public:
Fraction();
Fraction(int , int ); // auch Standardkonstruktor!
bool operator<(const Fraction&);
string toString() const;

friend  Fraction operator+(Fraction&, Fraction&);
friend  Fraction operator-(Fraction&, Fraction&);
friend  Fraction operator*(Fraction&, Fraction&);
friend  Fraction operator/(Fraction&, Fraction&);


private:
int gcd(int p, int q);
void read();
void cancel();
void format();
int numerator;
int denominator;
Fraction add(const Fraction& f);
Fraction subtract(const Fraction& f);
Fraction multiply(const Fraction&f );
Fraction divide(const Fraction& f);

};
#endif 

