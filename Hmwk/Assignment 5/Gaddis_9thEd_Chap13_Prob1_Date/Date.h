/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: Christian Fuentes
 *
 * Created on November 14, 2021, 12:26 AM
 */

#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;
    string sMonth;
    
public:
    Date(int, int, int);
    int getMnth() {return month;}
    int getDay() {return day;}
    int getYear() {return year;}
    string cnvtMon(int);
    string getSmon() {return sMonth;}
    
};


#endif /* DATE_H */

