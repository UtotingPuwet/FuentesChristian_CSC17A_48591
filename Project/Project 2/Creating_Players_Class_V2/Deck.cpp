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

Deck::Deck() {
    for (int i = 0; i < 52; i++) {
        deck[i].iniCard(i);
    }
}

Deck::~Deck() {
    delete []deck;
}

int Deck::deal(int i) {
    cout << deck[i].getSuit() << " of " << deck[i].getFace() << " is equal to " << deck[i].getVal() << '\n';
    return deck[i].getVal();
}