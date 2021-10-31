/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paychck.h
 * Author: UtotingPuwet
 *
 * Created on October 21, 2021, 2:36 PM
 */

#ifndef PAYCHCK_H
#define PAYCHCK_H
#include <cstring>

struct Paychck{
    string company;                                             //company name
    string address;                                             //address of company
    string name;                                                //name of person
    int amount;                                                 //numerical version of pay
    string eng;                                                 //English version of pay
    string sigLine = "Signature:    _____________________________________"; //signature line
    int size;
    
};



#endif /* PAYCHCK_H */

