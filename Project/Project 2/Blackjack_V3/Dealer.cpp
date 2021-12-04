/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dealer.h
 * Author: UtotingPuwet
 *
 * Created on December 1, 2021, 6:26 PM
 */

#include "Dealer.h"
#include <iostream>
using namespace std;


Dealer::Dealer() {
    int random = rand()%5;
    name += "Dealer " + names[random];
    hand = 0;
}

//this uses a hidden deck draw that doesn't print to command line the second
//card the dealer had drew.
int Dealer::iniHand() {
    hand = 0;
    int random = rand()%52;
    hand += dealDek.deal(random,name);
    random = rand()%52;
    hand += dealDek.hidDeal(random);
    return hand;
}

//This will be for all future dealer draws (so every card after the first 
//initial 2 cards
int Dealer::draw(int random) {
    int n = dealDek.deal(random,name);
    if (n == 1 && hand < 10) {
        return hand += 11;
    }
    else {
        return hand += n;
    }
    return hand += n;
}

void Dealer::setHand(int n) {
    hand = n;
}


//Random names :) just 5 of them.
string Dealer::names[5] = {"Aisha", "Annallea", "Adrianna", "Ashley", "Amber"};