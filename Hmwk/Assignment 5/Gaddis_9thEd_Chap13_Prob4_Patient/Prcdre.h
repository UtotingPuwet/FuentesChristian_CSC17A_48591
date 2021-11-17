/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prcdre.h
 * Author: UtotingPuwet
 *
 * Created on November 14, 2021, 6:54 PM
 */

#ifndef PRCDRE_H
#define PRCDRE_H
#include <string>
using namespace std;


class Prcdre {
private: 
    string name,
           date,
           doc;
    int charge;
public: 
    Prcdre (string,string,string,int);
    string getName() {return name;}
    string getDate() {return date;}
    string getDoc() {return doc;}
    int getChrg() {return charge;}
    
    string setName();
    string setDate();
    string setDoc();
    int    setChrg();
};


#endif /* PRCDRE_H */

