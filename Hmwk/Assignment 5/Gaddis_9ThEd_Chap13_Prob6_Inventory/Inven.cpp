/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Inven.h"
#include <iostream>
using namespace std;

/* 
 * File:   Inven.h
 * Author: UtotingPuwet
 *
 * Created on November 14, 2021, 11:54 PM
 */


Inven::Inven() {
    itemNum = 0;
    amount = 0;
    cost = 0;
    total = 0;
}

Inven::Inven(int itemNum, int amount, float cost) {
    while (itemNum < 1) {
        cout << "Input number greater than 1 for item number.\n";
        cin>>itemNum;
    }
    while (amount < 1) {
        cout << "Input number greater than 1 for amount of items.\n";
        cin>>amount;
    }
    while (cost < 1) {
        cout << "Input number greater than 1 for item cost.\n";
        cin>>cost;
    }
    this->itemNum = itemNum;
    this->amount = amount;
    this->cost = cost;
    this->total = setTot(cost,amount);
}

int Inven::setItem(int itemNum) {
    while (itemNum < 1) {
        cout << "Input number greater than 1.\n";
        cin>>itemNum;
    }
    this->itemNum = itemNum;
    return this->itemNum;
} 

int Inven::setAmon(int amount) {
    while (amount < 1) {
        cout << "Input number greater than 1.\n";
        cin>>amount;
    }
    this->amount = amount;
    return this->amount;
}

float Inven::setCost(float cost) {
    while (cost < 1) {
        cout << "Input number greater than 1.\n";
        cin>>cost;
    }
    this->cost = cost;
    return this->cost;
}

float Inven::setTot(float cost, int amount) {
    this->total = cost*amount;
    return this->total;
} 

