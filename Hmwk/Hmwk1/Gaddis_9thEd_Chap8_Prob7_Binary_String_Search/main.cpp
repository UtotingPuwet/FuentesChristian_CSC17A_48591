/*
    Author: Christian Fuentes
    Date:   September 2,2021  5:41pm
    Purpose:Sort and search.
    Version:First
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <algorithm>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


//Function Prototypes
string binSrch (string [], string, int);
void swap (string, string);
void selSort (string [], int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int NUM_NAMES = 20;
    string target;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",  "Griffin, Jim", "Stamey, Marty", "Rose, Geri", "Taylor, Terri", 
                               "Johnson, Jill", "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob", 
                               "Rutherford, Greg", "Javens, Renee", "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
    //Initialize variables
    
    //Process, map inputs to outputs
    selSort(names, NUM_NAMES);
    //Display your initial conditions as well as outputs.
    for (int i = 0; i < NUM_NAMES; i++) {
        cout << names[i] << '\n';
    }

    cout << "What name are you looking for?\n";
    getline(cin,target);
    cout << binSrch(names,target,NUM_NAMES);
    //Exit stage right
    return 0;
}


void selSort (string names[], int MAX) {
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = i+1; j < MAX; j++) {
            if (names[j][0] < names[i][0]) {
                string temp = names[j];
                names[j] = names[i];
                names[i] = temp;
            }
        }
    }
}

string binSrch (string name[], string target, int MAX) {
    int first,
        middle,
        last;
    bool found = false;
    
    first = 0;
    last = MAX;
    
    while (!found && first <= last) {
        middle = (first+last)/2;
        if (name[middle] == target) {
            found = true;
            return "Found\n";
        }
        else if (name[middle] > target) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    return "Not Found\n";
}