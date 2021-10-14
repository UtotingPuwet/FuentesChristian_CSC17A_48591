/*
 *File: main.cpp
 *Author: Christian Fuentes
 *Created on October 7, 2021
 *Purpose: Sentence Filter With Binary Files and Text file testing
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Program executions

int main (int argc, char** argv) {  
    fstream binFile;
    ifstream in;
    ofstream out;
    fstream test;
    
    char user[50] = {"I hate you. I HATE YOU."};
    
    char lower[50];
    
    string metype;
    long cursor = 0L;
    long size;

    
    getline(cin,metype);
    
    binFile.open(metype, ios::binary | ios::in | ios::out);
    
    
    
    
    binFile.write(reinterpret_cast<char *> (user), sizeof(user));
    
    binFile.seekg(cursor, ios::end);
    size = binFile.tellg();
    
    binFile.seekg(cursor,ios::beg);
    binFile.read(reinterpret_cast<char *> (lower), sizeof(lower));
    
    for (int i = 0; i < size; i++) {
        if (lower[i] >= 65 && lower[i] <= 90) {
            if (lower[i-2] == 46) {
                
            }
            else {
                lower[i] += 32;
            }
        }
        lower[0] -= 32;
        cout << lower[i];
    }
    
    
    binFile.close();
    
    
return 0;
}
