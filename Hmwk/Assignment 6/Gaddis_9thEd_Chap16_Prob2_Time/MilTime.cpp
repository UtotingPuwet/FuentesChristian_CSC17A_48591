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

#include "MilTime.h"

MilTime::MilTime(short milHours, short milSec) : Time(milHours,0,milSec) {
    short hour,
          min;
    
    
    hour = MilTime::cnvrt(milHours);
    
    min = hour%100;
    hour /= 100;
    
    MilTime::setHour(hour);
    MilTime::setMin(min);
    if (milHours > 2359) {
        throw TimeErr();
    }
    else {
        this->milHours = milHours;
    }
    if (milSec > 59 || milSec < 0) {
        throw TimeErr();
    }
    else {
        this->milSec = milSec;
    }
    
    
}

short MilTime::cnvrt(short milHour) {
    short hour,
          min;
    
    hour = milHour/100;
    min = milHour%100;
    
    if (hour > 12) {
        hour -= 12;
    }
    return (hour*100)+min;
}

short MilTime::setMil(short milHour) {
    this->milHours = milHour;
    return this->milHours;
}