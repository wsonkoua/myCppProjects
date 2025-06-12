
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
#include "Fraction.h"

int main() {
// local variables!
Fraction f1, f2, result;

vector< Fraction > myFractions;

cin >> f1;

cin >> f2;

myFractions.push_back(f1);

myFractions.push_back(f2);

cout << "\nErster Bruch: " << f1;

cout << "\nZweiter Bruch: " << f2;

result = f1 + f2;

myFractions.push_back(result);

cout << "\n\nAddition: " << result;

result = f1 - f2;

myFractions.push_back(result);

cout << "\nSubtraktion: " << result;

result = f1 * f2;

myFractions.push_back(result);

cout << "\nMultiplikation: " << result;
result = f1 / f2;
myFractions.push_back(result);
cout << "\nDivision: " << result;

sort(myFractions.begin(),myFractions.end());

cout << "\n\naufsteigend sortiert: ";
for (const auto& frac : myFractions) {

cout << frac << '\t';
}

cout << endl << endl;
}
