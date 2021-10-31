/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 20 2:51 PM
 * Purpose:  Bank account tracking
 */

//System Libraries
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//User Libraries
#include "ChckAcc.h"
//Global Constants - No Global Variables

//Function Prototypes
ChckAcc *init ();
bool verify (string);
void destroy (ChckAcc *);

//Execution Begins Here
int main(int argc, char** argv) {
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
    //Exit stage right!
    return 0;
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
