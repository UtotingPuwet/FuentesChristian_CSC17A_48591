/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: UtotingPuwet
 *
 * Created on November 30, 2021, 10:45 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <cstring>
using namespace std;
#include "AbsPlay.h"
#include "Dealer.h"

class Player : public AbsPlay{
private:
    int hand;
    int wins;
    int losses;
    int pushes;
    string name;
    Deck deck;
public:
    Player();
    Player(string);
    Player (const Player &);
    
    int getHand() {return hand;}
    int getWins() {return wins;}
    int getLoss() {return losses;}
    int getPush() {return pushes;}
    string getName() {return name;}
    
    int iniHand();
    void setHand(int);
    void setName(string);
    int draw(int);
    
    //Operator overloading.
    Player& operator++(int);
    Player& operator--(int);
    Player& operator+(const Player&);
    Player& operator-(const Player&);
    
    //friend operator
    friend Player chckWin (Player &p1, int dealer);
};


#endif /* PLAYER_H */

