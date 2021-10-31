/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 25, 2021. 7:11 PM
 * Purpose:  Add player structure
 * October 26, 2021 : fixed bug where return value on card didn't match.
 * October 27, 2021 : included ace.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries
#include "Deck.h"
#include "Player.h"
//Global Constants - No Global Variables

//Function Prototypes
void destroy (Deck *);
Deck *iniDeck ();
int draw(Deck *);
void print (Deck *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed
    srand (static_cast<unsigned int> (time(NULL)));
    //Declare Variable Data Types and Constants
    Deck *deck = iniDeck();
    Player p1,
           dealer;
    //Initialize Variables
    
    
    
    //Process or map Inputs to Outputs
    
    p1.hand += draw(deck);
    cout << "Your hand is now " << p1.hand << '\n';
    dealer.hand += draw(deck);
    cout << "Dealer hand is now " << dealer.hand << '\n';
    
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
        if ((i%13)+1 == 1) {
            deck->cards[i].face  = "Ace";
            deck->cards[i].val = 1;
        }
        else {
            deck->cards[i].val = (i%13)+1;
            deck->cards[i].face = to_string(deck->cards[i].val);
        }
    }
    
    
    
    return deck;
}

int draw (Deck *deck) {
    int random = rand()%52;
    random = deck->cards[random].val;
    cout << "You got a " << deck->cards[random].face << " of " << deck->cards[random].suit << '\n';
    
    return deck->cards[random].val;
}

void print (Deck *deck) {
    for (int i = 0; i < 52; i++) {
        int random = rand()%52;
        cout << deck->cards[random].face << " of " << deck->cards[random].suit << " has value of " << deck->cards[random].val << '\n';
    }
}