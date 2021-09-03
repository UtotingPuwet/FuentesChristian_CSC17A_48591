/*
    Author: Christian Fuentes
    Date:   September 1, 2021  6:51pm
    Purpose:USD to Yen and Euros
    Version:First
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Manipulate Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only
const float EURO_PER_DOLLAR = 0.84;
const float YEN_PER_DOLLAR = 109.95;
//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float totUSD, totYEN, totEURO;
    //Initialize variables
    cout << "How much USD to convert?\n";
    cin>>totUSD;
    
    totEURO = totUSD * EURO_PER_DOLLAR;
    totYEN =  totUSD * YEN_PER_DOLLAR;
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    cout << fixed << setprecision(2);
    cout << "Your $" << totUSD << " dollars convert to €" << totEURO << " Euros.\n";
    cout << "Your $" << totUSD << " dollars convert to ¥" << totYEN << " Yen.\n";
    //Exit stage right
    return 0;
}
