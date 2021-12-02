/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on December 1, 2021. 11:23 PM
 * Purpose:  Add operator overloading to wins/draws/losses. Add copy constructor to player.
 * Below is plan from last version.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Player.h"
#include "Dealer.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(NULL)));
    //Declare Variable Data Types and Constants
    Player p1("Christian");
    Dealer dealer;
    int random = rand()%52;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    dealer.iniHand() << '\n';

    
    cout << '\n' << '\n' << '\n';
    cout << p1.iniHand() << '\n';
    random = rand()%52;
    cout << p1.draw(random) << '\n';
    //Display Outputs
    
    //Reallocate Memory
    
    //Exit stage right!
    return 0;
}