/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: UtotingPuwet
 *
 * Created on November 26, 2021, 4:57 PM
 */

#include "Time.h"

Time::Time(short hour, short min, short sec) {
    this->hour = hour;
    this->min = min;
    this->sec = sec;
}

short Time::setHour(short hour) {
    this->hour = hour;
    return hour;
}

short Time::setMin(short min) {
    this->min = min;
    return min;
}

short Time::setSec(short sec) {
    this->sec = sec;
    return sec;
}