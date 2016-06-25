//  =============== BEGIN ASSESSMENT HEADER ================
/// @file mathematics.cpp
/// @brief Mathematics
///
/// @author Test Student [alane001@ucr.edu]
/// @date May 24, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/// @brief acquire the proper number of numeric inputs based on operation string
///
///     The numeric inputs are set into x, y, and z in that order;
///     the number of numeric inputs acquired is returned to the caller.
///     Not all operations require all three values:
///         do not set operands that are not needed.
///
/// @param op the operation to be performed such as division
/// @param x the first numeric input
/// @param y the second numeric input
/// @param z the third numeric input
/// @return the number of numeric inputs that were acquired
int acquireOperands(const string & op, double & x, double & y, double & z) {
    // This functions job is to get input depending on which operation is
    // chosen, it restricts the number of numbers used as well
    // It returns the number of inputs used which isnt!!!! used again in main
    int numberNumInputs;
    if (op == "division") {
        cout << "Enter your first number: ";
        cin >> x;
        cout << endl << "Enter your second number: ";
        cin >> y;
        cout << endl;
        numberNumInputs = 2;
    }
    else if (op == "pythagorean") {
        cout << "Enter your first number: ";
        cin >> x;
        cout << endl << "Enter your second number: ";
        cin >> y;
        cout << endl;
        numberNumInputs = 2;
    }
    else if (op == "quadratic") {
        cout << "Enter your first number: ";
        cin >> x;
        cout << endl << "Enter your second number: ";
        cin >> y;
        cout << endl << "Enter your third number: ";
        cin >> z;
        cout << endl;
        numberNumInputs = 3;
    }
    return numberNumInputs;
}

/// @brief calculate quotient for provided values (a/b); returns error code
///
/// @param a the dividend of the equation
/// @param b the divisor of the equation
/// @param result reference to place the quotient in
/// @return returns the integer representing the state of the calculation
///         using global constants for OK and DIV_ZERO
int division(double a, double b, double &result) {
    // If error is equal to one then output error message in main (divide by 0)
    // if error equal to zero then OK
    // only result is a pass by reference so that it may be passed out of funct
    int error;
    if (b == 0) {
        error = 1;
    }
    else {
        result = a / b;
        error = 0;
    }
    // returns error integer relating to specific error
    return error;
}

/// @brief calculate the roots to the quadratic formula for a polynomial of
///     the form a*x^2 + b*x + c = 0; returns error code when necessary.
///
/// @param a the coefficient of x^2 in the polynomial equation
/// @param b the coefficient of x in the polynomial equation
/// @param c the last value of the polynomial equation
/// @param root1 reference for the first root of the quadratic formula
/// @param root2 reference for the second root of the quadratic formula
/// @return returns the integer representing the state of the calculation
///         using global constants for OK, DIV_ZERO, and SQRT_ERR
int quadratic(double a, double b, double c, double &root1, double &root2) {
    //return error: 0=OK 1=DIV_ZERO 2=SQRT_ERR
    //Using the equation => -b+-sqrt(b^2 - 4ac) / 2a
    // a,b,c are pass by values and roots are by reference so thats why
    // roots are initialized so that they may be passed out of function after
    int error;
    double fourAC, insideSqRt, squareRoot;
    fourAC = 4*a*c;
    insideSqRt = (b*b) - fourAC;
    squareRoot = sqrt(insideSqRt);
    if (a == 0) {
        // error one means dividing by zero
        error = 1;
    }
    // Gives error code square rooting a negative # to give imaginary number
    // this checks if squareRoot is negative
    else if (insideSqRt < 0) {
        error = 2;
    }
    else {
        // Must do both roots, one where its adding and one its subtracting
        // because of the plus/minus nature of the equation
        // error zero means no problems
        error = 0;
        root2 = (-b + squareRoot) / (2*a);
        root1 = (-b - squareRoot) / (2*a);
    }
    return error;
}

/// @brief calculate c for the pythagorean theorem a^2 + b^2 = c^2
///
/// @param a the value of a in the equation
/// @param b the value of b in the equation
/// @param c reference for the hypotenuse value
/// @return returns the integer representing the state of the calculation
///         using global constant for OK
int pythagorean(double a, double b, double &c) {
    // No possible errors here to 0=OK the whole time
    // c is pass by reference so that it may be passed out of funct w/o return
    // statement, only returns integers based on error
    int error = 0; // because no errors possible
    c = sqrt((a * a) + (b * b));
    return error;
}

int main() {
    string operChoice;
    int correctOperation = 0;
    // These are the values to pass in the functions, must be double
    // newResult is for pythagorean, root 1/2 are for quadratic
    double x, y, z, newResult, root1, root2;
    // This causes a loop until a correct operation is chosen
    while (correctOperation != 1) {
        cout << "Please choose an operation: ";
        cin >> operChoice;
        cout << endl;
        if (operChoice == "division" || operChoice == "pythagorean" ||
        operChoice == "quadratic") {
            correctOperation = 1;
        }
        else {
            correctOperation = 0;
            cout << "Error: Operation not supported." << endl;
        }
    }
    // This calls function allowing user to enter numbers they want to use
    // operChoice is the input from above and x, y, z are reference parameters
    // that get changed as they input from the function
    // not all x-z are used in every operation, they are updated by reference
    // so these are junk values going in and and updated to used values
    // by reference
    // MUST BE BEFORE ANY OTHER FUNCTION SO x,y,z ARE CORRECT VALUES FIRST
    acquireOperands(operChoice, x, y, z);
    // using if statements allows for only the chosen operation to execute
    if (operChoice == "division") {
        // This call does the required math so that values are updated by
        // reference before you use them in the output, without a
        // return statement in the function. MUST BE LOCATED HERE
        // x, y are updated from acquireOperands function B4 so that they
        // compute the correct numbers chosen by users
        division(x, y, newResult);
        cout << "Equation: " << x << " / " << y << endl;
        //This outputs error if the function returns 1, meaning divide by zero
        if (division(x, y, newResult) == 1) {
            cout << "Error: Cannot divide by zero." << endl;
        }
        else {
            // This outputs the value updated by reference into declare variable
            // in main newResult which is &result in division function
            cout << "Result: " << newResult << endl;
        }
    }
    else if (operChoice == "pythagorean") {
        //Calls function first so that update by reference occurs first B4 out
        // x, y updtated by acquireOperands function, that why that funct is 1st
        // newResult is same as c in actual function, not just copy because it
        // can be updated since pass by reference
        pythagorean(x, y, newResult);
        // No possible errors here so no if/else statements required
        cout << "Equation: sqrt(" << x << "^2 + "<< y << "^2) "  << endl;
        cout << "Result: " << newResult << endl;
    }
    else if (operChoice == "quadratic") {
        // all variables are declared above at begining of main
        // x,y,z are from the acquireOperadns function, these are pass-by-value
        // so they are not changed once passed to quad function
        // root1/2 are updated by reference so they are changed by function,
        // allowing 2 values to be passed out without a return statement
        quadratic(x, y, z, root1, root2);
        cout << "Equation: " << x << "x^2 + " << y << "x + " << z << " = 0";
        cout << endl;
        // if function returns the error code of one means divide by zero
        if (quadratic(x, y, z, root1, root2) == 1) {
            cout << "Error: Cannot divide by zero." << endl;
        }
        // this provides the error when you try to squareroot a neg number
        else if (quadratic(x, y, z, root1, root2) == 2) {
            cout << "Error: Cannot take square root of a negative number.";
            cout << endl;
        }
        // this outputs the updated by reference root1/2 from function
        else {
            // these if/else used so that if the roots are the same
            // only one result will be output vs. two
            if (root1 != root2) {
                cout << "Result: " << root1 << ", " << root2 << endl;
            }
            else {
                cout << "Result: " << root1 << endl;
            }
        }
    }
    // ONLY ONE OF THESE FUNCTIONS OPERATE EACH RUN
    // ALL x,y,z values are updated by aquireOperands function before any of
    // these functions are invoke, this allows correct values to be used
    // Most of them use pass by value - which are just copies of the specificed
    // values (x,y,z), the results are the ones updated by pass by reference
    // Pass by refernece takes a declared variable in main, sends it to a funct
    // then updates that same variable using value in funct, IT IS NOT A COPY
    // like in pass by value

    return 0;
}
