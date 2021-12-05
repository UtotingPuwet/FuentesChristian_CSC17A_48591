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


///Cards for the Deck class
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
    ///Default constructor
    ///Used so that I don't have to initialize card when making card array. 
    Card();
    ///Super constructor
    ///Used in earlier versions, send in numbers between 0-51.
    Card(int);
    ///Get face string 
    /// \return face string
    string getFace() {return face;}
    ///Get suit string
    /// \return suit string
    string getSuit() {return suit;}
    ///Get card numeric value
    /// \return card numeric value
    int getVal() {return val;}
    ///Initialize card post-declaration
    /// Used for when making card array and not wanting to initialize 52 cards.
    /// \param any number 0-51.
    void iniCard(int);
    
};


#endif /* CARD_H */

