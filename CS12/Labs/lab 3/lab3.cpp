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

