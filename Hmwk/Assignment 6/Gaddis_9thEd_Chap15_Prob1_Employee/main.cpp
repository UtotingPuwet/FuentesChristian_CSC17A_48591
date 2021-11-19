/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 18, 2021 12:04 AM
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "Employe.h"
#include "ProdWork.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int shift;
    float pay;
    string name;
    string date;
    int id;
    //Initialize Variables
    cout << "Please input 1 if you work day shift or 2 if you work night shift.\n";
    cin>>shift;
    cout << "Please enter hourly pay rate.\n";
    cin>>pay;
    cin.ignore();
    cout << "Please input your name\n";
    getline(cin,name);
    cout << "Please enter the date you joined this company.\n";
    getline(cin,date);
    cout << "Please enter your ID.\n";
    cin>>id;
    //Process or map Inputs to Outputs
    ProdWork worker(shift,pay);
    worker.setName(name);
    worker.setHire(date);
    worker.setId(id);
    //Display Outputs
    cout << "\n\n\n\n";
    cout << worker.getName() << endl;
    cout << worker.getHire() << endl;
    cout << worker.getId() << endl;
    cout << worker.getShft() << endl;
    cout << worker.getPay() << endl;
    //Exit stage right!
    return 0;
}
