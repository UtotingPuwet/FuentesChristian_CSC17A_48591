/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.h
 * Author: UtotingPuwet
 *
 * Created on November 29, 2021, 8:05 PM
 */

#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
private:
    string setFace(int);
    string setSuit(int);
    int getVal(int);
protected:
    int cardNum;
    string face;
    string suit;
    int val;
public:
    Card(int);
    string getFace() {return face;}
    string getSuit() {return suit;}
    int getVal() {return val;}
    
};


#endif /* CARD_H */

