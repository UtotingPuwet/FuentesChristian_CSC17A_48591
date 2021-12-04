/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: UtotingPuwet
 *
 * Created on November 30, 2021, 12:41 AM
 */

#include "Deck.h"
#include <iostream>
using namespace std;

//In order to make a deck array I would of had to initialize all 52
//Cards in the array at the time the deck is created or make a function like (iniCard)
//This one where it would initialize the card, post-deck creation.
Deck::Deck() {
    for (int i = 0; i < 52; i++) {
        deck[i].iniCard(i);
    }
}


//Free up the allocated memory from deck.
Deck::~Deck() {
    delete []deck;
}

//Deals a card. Prints all the parts of a card that would be needed but only
//Returns a value because that's all that would be needed to keep track of 
//Player and dealer hand.
int Deck::deal(int i,string name) {
    cout << name << " got a " << deck[i].getSuit() << " of " << deck[i].getFace() << '\n';
    return deck[i].getVal();
}