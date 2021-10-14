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
void init(Division &, Division &, Division &, Division &);           //Initializes the names of each division.
void readInf(Division &, Division &, Division &, Division &);        //reads data from binary file.
int divYrly(Division);                                               //Yearly total for each division
int corYrly(Division, Division, Division, Division);                 //Yearly total for corporation (so add all divisions)
int divAvg(Division);                                                //Each divisions yearly average
int highLow(Division, Division, Division, Division, int &);          //Highest and lowest sales of each quarter
void print(Division, Division, Division, Division, int &);           //Print function
//Program executions


int main (int argc, char** argv) {  
    fstream binFile;
    int lowest;
    Division north;
    Division south;
    Division east;
    Division west;
    
    init(north,south,east,west);                                                   //initializing string names for each division
    
    readInf(north,south,east,west);                                                //reading in all data for structures
    
    print(north,south,east,west,lowest);                                           //print wanted data (whatever was asked in the book)
    
    
    return 0;
}

void init (Division &north, Division &south, Division &east, Division &west) {     //just initializing string names for each division
    north.name = "North";
    south.name = "South";
    east.name  = "East";
    west.name  = "West";
}

/* FOR CHRISTIAN FUENTES FUTURE REFERENCE 
 * 
 * Okay lots of code. Basically what's happening is we're creating cursor
 * to point to the place in the file we want to read from
 * who open the input file which is input.bin
 * cursor = sizeof(north.q1) * 0 will make it 0 but in other versions I had used
 * that to do cursor= sizeof(north.q1) * x where "x" is the number we want
 * because there's 16 numbers total if I made x = 3 it would give me
 * north.q4 because it's in the 3rd position.
 * Instead of that I just made it start at 0L and read downwards 
 * manually putting everything into place. 
*/

void readInf (Division &north, Division &south, Division &east, Division &west) {
    long cursor = 0L;
    fstream binFile;
    binFile.open("input.bin", ios::binary | ios::out |  ios::in);
    cursor = sizeof(north.q1) * 0;
    binFile.seekg(cursor, ios::beg);
    
    binFile.read(reinterpret_cast<char *> (&north.q1), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&north.q2), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&north.q3), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&north.q4), sizeof(north.q1));
    
    binFile.read(reinterpret_cast<char *> (&south.q1), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&south.q2), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&south.q3), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&south.q4), sizeof(north.q1));
    
    binFile.read(reinterpret_cast<char *> (&east.q1), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&east.q2), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&east.q3), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&east.q4), sizeof(north.q1));
    
    binFile.read(reinterpret_cast<char *> (&west.q1), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&west.q2), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&west.q3), sizeof(north.q1));
    binFile.read(reinterpret_cast<char *> (&west.q4), sizeof(north.q1));
    
    binFile.close();
}

int divYrly (Division div) {                                                    //yearly division sum. take each quarter from that division and add.
    int sum = div.q1+div.q2+div.q3+div.q4;
    return sum;
}

int corYrly (Division north, Division south, Division east, Division west) {    //yearly total from all divisions. Just add.
    int sum;
    sum = north.q1+south.q1+east.q1+west.q1+ north.q2+south.q2+east.q2+west.q2+
          north.q3+south.q3+east.q3+west.q3+ north.q4+south.q4+east.q4+west.q4;
    return sum;
}

int divAvg (Division div) {                                                     //each divisions average so add quarters 1-4 and divide by 4.
    int sum;
    sum = (div.q1+div.q2+div.q3+div.q4)/4;
    return sum;
}

int highLow (Division north, Division south, Division west, Division east, int &lowest) {   //highest and lowest sales for each quarter
    int q2,q3,q4;
    
    int highest = north.q1+south.q1+west.q1+east.q1;
    lowest = north.q1+south.q1+west.q1+east.q1;
    
    q2 = north.q2+south.q2+east.q2+west.q2;
    q3 = north.q3+south.q3+east.q3+west.q3;
    q4 = north.q4+south.q4+east.q4+west.q4;
    
    if (q2 > highest) highest = q2;
    if (q3 > highest) highest = q3;
    if (q4 > highest) highest = q4;
    
    if (q2 < lowest) lowest = q2;
    if (q3 < lowest) lowest = q3;
    if (q4 < lowest) lowest = q4;
    
    return highest;
}

void print (Division north, Division south, Division west, Division east, int &lowest) {        //print answers that the book wants.
    cout << "Total corporate sales for each quarter: \n";
    cout << "Quarter 1: " << north.q1+south.q1+east.q1+west.q1 << '\n';
    cout << "Quarter 2: " << north.q2+south.q2+east.q2+west.q2 << '\n';
    cout << "Quarter 3: " << north.q3+south.q3+east.q3+west.q3 << '\n';
    cout << "Quarter 4: " << north.q4+south.q4+east.q4+west.q4 << '\n';
    
    
    cout << "Total yearly sales for each quarter:\n";
    cout << "North: " << divYrly(north) << '\n';
    cout << "South: " << divYrly(south) << '\n';
    cout << "East:  " << divYrly(east) << '\n';
    cout << "West:  " << divYrly(west) << '\n';
    
    cout << "Total yearly corporate sales: " << corYrly(north,south,east,west) << '\n';
    
    cout << "Average sales for each division:\n";
    cout << "North: " << divAvg(north) << '\n';
    cout << "South: " << divAvg(south) << '\n';
    cout << "East:  " << divAvg(east) << '\n';
    cout << "West:  " << divAvg(west) << '\n';
    
    cout << "Highest sales of a quarter is " << highLow(north,south,east,west,lowest) << '\n';
    cout << "Lowest sales of a quarter is " << lowest;
}