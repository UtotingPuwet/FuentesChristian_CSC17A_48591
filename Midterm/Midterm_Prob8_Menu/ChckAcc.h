/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ChckAcc.h
 * Author: UtotingPuwet
 *
 * Created on October 20, 2021, 2:51 PM
 */

#ifndef CHCKACC_H
#define CHCKACC_H
#include <cstring>


struct ChckAcc {
    string acc;         //going to use this to veryify account number (account number)
    int account;        //numeric version of account number
    string name;        //name of person
    string address;     //address of person
    int    begBal;      //beginning balance
    int *withdrw;        //how many checks the person wrote
    int *deposit;        //how much the person has deposited.
    int nWith;           //how many withdrew checks
    int nDepo;           //how many deposit checks
    int newBal;          //new balance
};

#endif /* CHCKACC_H */

