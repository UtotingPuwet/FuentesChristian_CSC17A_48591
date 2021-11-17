/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Patient.h
 * Author: UtotingPuwet
 *
 * Created on November 14, 2021, 12:11 PM
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;


class Patient {
private: string name,
                address,
                phone,
                emerCont;
         int zip;
public:
    Patient(string,string,string,string,int);
    string setName();
    string setAdd();
    string setPhn();
    string setEmer();
    int setZip();
    
    string getName(){return name;}
    string getAdd() {return address;}
    string getPhn() {return phone;}
    string getEmerc() {return emerCont;}
    int    getZip() {return zip;}
    
                
};


#endif /* PATIENT_H */

