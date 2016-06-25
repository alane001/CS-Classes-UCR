// This program plays a guessing game where you try to guess the number
// the computer has picked.

//----------------------------------------------------------------------------------------------------------
//DESCRIPTION
//In this exercise, you'll practice finding and fixing C++ syntax errors as well as some logic errors.
//You will also learn to generate random integers using the rand() function.

//----------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
   int seed;
   cout << "Random Seed?" << endl << "? ";
   cin >> seed;
   srand(seed);

   // This first gave 0-99, had to chnage it by adding 1 to get it from 1 to 100
   int numberToGuess = rand() % 100 + 1;

   cout << "Guess a number between 1 and 100." << endl << "? ";

   int guess;
   cin >> guess;

   while (numberToGuess != guess)
   {
      if (guess > numberToGuess)
      {
         cout << "Try lower." << endl << "? ";
      }
      else if (guess < numberToGuess)
      {
         cout << "Try higher." << endl << "? ";
      }
      cin >> guess;
   }

   cout << "You guessed right!!!" << endl;
   return 0;
}
