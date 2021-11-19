/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employe.h
 * Author: UtotingPuwet
 *
 * Created on November 18, 2021, 12:04 AM
 */
#include "Employe.h"

Employe::Employe(string name, string hire, int id) {
    this->name = name;
    this->hire = hire;
    this->id = id;
}

string Employe::setHire(string hire) {
    this->hire = hire;
    return hire;
}

string Employe::setName(string name) {
    this->name = name;
    return name;
}

int Employe::setId(int id) {
    this->id = id;
    return id;
}

Employe::Employe() {
    
}