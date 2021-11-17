/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 16 2021, 11:28AM
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "MnthDay.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    string word;
    int day;
    //Initialize Variables
    cout << "What month?\n";
    cin>>word;
    cout << "What day?\n";
    cin>>day;
    //Process or map Inputs to Outputs
    MnthDay a(day,word);
    //Display Outputs
    cout << "Today is ";
    a.print();
    cout << endl;
    a++;
    cout << "Tomorrow is ";
    a.print();
    a--;
    cout << "Yesterday was ";
    a.print();
    //Exit stage right!
    return 0;
}