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

Player::Player(string name) {
    this->name = name;
    wins = 0;
    losses = 0;
    pushes = 0;
    hand = 0;
}

int Player::draw(int random) {
    int n = deck.deal(random);
    if (n == 1 && hand < 10) {
        return hand += 11;
    }
    else {
        return hand += n;
    }
    return hand += n;
}

int Player::iniHand(int n) {
    return n;
}