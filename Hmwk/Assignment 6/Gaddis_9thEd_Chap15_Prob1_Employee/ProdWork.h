/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProdWork.h
 * Author: UtotingPuwet
 *
 * Created on November 18, 2021, 12:51 AM
 */

#ifndef PRODWORK_H
#define PRODWORK_H
#include "Employe.h"

class ProdWork : public Employe {
private:
    int shift;
    float pay;
public:
    ProdWork(int,float);
    int setShft(int);
    float setPay(float);
    
    int getShft() {return shift;}
    float getPay() {return pay;}
};


#endif /* PRODWORK_H */

