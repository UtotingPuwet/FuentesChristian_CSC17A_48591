/*
    Author: Christian Fuentes
    Date:   September 1, 2021  11:07pm
    Purpose:
    Version:First
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>     //Manipulate Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    short month;
    int year;
    //Initialize variables
    cout << "Enter a month (1-12)\n";
    cin >> month;
    cout << "Enter a year:\n";
    cin >> year;
    
    if (month == 2 && year % 2 == 0 && year % 400 == 0) {
        cout << "29 days.";
    }
    else if (month == 2) {
        cout << "28 days.";
    }
    else if (month % 2 != 0 || month == 8 || month == 10 || month == 12) {
        cout << "31 days.";
    }
    else {
        cout << "30 days.";
    }
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
