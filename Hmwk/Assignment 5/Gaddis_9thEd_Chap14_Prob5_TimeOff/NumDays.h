/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: UtotingPuwet
 *
 * Created on November 16, 2021, 6:13 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H


class NumDays {
private:
    int hours;
    float days;
public:
    NumDays(int);
    float getDays() {return days;}
    int getHour() {return hours;}
    NumDays& operator++(int);
    NumDays& operator--(int);   
    const NumDays operator-(const NumDays&) const;
    const NumDays operator+(const NumDays&) const;
};


#endif /* NUMDAYS_H */

