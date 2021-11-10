/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 5, 2021 2:54PM
 * Purpose:  Binary file practice.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

//User Libraries
#include "Deck.h"
//Global Constants - No Global Variables

//Function Prototypes
void destroy (Deck *);
Deck *iniDeck ();
void print (Deck *);
Deck *binDeck(Deck *);
void toFile (Deck *, fstream &);
Deck *frmFile (Deck *, fstream &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Deck *deck = iniDeck();
    Deck *deck2 = binDeck(deck);
    //Initialize Variables
    
    
    
    //Process or map Inputs to Outputs
    
    //Display Outputs
    destroy (deck);
    cout << deck2->cards[0].face << " of " << deck2->cards[0].suit << " has value of " << deck2->cards[0].val;
    
    
    //Exit stage right!
    return 0;
}

void destroy (Deck *deck) {
    delete []deck->cards;
    delete deck;
}

Deck *iniDeck () {
    Deck *deck = new Deck;
    deck->cards = new Card[52];

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
        else if ((i%13)+1 == 1) {
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

void print (Deck *deck) {
    for (int i = 0; i < 52; i++) {
        cout << deck->cards[i].face << " of " << deck->cards[i].suit << '\n';
    }
}

Deck *binDeck (Deck *deck) {
    fstream binFile;
    Deck *deck2;
    binFile.open("cards.bin", ios::binary | ios::in | ios::out);
    
    toFile(deck,binFile);
    
    deck2 = frmFile(deck2,binFile);
    
    binFile.close();
    
    return deck2;
}

void toFile (Deck *deck, fstream &binFile) {
    long cursor = 0L;

    binFile.seekp(cursor,ios::beg);
    binFile.write(reinterpret_cast<char *> (deck->cards),sizeof(Card) * 52);

}

Deck *frmFile(Deck *deck2, fstream &binFile) {
    long cursor = 0L;
    
    Deck *deck =  new Deck;
    deck->cards = new Card[52];
    binFile.seekg(cursor,ios::beg);
    binFile.read(reinterpret_cast<char *> (deck->cards), sizeof(Card) * 52);
    
    
    return deck;
}