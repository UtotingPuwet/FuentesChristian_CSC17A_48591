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


//Default constructor
Player::Player() {
    name = "John Doe";
    wins = 0;
    losses = 0;
    pushes = 0;
    hand = 0;
}


//Super constructor
Player::Player(string name) {
    this->name = name;
    wins = 0;
    losses = 0;
    pushes = 0;
    hand = 0;
}

//Copy constructor
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

void Player::setHand(int n) {
    hand = n;
}

void Player::setName(string name) {
    this->name = name;
}

//ALL OF BELOW ARE OVERLOADED OPERATORS.
//These stayed in the program because they are what I actually used to test 
//Operator overloading on the dummies.
//So this is like the "real" admin mode as you wouldn't have to go through
//The menu I made to test operator overloading instead you would use these
//Functions and test them through main.cpp
Player& Player::operator ++(int n) {
    wins++;
    losses++;
    pushes++;
    return *this;
}

Player& Player::operator --(int n) {
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

Player& Player::operator -(const Player& p2) {
    wins = this->wins - p2.wins;
    losses = this->losses - p2.losses;
    pushes = this->pushes - p2.pushes;
    return *this;
}
