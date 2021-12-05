/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: UtotingPuwet
 *
 * Created on December 3, 2021, 12:10 AM
 */

#ifndef GAME_H
#define GAME_H
#include "Dealer.h"
using namespace std;

///Blackjack game itself
class Game {
private:
    string name;
    Player p1;
    int nGames;
public:
    ///Base constructor
    /// Doesn't do anything besides set name.
    /// \param Name
    Game(string);
    ///Blackjack
    /// All of blackjack will run in this single function while calling other utility functions.
    ///
    /// @see check21(int) p1Menu(Player) delMenu(Dealer&)
    void game();
    /// Player menu during turn
    /// Gives choice to either hit or stand on player's turn, stops when hand >= 21
    /// \param Player
    /// \return Player
    Player p1Menu(Player);
    /// Dealer menu
    /// Doesn't show anything on players side just logic for dealer to keep drawing until hand >= 17
    /// \param Dealer
    /// \return Dealer
    Dealer& delMenu(Dealer&);
    ///Check for 21 hand
    /// Checks whether player or dealer got 21
    /// \param hand
    /// \return true or false
    bool check21(int);
    
};


#endif /* GAME_H */

