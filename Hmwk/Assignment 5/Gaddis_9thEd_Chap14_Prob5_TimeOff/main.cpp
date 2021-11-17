/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 16 2021, 10:10PM
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "TimeOff.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int hours,
            id;
    string name;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    cout << "Please input your name.\n";
    getline(cin,name);
    cout << "Please input your ID.\n";
    cin>>id;
    TimeOff employee(id,name);
    
    cout << "Please input amount of vacation work hours you took.\n";
    cin>>hours;
    employee.vacTkn(hours);
    
    cout << "Please input max amount of vacation work hours.\n";
    cin>>hours;
    employee.maxVac(hours);
    
    cout << "Please input amount of sick work hours you took.\n";
    cin>>hours;
    employee.sickTkn(hours);
    
    cout << "Please input max amount of sick work hours.\n";
    cin>>hours;
    employee.maxSck(hours);
    
    cout << "Please input amount of unpaid leave you took.\n";
    cin>>hours;
    employee.unpTkn(hours);
    
    cout << "Please input amount of maximum unpaid leave.\n";
    cin>>hours;
    employee.maxUnp(hours);

    
    cout << '\n' << '\n' << '\n';
    
    
    
    
    //Display Outputs
    cout << "Your name is " << employee.getName() << " and your ID is " << employee.getId() << endl;
    cout << "Your vacation days took is " << employee.getVcTk() << " and max is " << employee.getMxVc() << endl;
    cout << "Your  sick days took is " << employee.getSkTk() << " and max is " << employee.getMxSk() << endl;
    cout << "Your unpaid leave days took is " << employee.getUnTk() << " and max is " << employee.getMxUn() << endl;
    
    
    //Exit stage right!
    return 0;
}