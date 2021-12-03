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

class Game {
private:
    string name;
    Player p1;
    int nGames;
public:
    Game(string);
    void game();
    Player p1Menu(Player);
    Dealer& delMenu(Dealer&);
    bool check21(int);
    
};


#endif /* GAME_H */

