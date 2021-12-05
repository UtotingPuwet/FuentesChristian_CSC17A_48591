/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: UtotingPuwet
 *
 * Created on December 3, 2021, 1:02 PM
 */

#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include "Dummy.h"
using namespace std;

///Starting menu
class Menu {
private:
    ///Name of the player
    string name;
    ///Player 1 variable
    Player p1;
    
public:
    ///Super constructor
    /// No default constructor because game shouldn't run without the player's name
    /// \param name
    Menu(string);
    
    ///Starting menu
    ///Starting menu for players to navigate(lets users: player, see instructions, use admin mode, and quit program.)
    void useMenu();
    ///Admin mode
    ///Lets users have fun with the operator overloading and shows templates.
    void admin();
};


#endif /* MENU_H */

