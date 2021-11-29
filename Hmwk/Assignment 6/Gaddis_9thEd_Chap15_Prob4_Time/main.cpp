/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 26, 2021. 4:57PM
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Time.h"
#include "MilTime.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    short hours,
          sec;
    //Initialize Variables
    cout << "What time is it in military time?(Hours only and minutes, no spaces)\n";
    cin>>hours;
    cout << "How many seconds?\n";
    cin>>sec;
    //Process or map Inputs to Outputs
    MilTime time(hours,sec);
    //Display Outputs
    cout << "Standard time is: \n";
    cout << time.getHour() << ' ' << time.getMin() << ' ' << time.getSec() << endl;

    cout << "Military time is: \n";
    cout << time.getMilH() << ' ' << time.getMilS();
    //Exit stage right!
    return 0;
}