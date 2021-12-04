/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on December 3, 2021. 12:51 PM
 * Purpose:
 *Alright scrapped the betting idea because it would take too many lines to implement :)
 * I documented and coded everything. I added the admin mode and everything is working just fine.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//User Libraries
#include "Menu.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(NULL)));
    //Declare Variable Data Types and Constants
    string name;
    
    //Initialize Variables
    cout << "What is your name? (First name only no spaces).\n";
    cin>>name;
    //Process or map Inputs to Outputs
    Menu menu(name);
    menu.useMenu();
    
    //Display Outputs
    
    //Reallocate Memory
    
    //Exit stage right!
    return 0;
}

