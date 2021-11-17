/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string>
#include "MnthDay.h"
#include <iostream>
using namespace std;

/* 
 * File:   MnthDay.h
 * Author: UtotingPuwet
 *
 * Created on November 16, 2021, 12:18 PM
 */

MnthDay::MnthDay(int n, string word) {
    this->num = n+totDay(word);
    this->eng = word;
}

string MnthDay::english(int n) {
    string eng = "";
    if (n <= 31) {
        eng = month[0];
        eng += to_string(n);
    }
    else if (n > 31 && n <= 59) {
        eng = month[1];
        eng += to_string(n-31);
    }
    else if (n > 59 && n <= 90) {
        eng = month[2];
        eng += to_string(n-59);
    }
    else if (n > 90 && n <= 120) {
        eng = month[3];
        eng += to_string(n-90);
    }
    else if (n > 120 && n <= 151) {
        eng = month[4];
        eng += to_string(n-120);
    }
    else if (n > 151 && n <= 181) {
        eng = month[5];
        eng += to_string(n-151);
    }
    else if (n > 181 && n <= 211) {
        eng = month[6];
        eng += to_string(n-181);
    }
    else if (n > 211 && n <= 242) {
        eng = month[7];
        eng += to_string(n-211);
    }
    else if (n > 242 && n <= 272) {
        eng = month[8];
        eng += to_string(n-242);
    }
    else if (n > 272 && n <= 303) {
        eng = month[9];
        eng += to_string(n-272);
    }
    else if (n > 303 && n <= 333) {
        eng = month[10];
        eng += to_string(n-303);
    }
    else if (n > 333 && n <= 365) {
        eng = month[11];
        eng += to_string(n-333);
    }
    else if (n >= 666) {
        eng = month[0];
        eng += "1";
    }
    else if (n < 1) {
        eng = month[11];
        eng += "31";
    }
    else {
        cout << "Error in user input or code.\nNow Terminating.";
        exit(0);
        
    }
    return eng;
}

void MnthDay::print() {
    cout << english(num);
}

MnthDay& MnthDay::operator ++(int n) {
    num += 1;
}

MnthDay& MnthDay::operator --(int n) {
    num -= 2;
}


int MnthDay::totDay(string word) {
    if (word == month[0]) {
        if (num > 31) {
            exit(0);
        }
        return 0;
    }
    else if (word == month[1]) {
        if (num > 28) {
            exit(0);
        }
        return 31;
    }
    else if (word == month[2]) {
        if (num > 31) {
            exit(0);
        }
        return 59;
    }
    else if (word == month[3]) {
        if (num > 30) {
            exit(0);
        }
        return 90;
    }
    else if (word == month[4]) {
        if (num > 30) {
            exit(0);
        }
        return 120;
    }
    else if (word == month[5]) {
        if (num > 30) {
            exit(0);
        }
        return 151;
    }
    else if (word == month[6]) {
        if (num > 30) {
            exit(0);
        }
        return 181;
    }
    else if (word == month[7]) {
        if (num > 31) {
            exit(0);
        }
        return 211;
    }
    else if (word == month[8]) {
        if (num > 30) {
            exit(0);
        }
        return 242;
    }
    else if (word == month[9]) {
        if (num > 31) {
            exit(0);
        }
        return 272;
    }
    else if(word  == month[10]) {
        if (num > 30) {
            exit(0);
        }
        return 303;
    }
    else if (word == month[11]) {
        if (num > 31) {
            exit(0);
        }
        return 333;
    }
}



string MnthDay::month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};