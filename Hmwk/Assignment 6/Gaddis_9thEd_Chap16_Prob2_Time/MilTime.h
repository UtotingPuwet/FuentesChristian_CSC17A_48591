/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.h
 * Author: UtotingPuwet
 *
 * Created on November 26, 2021, 8:04 PM
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"


class MilTime : public Time{
protected:
    short milHours;
    short milSec;
public:
    MilTime(short,short);
    
    short getMilH() {return milHours;}
    short getMilS() {return milSec;}
    
    short setMil(short);
    short cnvrt(short);
    
    class TimeErr {
        
    };
    
};


#endif /* MILTIME_H */

