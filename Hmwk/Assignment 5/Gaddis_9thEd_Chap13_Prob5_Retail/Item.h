/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.h
 * Author: UtotingPuwet
 *
 * Created on November 14, 2021, 8:00 PM
 */

#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
private: 
    string desc;
    int units; 
    float price;
public:
    Item(string, int, float);
    string getDesc() {return desc;}
    int getUnit() {return units;}
    float getPrce() {return price;}
    
    string setDesc(string);
    int setUnit(int);
    float setPrce(float);
};


#endif /* ITEM_H */

