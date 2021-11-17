/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Num.h
 * Author: UtotingPuwet
 *
 * Created on November 16, 2021, 12:22 AM
 */

#ifndef NUM_H
#define NUM_H
#include <string>
using namespace std;

class Num {
private: 
    int num;
public:
    Num(int);
    void print();
    string eng(int);
    static string teen[9];
};




#endif /* NUM_H */

