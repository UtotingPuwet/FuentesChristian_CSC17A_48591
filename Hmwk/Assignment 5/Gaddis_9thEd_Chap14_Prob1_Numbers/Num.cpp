/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Num.h"


/* 
 * File:   Num.h
 * Author: UtotingPuwet
 *
 * Created on November 16, 2021, 12:22 AM
 */


Num::Num(int n) {
    this->num = n;
}



string Num::eng(int n) {
    string english;
    
    int n100 = (n/100)%10;                       //getting 100s place
    int n10 = (n/10)%10;                         //getting 10s place
    int n1 = n%10;                               //getting 1s place
    
    switch (n100) {
        case 9: english += "Nine Hundred "; break;
        case 8: english += "Eight Hundred "; break;
        case 7: english += "Seven Hundred "; break;
        case 6: english += "Six Hundred "; break;
        case 5: english += "Five Hundred "; break;
        case 4: english += "Four Hundred "; break;
        case 3: english += "Three Hundred "; break;
        case 2: english += "Two Hundred "; break;
        case 1: english += "One Hundred "; break;
    }

    switch (n10) {
        case 9: english += "Ninety "; break;
        case 8: english += "Eighty "; break;
        case 7: english += "Seventy "; break;
        case 6: english += "Sixty "; break;
        case 5: english += "Fifty "; break;
        case 4: english += "Forty "; break;
        case 3: english += "Thirty "; break;
        case 2: english += "Twenty "; break;
        case 1:
          switch (n1) {                                //if n is 10 is 1 then it must be a teen number
            case 1: english += teen[0]; break;
            case 2: english += teen[1]; break;
            case 3: english += teen[2]; break;
            case 4: english += teen[3]; break;
            case 5: english += teen[4]; break;
            case 6: english += teen[5]; break;
            case 7: english += teen[6]; break;
            case 8: english += teen[7]; break;
            case 9: english += teen[8]; break;
        }
    }

    if (n10 != 1) {
        switch (n1) {
        case 9: english += "Nine "; break;
        case 8: english += "Eight "; break;
        case 7: english += "Seven "; break;
        case 6: english += "Six "; break;
        case 5: english += "Five "; break;
        case 4: english += "Four "; break;
        case 3: english += "Three "; break;
        case 2: english += "Two "; break;
        case 1: english += "One "; break;
        }
    }
    return english;
}

void Num::print() {
    cout << Num::eng(num);
}

string Num::teen[9] = {"Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};