/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.cpp
 * Author: UtotingPuwet
 *
 * Created on November 14, 2021, 11:08 AM
 */

#include "Date.h"
#include <string>
using namespace std;

Date::Date(int month, int day, int year) {
    this->month = month;
    this->day = day;
    this->year = year;
    this->sMonth=cnvtMon(month);
}

string Date::cnvtMon(int month) {
    switch (month) {
        case 1: sMonth = "January"; break;
        case 2: sMonth = "February"; break;
        case 3: sMonth = "March"; break;
        case 4: sMonth = "April"; break;
        case 5: sMonth = "May"; break;
        case 6: sMonth = "June"; break;
        case 7: sMonth = "July"; break;
        case 8: sMonth = "August"; break;
        case 9: sMonth = "September"; break;
        case 10: sMonth = "October"; break;
        case 11: sMonth = "November"; break;
        case 12: sMonth = "December"; break;
    }
    return sMonth;
}
