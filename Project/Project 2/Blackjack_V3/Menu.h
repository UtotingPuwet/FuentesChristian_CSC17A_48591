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

class Menu {
private:
    string name;
    Player p1;
    
public:
    Menu(string);
    
    void useMenu();
    void admin();
};


#endif /* MENU_H */

