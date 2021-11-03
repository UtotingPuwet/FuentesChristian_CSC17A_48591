/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: UtotingPuwet
 *
 * Created on October 25, 2021, 7:22 PM
 */

#ifndef PLAYER_H
#define PLAYER_H


struct Player {
    bool frstTrn = false;
    int hand;
    int wins = 0;
    int loss = 0;
    int pushes = 0;
    string ref; 
};



#endif /* PLAYER_H */

