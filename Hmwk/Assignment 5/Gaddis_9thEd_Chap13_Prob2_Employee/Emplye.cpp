/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Emplye.h
 * Author: UtotingPuwet
 *
 * Created on November 15, 2021, 4:22 PM
 */

#include <string>
#include "Emplye.h"

Emplye::Emplye() {
    name = "";
    depart = "";
    pos = "";
    id = 0;
}

Emplye::Emplye(string name, int id) {
    this->name = name;
    this->depart = "";
    this->id = id;
    pos = "";
}

Emplye::Emplye(string name, string depart, string pos, int id) {
    this->name = name;
    this->depart = depart;
    this->pos = pos;
    this->id = id;
}

string Emplye::setName(string name) {
    this->name = name;
    return this->name;
}

string Emplye::setDep(string depart) {
    this->depart = depart;
    return this->depart;
}

string Emplye::setPos(string pos) {
    this->pos = pos;
    return this->pos;
}

int Emplye::setId(int id) {
   this->id = id;
   return this->id;
}