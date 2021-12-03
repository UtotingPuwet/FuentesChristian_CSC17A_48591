/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on December 2, 2021. 7:56 PM
 * Purpose:  Finished making the game object now, need to add extra features.
 * Version 3 will probably have betting and I will code out the menu as well as the "admin" mode to let users toy around
 * with other features such as adding object and proving other concepts I have learned
 * I will also add more comments to explain this entire 1000 line project.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Game.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {

    //Random number seed
    srand(static_cast<unsigned int>(time(NULL)));
    //Declare Variable Data Types and Constants
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    Game blckjck("Christian");
    blckjck.game();
    //Display Outputs
    
    //Reallocate Memory
    
    //Exit stage right!
    return 0;
}

