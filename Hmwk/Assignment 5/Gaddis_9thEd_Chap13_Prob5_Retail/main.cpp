/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "Item.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    string desc;
    float  price;
    int    units;
    //Initialize Variables
    cout << "Enter description for first item.\n";
    cin>>desc;
    cout << "Enter price for first item.\n";
    cin>>price;
    cout << "Enter amount of units for first item.\n";
    cin>>units;
    //Process or map Inputs to Outputs
    Item item1(desc,units,price);
    
    //Do the same for second
    //Initialize Variables
    cout << "Enter description for second item.\n";
    cin>>desc;
    cout << "Enter price for second item.\n";
    cin>>price;
    cout << "Enter amount of units for second item.\n";
    cin>>units;
    //Process or map Inputs to Outputs
    Item item2(desc,units,price);
    
    //Do the same for third
    //Initialize Variables
    cout << "Enter description for third item.\n";
    cin>>desc;
    cout << "Enter price for third item.\n";
    cin>>price;
    cout << "Enter amount of units for third item.\n";
    cin>>units;    
    //Process or Map Inputs to outputs
    Item item3(desc,units,price);
    
    //Display Outputs
    cout << setprecision(2) << fixed;
    cout << left << '\n';
    cout << setw(50) << item1.getDesc() << '$' << setw(20) << item1.getPrce() << item1.getUnit();
    cout << endl;
    cout << setw(50) << item2.getDesc() << '$' << setw(20) << item2.getPrce() << item2.getUnit();
    cout << endl;
    cout << setw(50) << item3.getDesc() << '$' << setw(20) << item3.getPrce() << item3.getUnit();
    //Exit stage right!
    return 0;
}