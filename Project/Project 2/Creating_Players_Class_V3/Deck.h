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

#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck {
protected:
    Card *deck = new Card[52];
public:
    Deck();
    ~Deck();
    virtual int deal(int,string);
};


#endif /* DECK_H */

