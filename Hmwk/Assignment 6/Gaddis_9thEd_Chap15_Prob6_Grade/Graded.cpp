/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graded.h
 * Author: UtotingPuwet
 *
 * Created on November 28, 2021, 12:24 AM
 */

#include "Graded.h"

Graded::Graded() {
    this->score = 0.0;
}

Graded::Graded(float score) {
    this->score = score;
}

void Graded::setScor(float score) {
    this->score = score;
}

char Graded::getLett(float score) {
    if (score > 60) {
        return 'P';
    }
    else {
        return 'F';
    }
    return 'F';
}