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

#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <string>
using namespace std;


class Employe {
private:
    string name;
    string hire;
    int id;
public:
    Employe();
    Employe(string,string,int);
    string setName(string);
    string setHire(string);
    int setId(int);
    
    string getName() {return name;}
    string getHire() {return hire;}
    int getId() {return id;}
};


#endif /* EMPLOYE_H */

