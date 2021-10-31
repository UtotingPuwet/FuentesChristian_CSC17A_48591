/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 25, 2021.
 * Purpose:  Lost the last one :( made a new one and this will be the deck.
 * Adding Jack Queen and King logic.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries
#include "Deck.h"
//Global Constants - No Global Variables

//Function Prototypes
void destroy (Deck *);
Deck *iniDeck ();
void print (Deck *);


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Deck *deck = iniDeck();
    //Initialize Variables
    
    
    
    //Process or map Inputs to Outputs
    
    
    print (deck);
    
    
    
    //Display Outputs
    destroy (deck);
    //Exit stage right!
    return 0;
}

void destroy (Deck *deck) {
    delete []deck->cards;
    delete deck;
}

Deck *iniDeck () {
    Deck *deck = new Deck;
    int count = 0;
    int count2 = 0;
    
    

    for (int i = 0; i < 52; i++) {
        switch (i%4) {
            case 0: deck->cards[i].suit = "Hearts"; break;
            case 1: deck->cards[i].suit = "Diamonds"; break;
            case 2: deck->cards[i].suit = "Spades"; break;
            case 3: deck->cards[i].suit = "Clubs"; break;
        }
        if ((i%13)+1 > 10) {
            switch ((i%13)+1) {
                case 11: deck->cards[i].face = "Jack"; break;
                case 12: deck->cards[i].face = "Queen"; break;
                case 13: deck->cards[i].face = "King"; break;
            }
            deck->cards[i].val = 10;
        }
        else {
            deck->cards[i].val = (i%13)+1;
            deck->cards[i].face = to_string(deck->cards[i].val);
        }
    }
    
    
    
    return deck;
}

void print (Deck *deck) {
    for (int i = 0; i < 52; i++) {
        cout << deck->cards[i].face << " of " << deck->cards[i].suit << '\n';
    }
}