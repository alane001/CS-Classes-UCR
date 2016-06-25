//----------------------------------------------------------------------------------------------
//DESCRIPTION

//In this PROGRAM, you will be solving linear Diophantine equations recursively.

//A linear Diophantine equation is an equation in the form: ax + by = c where a, b, and c are all integers and the
//solutions will also be integers.

//See the following entry in Wikipedia: Linear Diophantine equations.

//You will be solving this using the recursive version of the Extended Euclidean algorithm for finding the integers x and y
// in Bezout's identity:  ax + by = gcd(a,b)


//Required Recursive Function

/* Returns true if a solution was found and false if there is no solution.
   x and y will contain a solution if a solution was found.
   This function will NOT output anything.
*/
//bool diophantine(int a, int b, int c, int &x, int &y);



//Basic Algorithm

//If gcd(a,b) does not divide c, then there is no solution.

//If b divides a (the remainder of a / b is 0), then you can just divide by b to get the solution: x = 0, y = c / b.

//Otherwise (b does not divide a), through a substitution method, we can come up with a simpler version of the original
//problem and solve the simpler problem using recursion.

//Substitution method

//ax + by = c
//Now, we can define a as:  a = bq + r where q is (a / b) (using integer division) and r is the remainder (a % b).

//Substituting (bq + r) in for a now: (bq + r)x + by = c which is the same as b(qx + y) + rx = c and now we have
//the equation in the same form, only with smaller coefficients: bu + rv = c with u = qx + y and v = x.

//Finally, you recursively call your function on this simpler version of the original problem. Don't forget that this
//recursive call will actually solve for u and v in this case, so you still have to solve for x and y to get the solution
//to the original problem: x = v        y = u - qx



//Linear Diophantine Example

//Example showing steps of algorithm: https://docs.google.com/document/d/1NXw2edGf2e4Yoj2uylYiandqvVVUQJlhf9S4PVfxIcY/edit



//Input/Output Test Samples

//Here are some examples you can test your function on:

//| Input (a b c)      | Results (x y)
//| ------------------ | ------------
//| 28 7 490           | 0 70
//| 1024 96 2048       | -64 704
//| 11 11 2010         | No solution!
//| 1984 3070 1        | No solution!
//| 395 252 1          | -37 58
//| 25 38 2            | -6 4
//| 200 -2 4           | 0 -2
//| 25 75 100          | 4 0
//| 25 75 1000         | 40 0
//| 25 75 1            | No solution!
//| -10 -10 100        | 0 -10
//| 12 24 48           | 4 0
//| 5 -29 6            | 36 6

//----------------------------------------------------------------------------------------------



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
