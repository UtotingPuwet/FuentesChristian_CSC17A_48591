/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 16 12:02 AM
 * Purpose:  Numbers converter.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Num.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int n;
    //Initialize Variables
    cout << "What number would you like to see in English form? (1-999).\n";
    cin>>n;
    while (n > 999 || n < 1) {
        cout << "Please input valid number.\n";
        cin>>n;
    }
    Num num(n);
    //Process or map Inputs to Outputs
    num.print();
    //Display Outputs

    //Exit stage right!
    return 0;
}