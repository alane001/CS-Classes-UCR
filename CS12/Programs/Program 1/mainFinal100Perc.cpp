// Programming Assignment Number 1
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

void readData(const string& filename, vector<double>& angles, vector<double>& coefLift);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);


int main(){

    string filename;
    string answer = "yes";
    double userAng = 0.0;
    bool repeat = true;
    double finalAnswer = 0.0;

    cout << "Enter name of input data file:" << endl << endl;
    cin >> filename;

    vector<double> angles;
    vector<double> coefLift;
    readData(filename, angles, coefLift);


    if (!isOrdered(angles)){
        reorder(angles, coefLift);
    }

    while (repeat){
        cout << endl << "Flight path angle? ";
        cin >> userAng;

        if (userAng < angles.at(0) || userAng > angles.at(angles.size() - 1)){
            cout << "Error: Angle outside of range of data. Choose another angle.";
        }
        else {

            finalAnswer = interpolation(userAng, angles, coefLift);

            cout << "At angle: " << userAng << " the coefficient of Lift is ";
            cout << finalAnswer;

            cout << endl << "Do you want to enter another flight-path angle? ";
            cin >> answer;
            if (answer == "no"){
                repeat = false;
            }
        }
    }

return 0;
}

void readData(const string& filename, vector<double>& angles, vector<double>& coefLift){
    ifstream inFS;
    double angle = 0;
    double coefL = 0;

    inFS.open(filename.c_str());

    if (!inFS.is_open()){
       cout << "Error opening " << filename << endl;
        exit(1); //indicated error, use this instead of return 1; because cant
        //return a value in a void function
    }

    //get first input
    inFS >> angle;
    while (!inFS.eof()){

        //fills in vectors
        angles.push_back(angle);
        inFS >> coefL;
        coefLift.push_back(coefL);
        inFS >> angle;
    }
    // closes file
    inFS.close();
}

bool isOrdered(const vector<double>& angles){
    bool order = true;


    //This assures that if a vector of 0 size is input that it wont fail.
    if (angles.size() == 0){
        order = true;
    }
    else {
        for (unsigned i = 0; i < angles.size() - 1; ++i){
            if (angles.at(i) > angles.at(i + 1)){
                order = false;
                break;

            }
        }
    }

    return order;
}

void reorder(vector<double>& angles, vector<double>& coefLift) {
    double swapAng = 0.0;
    double swapLift = 0.0;

    //nested for loop so that it goes through multiple times to sort, the inside
    //for loop is what moves higher numbers up and top for loop makes sure
    //it goes through enough to change every higher number
    for (unsigned j = 0; j < angles.size(); ++j){
        for (unsigned i = 0; i < angles.size() - 1; ++i){
            if (angles.at(i) > angles.at(i + 1)){
                swapAng = angles.at(i);
                angles.at(i) = angles.at(i + 1);
                angles.at(i + 1) = swapAng;

                //even though coeflift does not need to be in ascending order
                //it must have the values kept with the angles correctly
                swapLift = coefLift.at(i);
                coefLift.at(i) = coefLift.at(i + 1);
                coefLift.at(i + 1) = swapLift;
            }
        }
    }

}


double interpolation(double userAng, const vector<double>& angles, const vector<double>& coefLift){
    double pol = 0.0;

    for (unsigned i = 0; i < angles.size(); ++i){
        if (angles.at(i) == userAng){

            pol = coefLift.at(i);
            break;
        }
    }

    for (unsigned i = 0; i < angles.size() - 1; ++i){

        if (userAng > angles.at(i) && userAng < angles.at(i + 1)){

            pol = coefLift.at(i) + (static_cast<double>((userAng - angles.at(i))) / (angles.at(i + 1) - angles.at(i)))*(coefLift.at(i + 1) - coefLift.at(i));
            //this breaks the loop once the correct position is found, more efficient
            break;

        }
    }

    return pol;

}

