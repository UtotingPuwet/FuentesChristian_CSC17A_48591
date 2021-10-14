/*
 *File: main.cpp
 *Author: Christian Fuentes
 *Created on October 6, 2021
 *Purpose: Speakers' Bureau. Program that keeps track
 *of a speakers' bureau.
*/


#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//User Libraries
#include "CalInfo.h"

//Global Constants

//Function prototypes
int menu();
void getData(CalInfo[]);
void display(CalInfo[]);
void edit(CalInfo[]);
//Program executions

int main (int argc, char** argv) {
    CalInfo caller[10];
    
    
    int input = menu();
    while (input != 4) {
        switch (input) {
            case 1: getData(caller); break;
            case 2: display(caller); break;
            case 3: edit(caller);break;
        }
        input = menu();
    }
       

return 0;



}

int menu() {
    int input;
    cout << "This program is for  Speakers' Bureau.\n";
    cout << "Press 1 to input caller information.\n";
    cout << "Press 2 to display caller information.\n";
    cout << "Press 3 to change caller information.\n";
    cout << "Press 4 to quit.\n";
    cout << "Maximum number of callers is 10.\n";
    cin>>input;
    while (input > 4) {
        cout << "Please put proper input\n";
        cin>>input;
    }
    return input;
}

void getData (CalInfo caller[]) {
    int i;                          //this will be caller array element number.
    cout << "Please input which caller information you'd like to \n"
         << "enter (0-9).\n";
    cin >> i;
    while (i > 9) {
        cout << "Please enter number from 0-9.\n";
        cin>>i;
    }
    cout << "Please input caller name.\n";
    cin.ignore();
    getline(cin,caller[i].name);
    cout << "Please input caller's phone number (no spaces).\n";
    cin >> caller[i].phnNum;
    cout << "Please input speaker topic.\n";
    cin.ignore();
    getline(cin,caller[i].topic);
    cout << "Please input speaker fee (can' tbe less than 1).\n";
    cin>>caller[i].feeReq;
    while (caller[i].feeReq < 1) {
        cout << "Please input speaker fee not less than 1.\n";
    }
}

void display (CalInfo caller[]) {
    int i;                          //this will be to determine which caller
    cout << "Which caller would you like to pick? 0-9\n";
    cin>>i;
    cout << "Caller name is " << caller[i].name << '\n';
    cout << "Caller phone number is " << caller[i].phnNum << '\n';
    cout << "Caller speaker topic was " << caller[i].topic << '\n';
    cout << "Caller speaker fee was " << caller[i].feeReq << '\n';
}

void edit (CalInfo caller[]) {
    int i;                          //this will be used to determine which caller
    cout << "Which caller would you like to edit? 0-9\n";
    cin>>i;
        while (i > 9) {
        cout << "Please enter number from 0-9.\n";
        cin>>i;
    }
    cout << "Please input caller name.\n";
    cin.ignore();
    getline(cin,caller[i].name);
    cout << "Please input caller's phone number (no spaces).\n";
    cin >> caller[i].phnNum;
    cout << "Please input speaker topic.\n";
    cin.ignore();
    getline(cin,caller[i].topic);
    cout << "Please input speaker fee (can' tbe less than 1).\n";
    cin>>caller[i].feeReq;
    while (caller[i].feeReq < 1) {
        cout << "Please input speaker fee not less than 1.\n";
    }
}
