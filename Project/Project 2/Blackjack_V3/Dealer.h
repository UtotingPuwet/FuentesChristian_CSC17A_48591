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

#ifndef DEALER_H
#define DEALER_H
#include "Player.h"

///The Dealer for BlackJack
class Dealer : public AbsPlay{
private:
    int hand;
    string name;
    DealDek dealDek;
    static string names[5];
public:
    ///Base Constructor
    ///Sets hand, and picks random name.
    Dealer();
    
    ///Get dealer's hand
    /// \return hand
    int getHand() {return hand;}
    ///Get dealer's name
    /// \return name
    string getName() {return name;} 
    
    ///Initialize dealer's hand
    /// The first card is printed but not the second card
    /// \return card value
    int iniHand();
    
    ///Dealer draw
    int draw(int);
    /// Set dealer hand
    /// \param hand
    void setHand(int);
};


#endif /* DEALER_H */

