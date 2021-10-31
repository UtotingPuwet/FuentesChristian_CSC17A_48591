/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;

//User Libraries

//Global Constants - No Global Variables

//Function Prototypes
void encrypt();
void decrypt();
int check (int);
bool valid (string);


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int choice;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    
    //Display Outputs
    cout << "Press 1 to encrypt.\n"
         << "Press 2 to decrypt.\n";
    cin>>choice;
    switch (choice) {
        case 1: encrypt(); break;
        case 2: decrypt();
    }
    //Exit stage right!
    return 0;
}

void encrypt() {
    //Declare variables
    string s;       //use this to validate number. (useless variable otherwise)
    int temp;
    int n1,         //split up the number
        n2,
        n3,
        n4;
    int orig;       //number before encryption
    int secret;     //number after encryption.
    //Initialize variables
    secret = 0;
    cout << "Input the number you'd like to encrypt.\n";
    cin>>s;
    
    if (valid(s) == false) {
        cout << "INVALID NUMBER, MUST BE ONLY 4 DIGITS AND ONLY NUMBERS 0-7.\n";
        return;
    }
    
    //set "orig" variable
    orig = stoi(s);
    
    //Set n1-n4
    n1 = (orig/1000)%10;
    n2 = (orig/100)%10;
    n3 = (orig/10)%10;
    n4 = orig%10;
    //Process
    n1 += 3;
    n2 += 3;
    n3 += 3;
    n4 += 3;

    n1 %= 8;
    n2 %= 8;
    n3 %= 8;
    n4 %= 8;
    
    temp = n1;
    n1 = n3;
    n3 = temp;
    
    temp = n2;
    n2 = n4;
    n4 = temp;
    
    //Output
    secret += n1*1000;
    secret += n2*100;
    secret += n3*10;
    secret += n4;
    cout << "Encrypted number is " << secret;
}

void decrypt() {
    //Declare variables
    string s;       //use this to validate number. (useless variable otherwise)
    int temp;
    int n1,         //split up the number
        n2,
        n3,
        n4;
    int orig;       //number after decryption
    int secret;     //number before decryption.
    
    //Initialize Variables
    orig = 0;
    cout << "Please enter number you'd like to decrypt.\n";
    cin>>s;
    
    //Validate the number entered.
    if (valid(s) == false) {
        cout << "INVALID NUMBER, MUST BE ONLY 4 DIGITS AND ONLY NUMBERS 0-7.\n";
        return;
    }
    //Set the variable "secret"
    secret = stoi(s);
    
    //Set n1-n4 variables
    n1 = (secret/1000)%10;
    n2 = (secret/100)%10;
    n3 = (secret/10)%10;
    n4 = secret%10;
    
    //Process
    temp = n1;
    n1 = n3;
    n3 = temp;
    
    temp = n2;
    n2 = n4;
    n4 = temp;
    
    
    n1 += 5;
    n2 += 5;
    n3 += 5;
    n4 += 5;
    
    n1 = check(n1);
    n2 = check(n2);
    n3 = check(n3);
    n4 = check(n4);
    //Output
    orig += n1*1000;
    orig += n2*100;
    orig += n3*10;
    orig += n4;
    cout << "Original number was " << orig;
    
}

int check (int n) {
    if (n >= 8) {
        return n-8;
    }
    return n;
}

bool valid (string s) {
    //Declare  variables
    int n1,         //split up the number
        n2,
        n3,
        n4;
    int numb;
    //Initializing variables
    numb = stoi(s);
    
    n1 = (numb/1000)%10;
    n2 = (numb/100)%10;
    n3 = (numb/10)%10;
    n4 = numb%10;
    
    //Check and validate that  nothing is over 8 and is only 4 digits.
    if (s.length() > 4) {
        return false;
    }
    if (s.length() < 4) {
        return false;
    }
    if (numb > 7777) {
        return false;
    }
    if (n1 > 7) {
        return false;
    }
    if (n2 > 7) {
        return false;
    }
    if (n3 > 7) {
        return false;
    }
    if (n4 > 7) {
        return false;
    }
    return true;
    
}