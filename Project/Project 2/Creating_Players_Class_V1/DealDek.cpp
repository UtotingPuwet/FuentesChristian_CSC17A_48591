/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DealDek.h
 * Author: UtotingPuwet
 *
 * Created on November 30, 2021, 3:52 PM
 */

#include "DealDek.h"

DealDek::DealDek() {
    for (int i = 0; i < 52; i++) {
        dealDek[i].iniCard(i);
    }
}

DealDek::~DealDek() {
    delete []dealDek;
}

DealDek::deal(int i) {
    return dealDek[i].getVal();
}