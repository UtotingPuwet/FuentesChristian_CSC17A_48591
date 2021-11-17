/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NumDays.h"


/* 
 * File:   NumDays.h
 * Author: UtotingPuwet
 *
 * Created on November 16, 2021, 6:13 PM
 */

NumDays::NumDays(int hours) {
    this->hours = hours;
    this->days = (float)hours/8.0f;
}

NumDays& NumDays::operator ++(int extra) {
    hours += 1;
    this->days = hours/8.0f;
}

NumDays& NumDays::operator --(int less) {
    hours -= 1;
    this->days = hours/8.0f;
}

const NumDays NumDays::operator +(const NumDays& hours2) const {
    int num;
    
    num = this->hours + hours2.hours; 
    
    NumDays a(num);
    
    
    return a;
}

const NumDays NumDays::operator -(const NumDays& hours2) const{
    int num;
    
    num = this->hours - hours2.hours;
    
    NumDays a(num);
    
    
    return a;
}