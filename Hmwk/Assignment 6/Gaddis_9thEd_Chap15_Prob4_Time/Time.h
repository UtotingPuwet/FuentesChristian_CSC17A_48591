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

#ifndef TIME_H
#define TIME_H


class Time {
protected:
    short hour;
    short min;
    short sec;
public:
    Time(short,short,short);
    
    getHour() {return hour;}
    getMin() {return min;}
    getSec() {return sec;}
    
    short setHour(short);
    short setMin(short);
    short setSec(short);
};


#endif /* TIME_H */

