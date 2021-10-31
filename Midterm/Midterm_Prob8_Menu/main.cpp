/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 22,  2021  3:20 PM
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//User Libraries
#include "ChckAcc.h"
#include "Paychck.h"
#include "Array.h"
#include "Stats.h"
#include "Primes.h"
//Global Constants - No Global Variables

//Function Prototypes
void menu();
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
//Problem 1 Functions

ChckAcc *init ();
bool verify (string);
void destroy (ChckAcc *);

//Problem 2 Functions

Paychck *init2 ();
void getPay (Paychck *);
int numPay (int, int);
string engPay (int);
void display (Paychck *);

//Problem 3 Functions

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Problem 4

void encrypt();
void decrypt();
int check (int);
bool valid (string);

//Problem 5

//None

//Problem 6

//None

//Problem 7

void getPrime (int);
Primes *getData (int);
void print (Primes *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    char choice;
    //Initialize Variables
    do {
        menu();
        cin>>choice;
        
        
        //Process
        switch (choice) {
            case '1': {prob1();break;}
            case '2': {prob2();break;}
            case '3': {prob3();break;}
            case '4': {prob4();break;}
            case '5': {prob5();break;}
            case '6': {prob6();break;}
            case '7': {prob7();break;}
            default : cout << "Exiting menu\n";
        }   
    }while (choice >= '1' && choice <= '7');
    //Exit stage right!
    return 0;
}

void menu () {
    cout << '\n' << "Choosing from the following:" << endl;
    cout << "Type 1 for Problem 1" << endl;
    cout << "Type 2 for Problem 2" << endl;
    cout << "Type 3 for Problem 3" << endl;
    cout << "Type 4 for Problem 4" << endl;
    cout << "Type 5 for Problem 5" << endl;
    cout << "Type 6 for Problem 6" << endl;
    cout << "Type 7 for Problem 7" << endl;
}
//-------------------------------------------------------------------------------
//Problem 1
void prob1 () {
    //Declare Variable Data Types and Constants
    ChckAcc *bank;
    //Initialize Variables
    bank = init();
    //Process or map Inputs to Outputs
    
    //Display Outputs
    cout << "Bank account number:  " << bank->account << '\n';
    cout << "Person's name:        " << bank->name << '\n';
    cout << "Person's address:     " << bank->address << '\n';
    cout << "Current balance:      " << bank->begBal << '\n';
    cout << "Balance after checks: " << bank->newBal << '\n';
    if (bank->newBal < 0) {
        cout << "$25 fee for being overdrawn.\n";
        bank->newBal -= 25;
        cout << "New balance after fees is: " << bank->newBal << '\n';
    }
    
    //Deallocate memory
    destroy (bank);
    delete bank;
    return;
}
void destroy (ChckAcc *bank) {
    delete []bank->withdrw;
    delete []bank->deposit;
}

ChckAcc *init () {
    ChckAcc *bank = new ChckAcc;
    //Initialize account number + verify
    cout << "Please input account number.\n";
    cin>>bank->acc;
    if (verify(bank->acc) == false) {
        cout << "Invalid account number.\n";
        return bank;
    }
    bank->account = stoi(bank->acc);
    
    //Get name of user.
    cout << "Please input your name.\n";
    cin.ignore();
    getline(cin, bank->name);
    
    //Get user's address
    cout << "Please input your address.\n";
    getline(cin, bank->address);
    
    //Get user's beginning balance
    cout << "Please enter current balance.\n";
    cin >> bank->begBal;
    
    //Get withdraw 
    cout << "How many withdraw checks are you entering?\n";
    cin >> bank->nWith;
    
    bank->withdrw = new int[bank->nWith]; //allocate new memory for withdrw
    
    bank->newBal = bank->begBal;
    
    for (int i = 0; i < bank->nWith; i++) {
        cout << "Please enter withdraw checks one at a time.\n";
        cin>>bank->withdrw[i];
        bank->newBal -= bank->withdrw[i];
    }
    
    //Get deposit
    cout << "How many deposit checks are you entering?\n";
    cin >> bank->nDepo;
    
    bank->deposit = new int [bank->nDepo];
    
    for (int i = 0; i < bank->nDepo; i++) {
        cout << "Please enter deposit checks one at a time.\n";
        cin>>bank->deposit[i];
        bank->newBal += bank->deposit[i];
    }
    
    return bank;
    
}

bool verify (string s) {
    if (s.length() > 5) {
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------
//Problem 2
void prob2 (){
    //Declare Variable Data Types and Constants
    Paychck *checks;
    //Initialize Variables
    checks = init2();
    //Process or map Inputs to Outputs
    
    getPay(checks);
    
    //Display results
    
    display(checks);
    
    //Deallocate memory
    delete []checks;
    return;
}

Paychck *init2 () {
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
//---------------------------------------------------------------------------------
//Problem 3
void prob3 (){
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    return;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats; 
    
    
    //Looking for frequency
    stats->modFreq = 1;                                 //max Frequency
    
    for (int i = 0; i < array->size; i++) {             //checking frequency
        int curFreq = 0;
        for (int j = 0; j < array->size; j++) {
            if (array->data[i] == array->data[j]) {     //checking array->data[i] and array->data[j]
                curFreq++;
            }
        }
        if (curFreq > stats->modFreq && curFreq > 1) {  //has to occur more than once because j starts at 0 and will count the element i is looking for
            stats->modFreq = curFreq;
        }
    }
    
    //Find number of modes
    int nModes = 0;
    if (stats->modFreq > 1) {                           //if not over 1 then we want program to print null
        for (int i = 0; i < array->size; i++) {
            int curFreq = 0;                            //check frequency again
            for (int j = 0;j < array->size; j++) {
                if (array->data[i] == array->data[j]) {
                    curFreq++;
                }
            }
            if (curFreq == stats->modFreq) {            //if curFreq == modFreq then that means we have another mode
                nModes++;
            }
            i+= curFreq-1;                              //make "i" skip over already scanned elements, subtract 1 because we go too far(assume sorted)
        }
    }
    
    
    //Allocate mode
    int count = 0;                                      //separate count for the mode->data array 
    stats->mode=new Array;
    stats->mode->size=nModes;
    if(nModes!=0)stats->mode->data=new int[nModes];     //allocating mode's array
    if (stats->modFreq > 1) {
        for (int i = 0; i < array->size; i++) {         //nothing new here, 3rd time using this for loop, read above if needed
            int curFreq = 0;
            for (int j = 0; j < array->size; j++) {
                if (array->data[i] == array->data[j]) {
                    curFreq++;
                }
            }
            if (curFreq == stats->modFreq) {
                stats->mode->data[count] = array->data[i];
                count++;
            }
            i += curFreq-1;
        }
        
    }
    
    //Median
    if (array->size % 2) {
        stats->median = array->data[array->size/2];                                         //just divide by 2 to find middle number.
    }
    else {
        stats->median = (array->data[(array->size-1)/2] + array->data[array->size/2])/2.0f; //getting the two numbers in the middle, adding then div by 2
    }
    
    //Average
    stats->avg = 0;
    for (int i = 0; i < array->size; i++) {
        stats->avg += array->data[i];
    }
    
    stats->avg /= array->size;
    
    return stats;
}
//----------------------------------------------------------------------------------
//Problem 4
void prob4 () {
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
    return;
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
//--------------------------------------------------------------------------------
//Problem 5
void prob5 () {
    cout << "char maximum is 120 at factorial of 5.\n"
         << "unsigned char maximum is 208 at factorial of 6.\n"
         << "short maximum is 5040 at factorial of 7.\n"
         << "unsigned short maximum is 35200 at factorial of 9.\n"
         << "integer maximum is 479001600 at factorial of 12.\n"
         << "unsigned integer maximum is 2004189184 at factorial of 17.\n"
         << "long maximum is 2432902008176640000 at factorial of 20.\n"
         << "unsigned long is 17196083355034583040 at factorial of 22.\n"
         << "long maximum is 2432902008176640000 at factorial of 20.\n"
         << "unsigned long is 17196083355034583040 at factorial of 22.\n"
         << "float maximum is 479001600 at factorial of 12.\n"
         << "double maximum is 479001600 at factorial of 12.\n";
    return;
}
//--------------------------------------------------------------------------------
//Problem 6
void prob6() {
    cout << "base 10    " << '\t' << "base 16" << '\t' << "base 8" << '\t' << "base 2       " << '\t' << "Nasa Format" << endl;
    cout << "0.2        " << '\t' << "0.3    " << '\t' << "0.1463" << '\t' << "0.0011       " << '\t' << "666666FE   " << endl;
    cout << "3.07421875 " << '\t' << "3.13   " << '\t' << "3.046 " << '\t' << "0011.00010011" << '\t' << "62600002   " << endl;
    cout << "49.1875    " << '\t' << "31.3   " << '\t' << "61.14 " << '\t' << "00110001.0011" << '\t' << "62600006   " << endl;
    cout << "Negative versions\n";
    cout << "-0.2       " << '\t' << "0.13   " << '\t' << "0.6315" << '\t' << "0.1101       " << '\t' << "99999902   " << endl;
    cout << "-3.07421875" << '\t' << "C.ED   " << '\t' << "4.712 " << '\t' << "1100.11101101" << '\t' << "9D9FFFFE   " << endl;
    cout << "-49.1875   " << '\t' << "CE.D   " << '\t' << "16.64 " << '\t' << "11001110.1101" << '\t' << "9D9FFFFA   " << endl;
    return;
}
//--------------------------------------------------------------------------------
//Problem 7
void prob7() {
    int user;
    Primes *primes;
    
    
    cout << "What number do you want to see the prime factor of?\n";
    cin>>user;
    
    primes = getData(user);
    print (primes);
    
    delete []primes->prime;
    delete []primes;
    return;
}

Primes *getData (int origNum) {
    int num = origNum;
    Primes *primes = new Primes;
    int nFactor = 0;
    int divisor = 2;
    
    //Count how many prime factors there a re
    while (divisor * divisor <= num) {
        if (num % divisor == 0) {
            nFactor++;
            num /= divisor;
        }
        else {
            divisor++;
        }
    }
    if (num > 1) {
        nFactor++;
    }
    //Need to loop again to put all prime factors in a dynamic array (this will be uncounted for, will do another loop later)
    int *a = new int [nFactor]; //hold all prime factors
    divisor = 2;                        //set back to 2
    int count = 0;                      //a count variable for the dynamic array
    num = origNum;                      //set back to original number
    
    
    
    //Calculator  number of factors.
    while (divisor * divisor <= num) {
        if (num % divisor == 0) {
            a[count] = divisor;
            count++;
            num /= divisor;
        }
        else {
            divisor++;
        }
    }
    if (num > 1) {
        a[count] = num;
    }
    //Calculate the number of primes
    for (int i = 0; i < nFactor; i++) {
        int freq = 0;
        for (int j = 0; j < nFactor; j++) {
            if (a[i] == a[j]) {
                freq++;
            }
        }
        primes->nPrimes++;
        i+= freq-1;
    }
    
    //Create prime structure inside Primes structure
    primes->prime = new Prime [primes->nPrimes];
    //Fill the prime array structure
    count = 0;                                  //primes->prime needs its own count
    for (int i = 0; i < nFactor; i++) {
        int freq = 0;
        for (int j = 0; j < nFactor; j++) {
            if (a[i] == a[j]) {
                freq++;
            }
        }
        primes->prime[count].power = freq;
        primes->prime[count].prime = a[i];
        i+= freq-1;
        count++;
    }

    delete []a;
    return primes;
}

void print (Primes *primes) {
    for (int i = 0; i < primes->nPrimes; i++) {
        cout << primes->prime[i].prime << '^' << static_cast<int>(primes->prime[i].power);
        if (primes->nPrimes != i+1) cout << " * ";
    }
    
}