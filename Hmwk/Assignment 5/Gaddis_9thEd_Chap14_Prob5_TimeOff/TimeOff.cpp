/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TimeOff.h"


/* 
 * File:   TimeOff.h
 * Author: UtotingPuwet
 *
 * Created on November 16, 2021, 10:10 PM
 */

TimeOff::TimeOff(int id, string name) {
    this->hours = hours;
    this->id = id;
    this->name = name;
}

float TimeOff::maxSck(int hours) {
    NumDays a(hours);
    this->maxSck1 = a.getDays();
    return a.getDays();
}

float TimeOff::sickTkn(int hours) {
    NumDays  a(hours);
    this->sckTkn1 = a.getDays();
    return a.getDays();
}

float TimeOff::maxUnp(int hours) {
    NumDays a(hours);
    this->maxUnp1 = a.getDays();
    return a.getDays();
}

float TimeOff::unpTkn(int hours) {
    NumDays a(hours);
    this->unpTkn1 = a.getDays();
    return a.getDays();
}

float TimeOff::maxVac(int hours) {
    NumDays a(hours);
    this->maxVac1 = a.getDays();
    return a.getDays();
}

float TimeOff::vacTkn(int hours) {
    NumDays a(hours);
    this->vacTkn1 = a.getDays();
    return a.getDays();
}