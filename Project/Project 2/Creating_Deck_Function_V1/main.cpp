/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 29, 2021. 7:58 PM
 * Purpose:  Creating a deck using functions only.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables

//Function Prototypes
void create(int[],const int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    const int size = 52;
    int deck[size];
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    create(deck,size);
    //Display Outputs
    
    //Exit stage right!
    return 0;
}

void create (int deck[], const int size) {
    string suit;
    string face;
    for (int i = 0; i < size; i++) {
        deck[i] = i%13+1;
        switch (i%4) {
            case 0: suit = "Hearts"; break;
            case 1: suit = "Diamonds"; break;
            case 2: suit = "Spades"; break;
            case 3: suit = "Clubs"; break;
        }
        if ((i%13)+1 > 10) {
            switch ((i%13)+1) {
                case 11: face = "Jack";break;
                case 12: face = "Queen";break;
                case 13: face = "King";break;
            }
        }
        else if ((i%13)+1 == 1) {
            face = "Ace";
        }
        else {
            face = to_string(deck[i]);
        }
        cout << face << " of " << suit << '\n';
    }
}