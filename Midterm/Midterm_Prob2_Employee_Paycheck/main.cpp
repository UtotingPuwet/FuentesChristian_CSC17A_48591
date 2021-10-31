/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 21, 2021 2:34PM
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Paychck.h"
//Global Constants - No Global Variables

//Function Prototypes
Paychck *init ();
void getPay (Paychck *);
int numPay (int, int);
string engPay (int);
void display (Paychck *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Paychck *checks;
    //Initialize Variables
    checks = init();
    //Process or map Inputs to Outputs
    
    getPay(checks);
    
    //Display results
    
    display(checks);
    
    //Deallocate memory
    delete []checks;
    //Exit stage right!
    return 0;
}

Paychck *init () {
    //Size the dynamic array 
    int size;
    cout << "How many employee pay checks are you entering?\n";
    cin >> size;
    Paychck *a = new Paychck [size];
    a->size = size;
    
    //Initialize company and address now.
    cout << "Name of the company?\n";
    cin.ignore();
    getline(cin,a[0].company);
    
    cout << "Address of company?\n";
    getline(cin,a[0].address);
    
    //Initialize all elements in array
    for (int i = 0; i < a->size; i++) {
        a[i].company = a[0].company;
        a[i].address = a[0].address;
    }
    return a;
}

void getPay (Paychck *checks) {
    int payrt;
    int hours;
    for (int i = 0; i < checks->size; i++) {
        cout << "Please enter information for 1 employee at a time\n";
        cout << "Name of employee?\n";
        getline(cin,checks[i].name);
        
        cout << "Please  enter pay rate:\n";
        cin >> payrt;
        
        cout << "Please enter hours worked:\n";
        cin >> hours;
        cin.ignore();
        checks[i].amount = numPay(payrt,hours);
        checks[i].eng = engPay(checks[i].amount);
    }
}

int numPay (int payrt, int hours) {
    int pay = 0;
    if (hours > 60) {
        pay += (payrt*40);
        pay += (payrt*2)*10;
        pay += (payrt*3) * (hours-60);
        return pay;
    }
    else if (hours > 40 && hours < 60) {
        pay += (payrt * 40);
        pay += (payrt * 2) * (hours-50);
        return pay;
    }
    else {
        pay = payrt*hours;
        return pay;
    }
    return -1;
}

string engPay(int number) {
    string check;
    int n1000 = (number/1000)%10;                     //getting 1000s place
    int n100 = (number/100)%10;                       //getting 100s place
    int n10 = (number/10)%10;                         //getting 10s place
    int n1 = number%10;                               //getting 1s place
    if (number < 1 || number >= 10000) {
        cout<<number<< " is out of range.";
    }
    else {
        switch (n1000) {
            case 9: check += "Nine Thousand "; break;
            case 8: check += "Eight Thousand "; break;
            case 7: check += "Seven Thousand "; break;
            case 6: check += "Six Thousand "; break;
            case 5: check += "Five Thousand "; break;
            case 4: check += "Four Thousand "; break;
            case 3: check += "Three Thousand "; break;
            case 2: check += "Two Thousand "; break;
            case 1: check += "One Thousand "; break;
        }
        
        switch (n100) {
            case 9: check += "Nine Hundred "; break;
            case 8: check += "Eight Hundred "; break;
            case 7: check += "Seven Hundred "; break;
            case 6: check += "Six Hundred "; break;
            case 5: check += "Five Hundred "; break;
            case 4: check += "Four Hundred "; break;
            case 3: check += "Three Hundred "; break;
            case 2: check += "Two Hundred "; break;
            case 1: check += "One Hundred "; break;
        }
        
        switch (n10) {
            case 9: check += "Ninety "; break;
            case 8: check += "Eighty "; break;
            case 7: check += "Seventy "; break;
            case 6: check += "Sixty "; break;
            case 5: check += "Fifty "; break;
            case 4: check += "Forty"; break;
            case 3: check += "Thirty "; break;
            case 2: check += "Twenty "; break;
            case 1:
              switch (n1) {                                //if n is 10 is 1 then it must be a teen number
                case 9: check += "Nineteen "; break;
                case 8: check += "Eighteen "; break;
                case 7: check += "Seventeen "; break;
                case 6: check += "Sixteen "; break;
                case 5: check += "Fifteen "; break;
                case 4: check += "Fourteen "; break;
                case 3: check += "Thirteen "; break;
                case 2: check += "Twelve "; break;
                case 1: check += "Eleven "; break;
            }
        }
        
        if (n10 != 1) {
            switch (n1) {
            case 9: check += "Nine "; break;
            case 8: check += "Eight "; break;
            case 7: check += "Seven "; break;
            case 6: check += "Six "; break;
            case 5: check += "Five "; break;
            case 4: check += "Four "; break;
            case 3: check += "Three "; break;
            case 2: check += "Two "; break;
            case 1: check += "One "; break;
            }
        }
    }
    check += "Dollars";
    return check;
}

void display (Paychck *checks) {
    for (int i = 0; i < checks->size; i++) {
        cout << '\n' << checks[i].company;
        cout << '\n' << checks[i].address;
        cout << '\n' << checks[i].name << "    $" << checks[i].amount;
        cout << '\n' << checks[i].eng;
        cout << '\n' << checks[i].sigLine;
        cout << '\n';
    }
}