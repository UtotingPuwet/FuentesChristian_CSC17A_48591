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
#include "Inven.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Inven inven;
    char choice = '9';
    int itemNum,
        amount;
    float cost;
    //Initialize Variables
    inven = Inven(0,0,0);
    cout << endl;
    //Process or map Inputs to Outputs
    do {
        cout << "Enter 1 to get item number.\n";
        cout << "Enter 2 to get item amount.\n";
        cout << "Enter 3 to get item cost.\n";
        cout << "Enter 4 to get item total cost.\n";
        cout << "Enter 5 to set item number.\n";
        cout << "Enter 6 to set item amount.\n";
        cout << "Enter 7 to set item cost.\n";
        cout << "Enter 8 to set item total cost.\n";
        cout << "Enter 9 to exit program.\n";
        
        
        cin>>choice;
        switch (choice) {
            case '1': cout << inven.getItem() << endl; break;
            case '2': cout << inven.getAmon() << endl; break;
            case '3': cout << inven.getCost() << endl; break;
            case '4': cout << inven.getTot() << endl; break;
            case '5': {
                cout << "Enter item number.\n";
                cin>>itemNum;
                inven.setItem(itemNum);
                break;
            }
            case '6': {
                cout << "Enter amount of items.\n";
                cin>>amount;
                inven.setAmon(amount);
                break;
            }
            case '7': {
                cout << "Enter item cost.\n";
                cin>>cost;
                inven.setCost(cost);
                break;
            }
            case '8': inven.setTot(inven.getCost(),inven.getItem()); break;
        }
    }while (choice <= '8');
    //Display Outputs
    
    //Exit stage right!
    return 0;
}