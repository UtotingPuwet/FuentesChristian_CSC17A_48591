/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 28, 2021. 6:43PM
 * Purpose:  Min and Max template functions
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int a,                                      //can change the data type to whatever your heart desires :)
        b;
    //Initialize Variables
    cout << "What is the first  number?\n";
    cin>>a;
    cout << "What is the second  number?\n";
    cin>>b;
    //Process or map Inputs to Outputs
    
    //Display Outputs
    cout << "The bigger number is: " << max(a,b) << endl;
    cout << "The smaller number is: " << min(a,b);
    //Exit stage right!
    return 0;
}

template <class Num>
Num max (Num a, Num b) {
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

template <class Num>
Num min (Num a, Num b) {
    if (a > b) {
        return b;
    }
    else {
        return a;
    }
}

