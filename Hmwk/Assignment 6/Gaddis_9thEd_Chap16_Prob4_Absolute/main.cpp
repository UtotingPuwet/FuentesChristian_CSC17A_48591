/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 28, 2021. 6:43PM
 * Purpose:  Absolute value template functions
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables

//Function Prototypes
template <class Num>
Num absolte (Num a) {
    if (a < 0) {
        return a*-1;
    }
    return a;
}
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int a;
    //Initialize Variables
    cout << "What number do you want the absolute value of?\n";
    cin>>a;
    //Process or map Inputs to Outputs
    
    //Display Outputs
    cout << "The absolute value of " << a << " is " << absolte(a) << '\n';
    //Exit stage right!
    return 0;
}