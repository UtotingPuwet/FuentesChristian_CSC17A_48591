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

///Deck for the dealer
class DealDek : public Deck{
    private:
        Card *dealDek = new Card[52];
    public:
        ///Default constructor
        ///Creates 52 cards like Deck
        DealDek();
        ///Deconstructor
        ~DealDek();
        ///Deals the dealer a card
        /// 
        /// \param random number 
        /// \param dealer name
        /// \return card numeric value
        int deal(int,string);
        ///Deals the dealer a card without printing
        /// Doesn't print the card 
        /// \param random number
        /// \return card numeric value
        int hidDeal(int);
};


#endif /* DEALDEK_H */

