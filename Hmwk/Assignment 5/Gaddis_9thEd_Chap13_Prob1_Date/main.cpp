/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 13, 2021
 * Purpose:  Date
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Date.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int month,
        day,
        year;
    char choice;
    //Initialize Variables
    
    
    cout << "Please input month (number).\n";
    cin>>month;
    while (month > 12 || month < 1) {                                       //validation check
        cout << "input valid month 1-12.\n";
        cin>>month;
    }
    cout << "Please input day (number).\n";
    cin>>day;
    while (day > 31 || day < 1) {                                           //validation check
        cout << "Input valid day 1-31.\n";
        cin>>day;
    }
    cout << "Please input year (number).\n";
    cin>>year;
    
    //Menu for how they want the date printed.
    cout << "Please input what format you want the date in:\n";
    cout << "Press 1 for Month/Day/Year.\nPress 2 for Month Day, Year.\n";
    cout << "Press 3 for Day Month Year.\n";
    cin>>choice;
    //Process or map Inputs to Outputs
    Date date(month,day,year);
    //Display Outputs
    switch (choice) {
        case '1': cout << date.getMnth() << '/' << date.getDay() << '/' << date.getYear() << '\n'; break;
        case '2': cout << date.getSmon() << ' ' << date.getDay() << ',' << ' ' << date.getYear() << '\n';break;
        case '3': cout << date.getDay() << ' ' << date.getSmon() << ' ' << date.getYear() << '\n';break;
    }
    //Exit stage right!
    return 0;
}