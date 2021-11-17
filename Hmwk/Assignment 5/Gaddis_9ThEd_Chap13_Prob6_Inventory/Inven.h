/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inven.h
 * Author: UtotingPuwet
 *
 * Created on November 14, 2021, 11:54 PM
 */

#ifndef INVEN_H
#define INVEN_H


class Inven {
private:
    int   itemNum,
          amount;
    float cost,
          total;
public:
    Inven();
    Inven(int,int,float);
    
    int getItem() {return itemNum;}
    int getAmon() {return amount;}
    float getCost() {return cost;}
    float getTot() {return total;}
    
    int setItem(int);
    int setAmon(int);
    float setCost(float);
    float setTot(float,int);
    
};


#endif /* INVEN_H */

