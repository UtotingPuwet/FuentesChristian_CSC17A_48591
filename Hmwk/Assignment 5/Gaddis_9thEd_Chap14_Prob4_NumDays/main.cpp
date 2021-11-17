/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "NumDays.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    //Driver program to test all the classes operators. This shouldn't
    //be that hard to follow just adjust numbers according to what you want.
    NumDays a(8);
    NumDays b(12);
    NumDays c = a+b;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    cout << "a days = " << a.getDays() << " and hours are = " << a.getHour();
    cout << endl;
    cout << "b days = " << b.getDays() << " and hours are = " << b.getHour();
    cout << endl;
    cout << "c days = " << c.getDays() << " and hours are = " << c.getHour();
    
    c = b-a;
    //Display Outputs
    cout << endl;
    cout << "c days = " << c.getDays() << " and hours are = " << c.getHour();
    
    c++;
    cout << endl;
    cout << "c days = " << c.getDays() << " and hours are = " << c.getHour();
    
    c--;
    cout << endl;
    cout << "c days = " << c.getDays() << " and hours are = " << c.getHour();
    //Exit stage right!
    return 0;
}