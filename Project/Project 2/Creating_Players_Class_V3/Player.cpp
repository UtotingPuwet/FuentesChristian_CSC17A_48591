/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: UtotingPuwet
 *
 * Created on December 1, 2021, 12:48 PM
 */

#include "Player.h"
#include <iostream>



Player::Player() {
    name = "John Doe";
    wins = 0;
    losses = 0;
    pushes = 0;
    hand = 0;
}


Player::Player(string name) {
    this->name = name;
    wins = 0;
    losses = 0;
    pushes = 0;
    hand = 0;
}

Player::Player(const Player &p2) {
    wins  = p2.wins;
    losses = p2.losses;
    pushes = p2.pushes;
    name = p2.name;
    hand = p2.hand;
}

int Player::draw(int random) {
    int n = deck.deal(random,name);
    if (n == 1 && hand < 10) {
        return hand += 11;
    }
    else {
        return hand += n;
    }
    return hand += n;
}

int Player::iniHand() {
    int random = rand()%52;
    hand = 0;
    for (int i = 0; i < 2; i++) {
        hand = draw(random);
        std::cout << hand << endl;
        random = rand()%52;
    }
    return hand;
    
}

Player& Player::operator ++() {
    wins++;
    losses++;
    pushes++;
    return *this;
}

Player& Player::operator --() {
    wins--;
    losses--;
    pushes--;
    return *this;
}

Player& Player::operator +(const Player &p2) {
    wins = this->wins + p2.wins;
    losses = this->losses + p2.losses;
    pushes = this->pushes + p2.pushes;
    return *this;
}
