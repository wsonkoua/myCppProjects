#include <iostream>
#include <string>
using namespace std;

class MastermindDigits{
    
  public:
        
        MastermindDigits();
        MastermindDigits(int);
        ~MastermindDigits();
        void makeDigitsToGuess();
        void setDigits(int);
        int locationRight(const MastermindDigits &); 
        int locationWrong(const MastermindDigits&);
        bool isEqual(const MastermindDigits &);
  private:
       int* digits;
};