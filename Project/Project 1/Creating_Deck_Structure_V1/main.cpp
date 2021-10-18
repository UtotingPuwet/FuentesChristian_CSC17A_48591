/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 17, 2021 3:30 PM
 * Purpose:  Making a deck (doesn't include the logic for jack, queen, king)
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//User Libraries
#include "Card.h"
//Global Constants - No Global Variables

//Function Prototypes
Card *filDeck ();
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare seed
    srand(static_cast<unsigned int>(time(NULL)));
    //Declare Variable Data Types and Constants
    Card *cards;
    cards = filDeck();
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    cout << "You got a " << cards[0].suit << " and its value is " << cards[0].val;
    //Display Outputs
    delete []cards;
    //Exit stage right!
    return 0;
}

Card *filDeck () {
    Card *a = new Card [52];
    for (int i = 1; i <= 13; i++) {
        a[i-1].val = i;
        if (i+1 > 10) {
            a[i-1].val = 10;
        }
        for (int j = 0; j < 4; j++) {
            if (j==0) a[j].suit = "Hearts";
            if (j==1) a[j].suit = "Diamonds";
            if (j==2) a[j].suit = "Clubs";
            if (j==3) a[j].suit = "Spades";
        }
    }
    return a;
}