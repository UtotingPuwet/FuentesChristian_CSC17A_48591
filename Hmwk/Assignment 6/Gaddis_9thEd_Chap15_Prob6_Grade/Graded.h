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

#ifndef GRADED_H
#define GRADED_H


class Graded {
protected:
    float score;
public:
    Graded();
    Graded(float);
    void setScor(float);
    
    float getScor(float) {return score;}
    
    virtual char getLett(float);
    
};


#endif /* GRADED_H */

