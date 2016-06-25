//----------------------------------------------------------------------------------------------
//DESCRIPTION
//For this PROGRAM you will calculate the coefficient of lift for a given flight-path angle
//based on wind tunnel data stored in a file.

//STEPS
//Ask the user for the name of file that contains the wind tunnel data.
// 1. Read wind-tunnel data into two parallel vectors, one vector stores the flight-path angle and the other stores the
//    corresponding coefficient of lift for that angle. Both vectors should store doubles.
// 2. Ask the user for a flight-path angle. If the angle is within the bounds of the data set, the program should then
//    use linear interpolation (see explanation of linear interpolation below) to compute the corresponding coefficient
//    of lift and output it.
// 3. Finally, ask the user if they want to enter another flight-path angle. Repeat steps 3 and 4 if they answer yes,
//    otherwise end the program if they answer no.

//For linear interpolation to work, the flight-path angles in the data file must be in ascending order. If the flight-path
//angles are not in ascending order, your program will need to sort them before implementing Step 3.

//LINEAR INTERPOLATION
//The wind-tunnel test data consists of some number of tested flight-path angles and their corresponding coefficient of lift.
//Using this data, we can estimate, using linear interpolation, the coefficient of lift for a flight-path angle within the
//bounds of the data set, even if that particular flight-path angle was not tested. If we want to find the coefficient of lift
//for flight-path angle b, we find flight-path angles a and c such that a < b < c.

//Obviously, if flight-path b already exists in the given data set, then you do not need to use linear interpolation.
//However, if it doesn't exist, then linear interpolation assumes a straight line exists between f(a) and f(c).
//(In this case, f(a) is the coefficient of lift for flight-path angle a and f(c) is the coefficient of lift for flight-path
//angle c.) To find f(b), use the formula:    f(b) = f(a) + (b - a)/(c - a)(f(c) - f(a))


//DATA FILE FORMAT
//The data file will have on each line, one flight-path angle (in degrees), a space, and then the corresponding coefficient of
//lift. See the following file examples, tunnel1.dat and tunnel2.dat. You must create these 2 files and turn them in with your
// program. Use these files to help you test your program, but do not assume these will be the only files we will test
//your program with. In other words, when testing your program you should also make up your own data files. You should try to
// come up with data files that will break your program if it doesn't follow all of the given specifications. That's what we
//will be doing when grading it.

//----------------------------------------------------------------------------------------------


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


// readData passes in the name of a file and two vectors (double) and stores in the first vector the flight-path angles (first column)
//and in the second vector the corresponding coefficients of lift (2nd column). If the file does not open properly, this function
// should output an error message and then call the exit function passing it an exit value of 1.
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


// isOrdered passes in the vector of flight-path angles and returns true if it stores the angles are in ascending order,
//otherwise returns false.
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


// reorder passes in both vectors of data and then reorders the data so that the flight-path angles are in ascending order while
//maintaining the correspondence between the flight-path angles and their corresponding coefficients of lift.
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


// interpolation  passes in the requested flight-path angle along with the 2 vectors of data (flight-path angles and corresponding
// coefficients of lift) and returns the corresponding coefficient of lift.
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

