/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 30, 2021. 8:09 PM
 * Purpose:  Creating players using classes. Added abstract player along with player class.
 * BIG CHANGES :)
 * Plan: Add operator overloading to wins/draws/losses. Eventually.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Player.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(NULL)));
    //Declare Variable Data Types and Constants
    Player p1("Christian");
    int random = rand()%52;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    for (int i = 0; i < 12; i++) {
        random = rand()%52;
        cout << "Hand = " << p1.draw(random) << endl;
    }
    
    //Display Outputs
    
    //Reallocate Memory
    
    //Exit stage right!
    return 0;
}