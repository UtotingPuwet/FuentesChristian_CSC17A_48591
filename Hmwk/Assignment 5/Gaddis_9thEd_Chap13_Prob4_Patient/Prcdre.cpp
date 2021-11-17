/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Prcdre.h"
#include <string>
#include <iostream>
using namespace std;

/* 
 * File:   Prcdre.h
 * Author: UtotingPuwet
 *
 * Created on November 14, 2021, 6:54 PM
 */

Prcdre::Prcdre(string name, string date, string doc, int charge) {
    setName();
    setDate();
    setDoc();
    setChrg();
}

string Prcdre::setName() {
    cout << "What is the name of the procedure?\n";
    getline(cin,name);
    return this->name;
}

string Prcdre::setDate() {
    cout << "What is the date of the procedure?\n";
    getline(cin,date);
    return this->date;
}

string Prcdre::setDoc() {
    cout << "What is the name of the Doctor?\n";
    getline(cin,doc);
    return this->doc;
}

int Prcdre::setChrg () {
    cout << "How much did this procedure cost?\n";
    cin>>charge;
    return this->charge;
}