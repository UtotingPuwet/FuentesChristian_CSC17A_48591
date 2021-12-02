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
    name = names[random];
    hand = 0;
}

int Dealer::iniHand() {
    int random = rand()%52;
    hand += dealDek.deal(random);
    random = rand()%52;
    hand += dealDek.hidDeal(random);
    return hand;
}

int Dealer::draw(int random) {
    int n = dealDek.deal(random);
    if (n == 1 && hand < 10) {
        return hand += 11;
    }
    else {
        return hand += n;
    }
    return hand += n;
}


string Dealer::names[5] = {"Aisha", "Annallea", "Adrianna", "Ashley", "Amber"};