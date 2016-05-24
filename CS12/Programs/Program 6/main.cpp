#include <iostream>

using namespace std;

bool diophantine(int a, int b, int c, int &x, int &y);
int gcd(int, int);

int main() {

    //cout << gcd(200, -2);

    int a, b, c, x, y;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}


bool diophantine(int a, int b, int c, int &x, int &y)
{
    bool answer = true;

    // cout << gcd(a,b) << "  " << c << "    " << gcd(a,b) % c << endl;
    // cout << a % b << endl;

    //had to add the a>0 part because of negative values being input
    //the gcd function I used requires that the inputs be non negative
    if(a > 0 && b > 0 && c % gcd(a,b) != 0)
    {
        answer = false;
    }
    else if(a % b == 0)
    {
        x = 0;
        y = c / b;
        answer = true;
    }
    else
    {
        int q = a / b;
        int r = a % b;

        //Equations being used
        //bu + rv = c
        //x = v
        //y = u - qx


        //have to recursive the values now where a = b, b = r and c = c now
        diophantine(b,r,c,x,y);
        //need to store x's value (which is u in reality)
        int swap;
        swap = x;

        //x = v part where y is v
        x = y;

        // y = u - qx where the x is the previous x = v part, swap is when x = u from previous
        y = swap - (q * x);

        // cout << "x: " << x << endl;
        // cout << "y: " << y << endl;
    }

    return answer;
}

//The greatest common divisor, using recursion
int gcd(int one, int two)
{
    //YOU must make sure the input results are not less than one
    int gcdVal = 0; // Holds GCD results

   if(one == two) {    // Base case: Numbers are equal
      gcdVal = one;       // Return value
   }
   else {                    // Recursive case: subtract smaller from larger
      if (one > two) { // Call function with new values
         gcdVal = gcd(one - two, two);
      }
      else {
         gcdVal= gcd(one, two - one);
      }
   }

   return gcdVal;
}
