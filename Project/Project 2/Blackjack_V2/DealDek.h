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

#ifndef DEALDEK_H
#define DEALDEK_H
#include "Deck.h"

class DealDek : public Deck{
    private:
        Card *dealDek = new Card[52];
    public:
        DealDek();
        ~DealDek();
        int deal(int,string);
        int hidDeal(int);
};


#endif /* DEALDEK_H */

