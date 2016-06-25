//----------------------------------------------------------------------------------------------
//DESCRIPTION

//RATIONAL NUMBERS

//It may come as a bit of a surprise when the C++ floating-point types (float, double), fail to capture a particular value
//accurately. Certainly double, which is usually stored as a 64-bit value, is far better than the old float, which is only 32
//bits, but problems do arise. For example:

//float n = 2.0;
//float d = 3.0;
//cout << precision(17);
//cout << n / d << endl;
//produces 0.6666668653488159, which is accurate to only 8 decimal places - a bit dirty for a discipline that prides itself on
//precision!

//A solution that is often used when precision is of greatest importance and all of the numbers involved are going to be "rational"
// (that is, expressible as a 'ratio' of two integers - i.e. a fraction) is to use a custom data type - i.e. a class - that
//implements fractions, or "rational numbers". This is what you will do in this lab assignment.

//CLASS SPECIFICATION

//Write a C++ program that performs the rational number operations addition, subtraction, multiplication and division on two
//fractions. The program should be written in a single file. You will need to design a "rational number" class named Rational
//whose value will be a fraction (e.g., 1/128, or 22/7), with appropriate constructors and member functions. A fraction will be
// specified as a numerator and a denominator - e.g. the pair (8, 109) represents the fraction 8/109. The member variables should
//be private and accessed using the accessor and mutator functions.

//CONSTRUCTORS

//Create 3 constructors: * a constructor with two parameters (numerator and denominator) * a constructor with one parameter
//(denominator set to 1) * a constructor with no parameters (0/1)

//ACCESSOR FUNCTIONS

//add
//subtract
//multiply
//divide
//display
//The following are a list of the rules of arithmetic for fractions:

//(a/b) + (c/d) = (ad + bc) / (b*d)
//(a/b) - (c/d) = (ad - bc) / (b*d)
//(a/b) * (c/d) = (ac) / (bd)
//(a/b) / (c/d) = (ad) / (cb)
//Note that for this lab, when you perform an operation, you do not need to simplify the resulting fraction,
//i.e., 4/5 * 5/10 = 20/50. You should not simplify this to 2/5 at this point.

//The display function should output the Rational object in the format:  n / d

//----------------------------------------------------------------------------------------------


#include <iostream>
#include <string>

using namespace std;

class Rational
{
   private:
      int numerator;
      int denominator;
   public:
      Rational();
      Rational(int);
      Rational(int, int);
      const Rational add(const Rational &) const;
      const Rational subtract(const Rational &) const;
      const Rational multiply(const Rational &) const;
      const Rational divide(const Rational &) const;
      void display() const;
      int getNumerator() const;
      int getDenominator() const;
};

//function definitions go after here

Rational::Rational(){
    numerator = 0;
    denominator = 1;

    return;
}

Rational::Rational(int num){
    numerator = num;
    denominator = 1;

    return;
}

Rational::Rational (int num, int denom){
    numerator = num;
    denominator = denom;

    return;
}
// Had to add these in order to get the Rational R numerator and denominator, CAUSED LARGE PROBLEM
//Had to add the const on the end in order to use it in  the const Rational function add/subtract etc...
int Rational::getNumerator() const
{
    return numerator;
}

int Rational::getDenominator() const
{
    return denominator;
}


// Store each numerator and denominator in individual variables in order to pass it to the Rational function which stores them
//as numerator and denominator in new Rational object
const Rational Rational::add(const Rational & R) const{
    int a = (numerator * R.getDenominator()) + (denominator * R.getNumerator());
    int b = (denominator * R.getDenominator());

    return Rational(a, b);
}

const Rational Rational::subtract(const Rational & R) const{
    int a = (numerator * R.getDenominator()) - (denominator * R.getNumerator());
    int b = (denominator * R.getDenominator());

    return Rational(a, b);
}

const Rational Rational::multiply(const Rational & R) const{
    int a = numerator * R.getNumerator();
    int b = denominator * R.getDenominator();

    return Rational(a, b);
}

const Rational Rational::divide(const Rational & R) const{

    int a = numerator * R.getDenominator();
    int b = denominator * R.getNumerator();

    return Rational(a, b);
}

void Rational::display() const{
    cout << numerator << " / " << denominator;
}


//main body - do not alter anything below here

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   int choice;

   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;

   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;

   cout << "Enter Operation (1 - 4):" << endl
      << "1 - Addition (A + B)" << endl
      << "2 - Subtraction (A - B)" << endl
      << "3 - Multiplication (A * B)" << endl
      << "4 - Division (A / B)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 2) {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 3) {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 4) {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;

   return 0;
}

Rational getRational() {
   int choice;
   int numer, denom;

   cout << "Which Rational constructor? (Enter 1, 2, or 3)" << endl
      << "1 - 2 parameters (numerator & denominator)" << endl
      << "2 - 1 parameter (numerator)" << endl
      << "3 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational &rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

