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

#ifndef EMPLYE_H
#define EMPLYE_H
#include <string>
using namespace std;


class Emplye {
private:
    string name,
           depart,
           pos;
    int id;
public: 
    Emplye();
    Emplye(string,int);
    Emplye(string,string,string,int);
    
    string getName() {return name;}
    string getDep() {return depart;}
    string getPos() {return pos;}
    int getId() {return id;}
    
    string setName(string);
    string setDep(string);
    string setPos(string);
    int setId(int);
};


#endif /* EMPLYE_H */

