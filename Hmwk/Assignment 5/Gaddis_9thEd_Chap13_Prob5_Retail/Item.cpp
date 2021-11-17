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


#include <string>

#include "Item.h"
using namespace std;

Item::Item(string desc, int units, float price) {
    this->desc = desc;
    this->units = units;
    this->price = price;
}

string Item::setDesc(string desc) {
    return this->desc = desc;
}

float Item::setPrce(float price) {
    return this->price = price;
}

int Item::setUnit(int units) {
    return this->units = units;
}