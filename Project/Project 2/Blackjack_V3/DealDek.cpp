/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DealDek.h
 * Author: UtotingPuwet
 *
 * Created on November 30, 2021, 3:52 PM
 */

#include "DealDek.h"
#include <iostream>
using namespace std;

//This works the same as the deck for players.
//Just wanted to make another one for the dealer because the dealers always,
//Have their own decks.
DealDek::DealDek() {
    for (int i = 0; i < 52; i++) {
        dealDek[i].iniCard(i);
    }
}

DealDek::~DealDek() {
    delete []dealDek;
}

int DealDek::deal(int i,string name) {
    cout << name << " got a " << dealDek[i].getSuit() << " of " << dealDek[i].getFace() << '\n';
    return dealDek[i].getVal();
}

//Hidden deal where it doesn't print what the card is.
//This is specifically for draw #2 for the dealer.
int DealDek::hidDeal(int i) {
    return dealDek[i].getVal();
}


