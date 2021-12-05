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

///Player for the game, check Dealer for dealer file.
///
///This tracks player winrate as well as hand total. Can take in names and has its own deck.
class Player : public AbsPlay{
private:
    int hand;
    int wins;
    int losses;
    int pushes;
    string name;
    Deck deck;
public:
    ///Default constructor
    ///
    ///sets everything to 0 and makes name "John Doe"
    Player();
    ///Super constructor
    /// 
    ///Sets everything to 0 and sets name to parameter. 
    ///@param name sets name to player name
    Player(string);
    
    ///Copy constructor
    /// Just copies, nothing special here. 
    Player (const Player &);
    
    int getHand() {return hand;}
    int getWins() {return wins;}
    int getLoss() {return losses;}
    int getPush() {return pushes;}
    string getName() {return name;}
    
    ///Draws 2 cards for the player
    int iniHand();
    ///Void function that sets hand
    void setHand(int);
    void setName(string);
    ///Draw function for iniHand()
    ///@see iniHand();
    int draw(int);
    
    //Operator overloading.
    ///Operator overload for ++
    /// Adds 1 to wins/losses/pushes
    /// \param doesn't matter but is needed for ++ to work
    /// \return Player
    Player& operator++(int);
    ///Operator overload --
    /// Subtracts 1 to wins/losses/pushes
    /// \param doesn't matter but is needed for -- to work
    /// \return Player
    Player& operator--(int);
    ///Operator overload +
    /// Add 2 player objects together (for wins/losses/pushes).
    /// \param Another player object.
    /// \return Player
    Player& operator+(const Player&);
    ///Operator overload -
    /// Subtract 2 player objects together (for wins/losses/pushes).
    /// \param Another player object
    /// \return Player
    Player& operator-(const Player&);
    
    ///friend
    ///This is for the game and needs access to wins/losses/pushes data
    ///@see game ()
    friend Player chckWin (Player &p1, int dealer);
};


#endif /* PLAYER_H */

