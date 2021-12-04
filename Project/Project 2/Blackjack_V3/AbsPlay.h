/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbsPlay.h
 * Author: UtotingPuwet
 *
 * Created on December 1, 2021, 10:04 AM
 */

#ifndef ABSPLAY_H
#define ABSPLAY_H
#include "DealDek.h"

#include <cstring>
using namespace std;

//This is an abstract player that  is used for both dealer and player.
//Made this first before either class to have a setup of what both need.
class AbsPlay {
public:
    virtual int iniHand() = 0;
    virtual int getHand() = 0;
    virtual string getName() = 0;
};


#endif /* ABSPLAY_H */

