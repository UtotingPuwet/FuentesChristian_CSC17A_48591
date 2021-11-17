/*
 *File: main.cpp
 *Author: Christian Fuentes
 *Created on October 9, 2021 9:02 PM
 *Purpose: Array to File and vice versa functions.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void aryFile(string, int*, const int);
int *fileAry(string, int*, const int);
void print (int *, const int);

//Program executions


int main (int argc, char** argv) {  
    string file;
    int size;
    int *a;
    
    cout << "Please input file name\n";
    getline(cin,file);
    
    cout << "Please input array size\n";
    cin>>size;
    
    
    aryFile(file,a,size);
    
    a = fileAry(file,a,size);
    
    print(a,size);
    
    delete a;
    
    return 0;
}

void aryFile (string file, int *a, const int size){
    fstream binFile;
    int *b = new int [size];
    
    binFile.open(file, ios::binary | ios::in | ios:: out | ios::trunc);
    cout << "Please enter array content\n";
    for (int i = 0; i < size; i++) {
        cin>>b[i];
    }
    binFile.write(reinterpret_cast<char *> (b), sizeof(int) * size);
    
    binFile.close();
    delete []b;
}

int *fileAry (string file, int *a, const int size) {
    int *b = new int [size];
    fstream binFile;
    long cursor = 0L;
    binFile.open(file, ios::binary | ios::in | ios::out);
    
    cout << "Filling array with content\n";
    
    binFile.seekg(cursor, ios::beg);
    binFile.read(reinterpret_cast<char *> (b), sizeof(int) * size);
    
    binFile.close();
    
    return b;
    
}

void print (int *a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }
}