/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 13 2021, 9:30PM
 * Purpose:  Opening a file and displaying contents on screen
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

//User Libraries

//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    fstream txtFile;
    string line;
    int count = 0;
    int count2 = 0;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    txtFile.open("input.txt", ios::in);
    
    while (txtFile >> line) {
        count++;
    }
    cout << count << '\n';
    txtFile.clear();
    txtFile.seekg(0);
    //Display Outputs
    if (count <= 10) {
        while (txtFile >> line) {
            cout << line << '\n';
        }
        cout << "Entire file as been displayed\n";
    } 
    else {
        while (count2 != 10) {
            txtFile >> line;
            cout << line << '\n';
            count2++;
        }
    }
    
    
    
    txtFile.close();
    //Exit stage right!
    return 0;
}