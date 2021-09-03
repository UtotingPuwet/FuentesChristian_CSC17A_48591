/*
    Author: Christian Fuentes
    Date:   September 1, 2021  11:40pm
    Purpose:Population changes
    Version:First
 */

//System Libraries
#include <iostream>    //Input/Output Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float   organs,
            inc,
            total;
    int days;
            
    //Initialize variables
    cout << "How many starting organisms?\n";
    cin >> organs;
    while (organs < 2) {
        cout << "Must have more than 2 starting organisms.\n";
        cin >> organs;
    }
    
    cout << "How much does it  increase by? (in %)\n";
    cin >> inc;
    while (inc < 0) {
        cout << "Increase cannot be negative.\n";
        cin >> inc;
    }
    
    cout << "How many days?\n";
    cin >> days;
    while (days < 1) {
        cout << "Days cannot be less than 1.\n";
        cin >> days;
    }
    
    inc = inc/100;
    inc = inc + 1;
    
    total = 0;

    //Process, map inputs to outputs
    for (int i = 1; i <= days; i++) {
        organs = organs*inc;
        total = organs;
    }
    //Display your initial conditions as well as outputs.
    cout << "The  population will be " << total;
    //Exit stage right
    return 0;
}
