// This program implements the Monte Carlo Method for estimating the value of PI.

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// given the coordinates of a point (x,y) computes if the point is inside the circle
// centered at origin with radius r. Returns 'true' if it is inside, 'false' otherwise.
bool isInside(double x, double y, double r)
{
   double left, R;
   bool answer;
   left = pow(x,2) + pow(y,2);
   R = pow(r,2);
   //cout << "left =" << left << "  R=" << R;
   //if > then outside circle
   if (left > R){
       answer = false;
   }
   else{
       answer = true;
   }
   return answer;
}

// given s, the size of the side of a square that is centered at the origin,
// chooses a random coordinates inside the square, and calls isInside function
// to test if the point is inside the circle or not.
bool throwDart(int s)
{
   int x, y;
   // assign x and y to two random integers between -s/2 and s/2
   // difficulty came from the rand() giving only from -9 to 10, once put perenthesis then it worked (s+1) stuff
   x = (rand() % (s + 1)) - s/2;
   y = (rand() % (s + 1)) - s/2;
   //cout << endl << "x =" << x << "    " << "y= " << y;

   //Call the isInside function and return its output.
   //You do not have to cast x & y to doubles, it is done automatically.
   return isInside(x, y, s/2.0);

}

int main()
{
   srand(333);
   int side; // this is the side of the square and is also our resolution.
   int tries;  // this is the number of tries.

   //Ask the user for the size (integer) of a side of the square
   cout << "Size (integer) of a side of the square?";
   //Get the users input using cin
   cin >> side;

   //Ask the user for the number of tries using cout.
   cout << "Number of tries?";

   //Get the users input using cin.
   cin >> tries;


   double inCount = 0, outCount = 0; //counter to track number of throws that fall inside the circle

   for(int i = 0; i < tries; ++i)
   {
      //throw a dart using throwDart method and increment the counter depending on its output.
      if (throwDart(side) == true){
         inCount = inCount + 1;
      }
      else{//if (throwDart(side) == false) {
         outCount = outCount + 1;
      }
      //cout << endl << inCount << "    " << outCount;

   }
  outCount = outCount + inCount;

   //Compute and display the estimated value of PI. Make sure you are not using integer division.
   double pi;
   //must double cast to get correct division
   //cout << endl << inCount << "    " << outCount;
   pi = 4 * (static_cast<double>(inCount) / outCount);
   cout << pi << endl;


   return 0;
}
