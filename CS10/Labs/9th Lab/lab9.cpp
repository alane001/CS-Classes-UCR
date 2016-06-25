//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab9.cpp
/// @brief Lab 9
///
/// @author Test Student [alane001@ucr.edu]
/// @date May 23, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void fillVector(vector <double> &);
double average(const vector <double> &);
double standardDeviation(vector <double> );

int main()
{
    // Used to test average function
    //vector <double> v(5);
    //for (int i = 0; i < 5; ++i) {
    //    double a;
        //cin >> a;
        //v.at(i) = a;
    //}
    //cout << average(v);

    // Used to test both functions
    //vector <double> v(5);
    //for (int i = 0; i < 5; ++i) {
    //    double a;
    //    cin >> a;
    //    v.at(i) = a;
    //}
    //cout << average(v) << " " << standardDeviation(v);\

    // This is the test harness to test the functions!!!!!!!!!!!!!!!!!!!
    // I'm not sure why the zero next to aec but output shows that it will add
    // zeros for each number more so it is only correct when it is like this
    vector <double> aec(0);
    fillVector(aec);
    // This shows the values stored in each part of vector to test fillVector
    for (int i = 0; i < aec.size(); ++i) {
        cout << aec.at(i);
    }
    // This shows the values of the other functions to see if correct
    // Cant use == 30.0 the complier wont accept it
    if (average(aec) >= 30.0) {
        cout << "Passed ";
        cout << average(aec) << " ";
        cout << standardDeviation(aec);
    }
    else {
        cout << "Failed";
        cout << average(aec);
    }
    return 0;
}

void fillVector(vector <double> &v)
{
    double d;
    while (cin >> d)
    {
        v.push_back(d);
    }
}

double average(const vector <double> &v)
{
    double sum = 0.;
    // This sums all of the values in the vector
    for (int i = 0; i < v.size(); i++)
    {
        sum += v.at(i);
    }
// this returns the ave because takes full sum and divides it by num of values
    return sum / v.size();
}
// dont not want pass by reference here because dont want them to change
double standardDeviation(vector <double> v)
{
    // Make sure to initialize the values to FLOATING POINT not integers
    double subtract = 0.0, division = 0.0;
    // This is used to calc the top portion of the stdev, each value minus
    // the mean of all the values then squared, use for loop so that it uses
    // every value in the vector starting at 0 up to last num in vector
    // the .at(i) gives the specific vector depending on the loop number
    // the average(v) calls the average function and uses value each time
    // need += so that it updates the value for each added value, look in notes
    for (int i = 0; i < v.size(); ++i) {
        subtract += (v.at(i) - average(v)) * (v.at(i) - average(v));
    }
    // this divides the top portion but the total number of values
    division = subtract / v.size();
    // this returns the squareroot of the above math, which is the
    // standard deviation
    return sqrt(division);
}
