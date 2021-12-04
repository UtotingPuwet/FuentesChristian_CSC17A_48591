/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on December 3, 2021. 12:51 PM
 * Purpose:
 * Version 3 will probably have betting and I will code out the menu as well as the "admin" mode to let users toy around
 * with other features such as adding object and proving other concepts I have learned
 * I will also add more comments to explain this entire 1000 line project.
 * Well this is version 3. 
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
    Menu menu(name);
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    menu.useMenu();
    
    //Display Outputs
    
    //Reallocate Memory
    
    //Exit stage right!
    return 0;
}

