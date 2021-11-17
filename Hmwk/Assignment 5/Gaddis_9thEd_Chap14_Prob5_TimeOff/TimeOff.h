/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: UtotingPuwet
 *
 * Created on November 16, 2021, 10:10 PM
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include <string>
#include "NumDays.h"
using namespace std;


class TimeOff {
private:
    string name;
    int id;
    int hours;
    int days;
    float maxVac1;
    float vacTkn1;
    float maxSck1;
    float sckTkn1;
    float maxUnp1;
    float unpTkn1;
    
public:
    TimeOff(int,string);
    float maxSck(int);
    float sickTkn(int);
    float maxVac(int);
    float vacTkn(int);
    float maxUnp(int);
    float unpTkn(int);
    
    float getMxSk() {return maxSck1;}
    float getSkTk() {return sckTkn1;}
    float getMxVc() {return maxVac1;}
    float getVcTk() {return vacTkn1;}
    float getMxUn() {return maxUnp1;}
    float getUnTk() {return unpTkn1;}
    string getName() {return name;}
    int getId() {return id;}
    
    
    
};


#endif /* TIMEOFF_H */

