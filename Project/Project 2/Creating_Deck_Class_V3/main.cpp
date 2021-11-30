/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 29, 2021. 11:59 PM
 * Purpose:  Creating cards using classes. Created deck class and using pointers now.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Card.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Card *card = new Card[52];
    //Initialize Variables
    for (int i = 0; i < 52; i++) {
        card[i].iniCard(i);
    }
    //Process or map Inputs to Outputs
    
    //Display Outputs
    for (int i = 0; i < 52; i++) {
        cout <<  card[i].getSuit() << " of " << card[i].getFace() << " is equal to " << card[i].getVal() << '\n';
    }
    //Reallocate Memory
    
    delete []card;
    
    //Exit stage right!
    return 0;
}