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

class Dealer : public AbsPlay{
private:
    int hand;
    string name;
    DealDek dealDek;
    static string names[5];
public:
    Dealer();
    
    int getHand() {return hand;}
    string getName() {return name;} 
    
    int iniHand();
    int draw(int);
    void setHand(int);
};


#endif /* DEALER_H */

