//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab3.cpp
/// @brief Lab 3
///
/// @author Test Student [alane001@ucr.edu]
/// @date April 12, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
using namespace std; 

int main()
{
   int ex;
   cout << "Which exercise? ";
   cin >> ex;
   cout << endl;
   if ( ex == 1 )
   {
      // All Exercise 1 code
      int first, second;
      cout << "Enter the first integer: ";
      // User enters first integer
      cin >> first;
      cout << endl << endl;
      // User enters second integer
      cout << "Enter the second integer: ";
      cin >> second;
      cout << endl << endl;
      // Math computations happens next
      cout << first << " + " << second << " = " << first + second << endl;
      cout << first << " * " << second << " = " << first * second << endl;
      cout << first << " / " << second << " = " << first / second << endl;
      cout << first << " % " << second << " = " << first % second << endl;
    
   }
   else if ( ex == 2 )
   {
      // All Exercise 2 code 
      double purchaseAmount, amountReceived;
      // User enters purchase amount
      cout << "Enter purchase amount: ";
      cin >> purchaseAmount;
      cout << endl << endl;
      // User enters amount received from customer
      cout << "Enter amount received: ";
      cin >> amountReceived;
      cout << endl << endl;
      // Computations for total change
      double totalChange;
      totalChange=amountReceived - purchaseAmount;
      cout << "Total Change: $" << totalChange << endl;
      cout << endl;
      // Break down of the change
      int totalPennies;
      // Convert change to amount of pennies
      totalPennies=static_cast<int>(totalChange*100+0.5);
      //Integer division
      int dollars, quarters, dimes, nickels, pennies;
      // Dollar amount
      dollars=totalPennies/100;
      totalPennies=totalPennies%100;
      cout << "dollars " << dollars << endl;
      // Quarter amount
      quarters=totalPennies/25;
      totalPennies=totalPennies%25;
      cout << "quarters " << quarters <<endl;
      // Dime amount
      dimes=totalPennies/10;
      totalPennies=totalPennies%10;
      cout << "dimes " << dimes << endl;
      // Nickel amount
      nickels=totalPennies/5;
      totalPennies=totalPennies%5;
      cout << "nickels " << nickels << endl;
      // Penny amount
      pennies=totalPennies/1;
      totalPennies=totalPennies%1;
      cout << "pennies " << pennies << endl;
   }
  
   return 0;
}
