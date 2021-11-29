/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Essay.h
 * Author: UtotingPuwet
 *
 * Created on November 28, 2021, 1:25 AM
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "Graded.h"

class Essay : public Graded {
protected:
    float grammar,
          spell,
          length,
          content;
    char grade;
    
public:
    Essay();
    Essay(float,float,float,float);
    
    char getLett(float);
    
    char getGrad() {return grade;}
};


#endif /* ESSAY_H */

