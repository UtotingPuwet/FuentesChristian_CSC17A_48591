/*
    Author: Christian Fuentes
    Date:   September 1, 2021  6:49pm
    Purpose:USD to Euros and Yen
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
    float fah, cel;
    //Initialize variables
    cout<<"What is the temperature in Celsius?\n";
    cin >> cel;
    fah = ((9.0/5.0)*cel) + 32.0; 
    //Process, map inputs to outputs
    cout << fah;
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
