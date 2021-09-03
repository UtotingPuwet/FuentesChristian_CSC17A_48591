/*
    Author: Christian Fuentes
    Date:   September 2,2021  12:26pm
    Purpose:Fahrenheit to Celsius
    Version:First
 */

//System Libraries
#include <iostream>    //Input/Output Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


//Function Prototypes
float celsius (float f);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    float f, c;
    //Initialize variables
    cout << "Give temperature in Fahrenheit.\n";
    cin >> f;
    //Process, map inputs to outputs
    c = celsius(f);
    //Display your initial conditions as well as outputs.
    cout << c << "\n \n \n";
    cout << "Table for Fahrenheit temperatures 0-20.\n";
    cout << "F    C\n";
    
    for (int i = 0; i <= 20; i++) {
        cout << i << " = " << celsius(i) << '\n';
    }
    //Exit stage right
    return 0;
}

float celsius (float f) {
    return (5.0/9.0)*(f - 32);
}