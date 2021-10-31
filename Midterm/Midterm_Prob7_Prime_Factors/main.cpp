/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 22 2021, 11:21AM
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Primes.h"
//Global Constants - No Global Variables

//Function Prototypes
void getPrime (int);
Primes *getData (int);
void print (Primes *);
//Execution Begins Here
int main(int argc, char** argv) {
    int user;
    Primes *primes;
    
    
    cout << "What number do you want to see the prime factor of?\n";
    cin>>user;
    
    primes = getData(user);
    print (primes);
    
    delete []primes->prime;
    delete []primes;
    //Exit stage right!
    return 0;
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