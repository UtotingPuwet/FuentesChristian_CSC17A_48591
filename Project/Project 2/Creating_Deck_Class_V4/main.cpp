/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 29, 2021. 11:59 PM
 * Purpose:  Creating cards using classes. Added a dealer deck.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Deck.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(NULL)));
    //Declare Variable Data Types and Constants
    Deck deck,
         dealDek;
    int random = rand()%52;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    cout << deck.deal(random) << endl;
    cout << dealDek.deal(random);               //proof that both of them run the same.
    //Display Outputs
    
    //Reallocate Memory
    
    //Exit stage right!
    return 0;
}