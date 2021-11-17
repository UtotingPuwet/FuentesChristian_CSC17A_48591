/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MnthDay.h
 * Author: UtotingPuwet
 *
 * Created on November 16, 2021, 12:18 PM
 */

#ifndef MNTHDAY_H
#define MNTHDAY_H
#include <string>
using namespace std;

class MnthDay {
private: 
    int num;
    string eng;
public:
    MnthDay(int);
    string english(int);
    void print();
    static string month[12];
    
};


#endif /* MNTHDAY_H */

