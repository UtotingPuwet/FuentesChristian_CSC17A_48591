/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.h
 * Author: UtotingPuwet
 *
 * Created on November 29, 2021, 8:05 PM
 */

#include "Card.h"
#include <string>
using namespace std;


Card::Card() {
    
} 

Card::Card(int n) {
    face = setFace(n);
    suit = setSuit(n);
    val = getVal(n);
}


string Card::setFace(int n) {
    switch (n%4) {
        case 0: return "Hearts";break;
        case 1: return "Diamonds";break;
        case 2: return "Spades";break;
        case 3: return "Clubs";break;
    }
    return 0;
}

string Card::setSuit(int n) {
    if ((n%13)+1 > 10) {
        switch((n%13)+1) {
            case 11: return "Jack";break;
            case 12: return "Queen";break;
            case 13: return "King";break;
        }
    }
    else if ((n%13)+1 == 1) {
        return "Ace";
    }
    else {
        return to_string((n%13)+1);
    }
    return 0;
}

int Card::getVal(int n) {
    if ((n%13)+1 > 10) {
        return 10;
    }
    return (n%13)+1;
}

void Card::iniCard(int n) {
    face = setFace(n);
    suit = setSuit(n);
    val = getVal(n);
}