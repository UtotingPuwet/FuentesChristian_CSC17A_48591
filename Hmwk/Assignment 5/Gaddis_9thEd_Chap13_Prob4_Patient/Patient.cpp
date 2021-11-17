/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.cpp
 * Author: UtotingPuwet
 *
 * Created on November 14, 2021, 12:11 PM
 */


#include "Patient.h"
#include <string>
#include <iostream>
using namespace std;


Patient::Patient(string name, string address, string phone, string emerCont, int zip) {
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->emerCont = emerCont;
    this->zip = zip;
}

string Patient::setName() {
    cout << "Please enter patient name.\n";
    cin>>name;
    return this->name;
}

string Patient::setAdd() {
    cout << "Please enter patient address.\n";
    cin>>address;
    return this->address;
}

string Patient::setPhn() {
    cout << "Please enter patient phone number.\n";
    cin>>phone;
    return this->phone;
}

string Patient::setEmer() {
    cout << "Please enter patient emergency contact.\n";
    cin>>emerCont;
    return this->emerCont;
}

int Patient::setZip() {
    cout << "Please enter patient zip code.\n";
    cin>>zip;
    return this->zip;
}