#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void fillVector(vector <double> &);
double average(const vector <double> &);

int main()
{
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
    for (int i = 0; i < v.size(); i++)
    {
        sum += v.at(i);
    }

    return sum / v.size();
}
