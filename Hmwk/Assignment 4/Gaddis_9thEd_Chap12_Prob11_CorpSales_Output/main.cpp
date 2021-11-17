/*
 *File: main.cpp
 *Author: Christian Fuentes
 *Created on October 12, 2021 9:02 PM
 *Purpose: Corporate Sales output.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

//User Libraries
#include "Division.h"

//Global Constants

//Function prototypes
void init(Division &, Division &, Division &, Division &);                            //initializing string names for each division
void qSales(Division &);
void toFile (Division, fstream &);
Division fillTest();
void print (Division);


//Program executions


int main (int argc, char** argv) {  
    fstream binFile;
    
    Division north;
    Division south;
    Division east;
    Division west;
    Division test;
    
    init(north,south,east,west);                                                   //initializing string names for each division
    
    
    
    qSales(north);
    qSales(south);
    qSales(east);
    qSales(west);
    
    binFile.open("input.bin", ios:: binary | ios::in | ios::out);
    toFile(north,binFile);
    toFile(south,binFile);
    toFile(east,binFile);
    toFile(west,binFile);
    
    
    
    binFile.read(reinterpret_cast<char *> (&test.q1), sizeof(north.q1));
    cout << test.q1;
    
    
    binFile.close();
    
    print(north);
    print(south);
    print(east);
    print(west);
    
    return 0;
}

void init (Division &north, Division &south, Division &east, Division &west) {     //just initializing string names for each division
    north.name = "North";
    south.name = "South";
    east.name  = "East";
    west.name  = "West";
}

void qSales (Division &div) {
    cout << "Please input quarter 1 sales for " << div.name << '\n';
    cin >> div.q1;
    while (div.q1 < 0) {
        cout << "Please input a number that isn't negative\n";
        cin >> div.q1;
    }
    cout << "Please input quarter 2 sales for " << div.name << '\n';
    cin >> div.q2;
    while (div.q2 < 0) {
        cout << "Please input a number that isn't negative\n";
        cin >> div.q2;
    }

    cout << "Please input quarter 3 sales for " << div.name << '\n';
    cin >> div.q3;
    while (div.q3 < 0) {
        cout << "Please input a number that isn't negative\n";
        cin >> div.q3;
    }

    cout << "Please input quarter 4 sales for " << div.name << '\n';
    cin >> div.q4;
    while (div.q4 < 0) {
        cout << "Please input a number that isn't negative\n";
        cin >> div.q4;
    }

}

void toFile (Division div, fstream &binFile) {
    
    binFile.write(reinterpret_cast<char *> (&div.q1), sizeof(div.q1));
    binFile.write(reinterpret_cast<char *> (&div.q2), sizeof(div.q2));
    binFile.write(reinterpret_cast<char *> (&div.q3), sizeof(div.q3));
    binFile.write(reinterpret_cast<char *> (&div.q4), sizeof(div.q4));
}

void print (Division div) {
    cout << div.name << '\n';
    cout << div.q1 << '\n';
    cout << div.q2 << '\n';
    cout << div.q3 << '\n';
    cout << div.q4 << '\n';
}