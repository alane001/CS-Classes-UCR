//--------------------------------------------------------------------------------------------------
//DESCRIPTION

//Distance Class

//The Distance class will represent a distance in some number of feet and inches. This Distance object must always be positive
//and never contain an inch value greater than or equal to 12 (12 inches equals 1 foot). It is your job, as the engineer/designer
// of this Distance class to make sure this is always true.

//Separate Files

//As is commonly done when designing a class, you are to separate your class from the program that will use the class.
// You will need the following 3 files:

//main.cpp: contains the main function and any other global functions used to test your Distance class.
//Distance.h: the Distance class header (aka interface) file. Contains the declaration of the Distance class.
//Distance.cpp: the Distance class implementation file. Contains the implementations of all Distance member functions.
//You will submit all 3 files, main.cpp, Distance.h and Distance.cpp.


//---------------------------------------------------------------------------------------------------


#include <iostream>

//Must include header file
#include "Distance.h"

using namespace std;

int main()
{
  Distance d1;
  cout << "d1: " << d1 << endl;

  Distance d2 = Distance(2, 5.9);
  Distance d3 = Distance(3.75);
  cout << "d2: " << d2 << endl;
  cout << "d3: " << d3 << endl;

  //test init helper function
  Distance d4 = Distance(5, 19.34);
  Distance d5 = Distance(100);
  cout << "d4: " << d4 << endl;
  cout << "d5: " << d5 << endl;

  //test add (<12 inches)
  cout << "d4 + d5: " << (d4 + d5) << endl;
  //test add (>12 inches)
  cout << "d2 + d4: " << (d2 + d4) << endl;

  //test sub (0 ft)
  cout << "d3 - d1: " << (d3 - d1) << endl;
  //test sub (0 ft, negative conversion)
  cout << "d1 - d3: " << (d1 - d3) << endl;

  //test sub (positive ft & inch)
  cout << "d4 - d2: " << (d4 - d2) << endl;
  //test sub (negative ft & inch)
  cout << "d2 - d4: " << (d2 - d4) << endl;

  //test sub (negative ft, positive inch)
  cout << "d4 - d5: " << (d4 - d5) << endl;
  //test sub (positive ft, negative inch)
  cout << "d5 - d2: " << (d5 - d2) << endl;

  return 0;
}
