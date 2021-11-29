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

#include "Essay.h"


Essay::Essay(){
    grammar = 0.0;
    spell = 0.0;
    length = 0.0;
    content = 0.0;
    ;
}

Essay::Essay(float grammar,float spell,float length,float content) : Graded(grammar+spell+length+content){
    float score = grammar+spell+length+content;
    this->grammar = grammar;
    this->spell = spell;
    this->length = length;
    this->content = content;
    this->grade = getLett(score);
    
    
}

char Essay::getLett(float score) {
    
    if (score >= 90) {
        return 'A';
    }
    else if (score < 90 && score >= 80) {
        return 'B';
    }
    else if (score < 80 && score >= 70) {
        return 'C';
    }
    else if (score < 70 && score >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
    return 'F';
}