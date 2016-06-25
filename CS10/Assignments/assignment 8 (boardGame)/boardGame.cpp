//  =============== BEGIN ASSESSMENT HEADER ================
/// @file boardgame.cpp 
/// @brief Monte Carlo Method - Board Game
///
/// @author Test Student [alane001@ucr.edu]
/// @date June 1, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <cstdlib> // for random number generation 
#include <ctime> //to call time()
#include <vector> // to use vectors
using namespace std;

//@breif    simulates rolling N dice, each of which has the specified 
//          number of sides

//@param  both integer type, first numDice is the number of dice to roll, by
//        value, numSides is how many sides on each dice, by value
//@return    integer, the summation of all N dice rolls
int rollNDice(int numDice, int numSides) {
    int summation = 0, randomnum = 0;
    // This only executes if the number of dice is chosen is more than one
    if (numDice > 1) {
        //This loops for how ever many dice are chosen, if two is given
        //then it will loop twice getting a random number, then storing it,
        //then getting another random number and adding it to the number B4
        for (int i = 1; i <= numDice; ++i) {
            // looking at pig.cpp you will see the 1 here be small, but sense we 
            // are rolling die it will always be 1 here so just subed in one
            // the numSides represents the max (large) number on the die so it  
            // will be the same as large on pig.cpp
            // rand % 6 will never be higher than 5 so the plus one gives 6 if 
            // it is 5, this gives all of the possible values of the die
            randomnum = 1 + rand() % (numSides - 1 + 1);
            // This keeps track of the total sum of the rolls so if first roll 
            // is 2 and 2nd is 5 then summation would equal = 7
            summation += randomnum;
        }
    }
    else if (numDice == 1) {
        randomnum = 1 + rand() % (numSides - 1 + 1);
        // only one roll here so summation is just the value of the first 
        // random number generation
        summation = randomnum;
    }
    return summation;
    // TESTED IT WORKS
}



//@breif    returns the cell on the board with the most "landings", 
//          within an inclusive interval
//@param  first parameter: the game board vector,  by const reference
//@param   second parameter: the start of the interval to be tested, by value
//@param    third parameter: the end of the interval to be tested, by value
//@return    integer, the first cell in the interval with the most landings
int mostLandings (const vector<int> &value, int start, int end) {
    // had problem here with initalized to start instead of 0 here
    int maxCount = 0;
    int cellNumber = 0;
    if (end == 0) {
        cellNumber = start;
        return cellNumber;
    }
    if (start > end) {
        cellNumber = start;
        return cellNumber;
    }
    // THIS <= end IS CAUSING A PROBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // this loop goes through the vector of range specificed in the parameters
    for (int i = start; i <= end; ++i) {
        // Only updates values if the count is larger than the previous
        // not update if values are the same so it takes FIRST Cell w/ value
        // In here is causing the problem!!!!!!!!!!!!
        if (i >= value.size()) {
            i = i - 1;
            if (value.at(i) > maxCount) {
                maxCount = value.at(i);
                cellNumber = i;
            }
            i = i + 1;
        }
        else {
            if (value.at(i) > maxCount) {
                maxCount = value.at(i);
                cellNumber = i;
            }
        }
    }
    if (start == end){
        cellNumber = start;
        return cellNumber;
        }
    return cellNumber;
}


int main() {
    srand(time(0)); // CHANGE BEFORE R SUB TO TIME(0)!!!!!
    int numSidesBoard = 0, numSpotsBoard = 0, numSimulations = 0;
    cout << "How many sides of the board are there? ";
    cin >> numSidesBoard;
    cout << endl << "How many spots are on each side? ";
    cin >> numSpotsBoard;
    cout << endl << "How many simulations? ";
    cin >> numSimulations;
    //This is the first vector needed, it allocates the total number of spaces
    // needed for the game board depending on the # of sides and spots
    vector <int> board(numSidesBoard * numSpotsBoard);
    
    // This vector will be updated with the push_back function below
    vector <int> range;
    
    //need to determine the number of spots per side, the intervals
    // starts at position 1
    int start = 1;
    range.push_back(start);
    // this gives the end position of the first side
    // board.size() gives the size of the vector so if 
    // numsides * numspots where sides = 4 and spots = 10 = 40 then 40 / 4 = 10 
    // so each side has 10 values
    int end = board.size() / numSidesBoard;
    range.push_back(end);
    // this loop and above gets the ranges of the values depending on 
    // the size of the board picked, it can then uses these indivdual
    // values to send to the function mostLandings for the start and 
    // end interval to check for the highest count in that range
    // < numSidesBoard because already have the first side's values from above
    for (int side = 1; side < numSidesBoard; ++side) {
        // this adds one to the end value to make the new starting value
        start = 1 + end;
        range.push_back(start);
        // this makes the new end value
        end += (board.size() / numSidesBoard);
        range.push_back(end);
    }
    
    
    int totalSumation = 0;
    //This is the loop that will roll the dice and fill in the vector board,
    
    // THIS IS THE LOOP THAT WAS THROWING THE ERROR IN VECTOR
    // IT needed for the totalSumation to be less than not less than or equal
    // for both the while loop and for the if statement
    // so totalsumation < (numside * numSpots) instead of totalsumation <= (num
    // side *numSpot)
    // explained under for statement
    
    for (int i = 1; i <= numSimulations; ++i) {
        // The value was exactly numSides * numSpots on a certain simulation 
        // so it was updating the totalsumation value with another roll when it 
        // should have stoped, since it didnt stop then the last board.at(totalS
        // umation) was being updated at a range that was not valid, causing the
        // out_of_range error
        while (totalSumation < (numSidesBoard * numSpotsBoard)) {
            // this adds the value of total of the dice rolled to the last val
            // 2 and 6 b/c game uses 2 die and a 6 sided die, can change later
            totalSumation += rollNDice(2, 6);
            // CHANGED THIS TO NOT EQUAL TO !!!!!!!!!!!!!!!!!!!!!!!
            if (totalSumation < (numSidesBoard * numSpotsBoard) ) {
                // this incerments the boards vector value by one at the val
                // of the total sum at that point
                ++board.at(totalSumation);
            }
        }
        // to reset amount so that it can start over with new simulation
        totalSumation = 0;
    }
    
    
    //vector for storing the values of the cell with the most landings
    vector <int> landedMost;
    int outputLanded = 0;
    // do c+2 so that it can skip over the c+1 of the endrange
    // this loop will fill landedMost vector using the values obtained from 
    // the function mostLandings above
    for (int c = 0; c < range.size(); c = c + 2) {
        int startRange = 0, endRange = 0;
        startRange = range.at(c);
        endRange = range.at(c+1);
        //this will add the next value onto the end of vector landedmost
        landedMost.push_back(mostLandings (board, startRange, endRange));
    }
    
    
    cout << endl << "The following spots on each side have the most landings: "
    << endl;
    for (int d = 1; d <= numSidesBoard; ++d) {
        // landedmost at prints out the vector location in board that has the
        //most landings while board at (  ) prints out the value in board 
        // vector that keeps track of how many times it has landed on there
        cout << "On side " << d << ", spot " << landedMost.at(outputLanded)
        << " has the most landings: " << board.at(landedMost.at(outputLanded)) 
        << endl;
        // updates outputlanded so that it will output the next value in that 
        // vector making the values change everytime
        outputLanded += 1;
    }
    return 0;
}