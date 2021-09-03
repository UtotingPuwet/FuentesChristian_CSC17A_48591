/*
    Author: Christian Fuentes
    Date:   September 2,2021  3:26pm
    Purpose:Track weather conditions.
    Version:First
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <fstream>     //File Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


//Function Prototypes


//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    ofstream out;
    ifstream in;
    int const SIZE = 3;
    char data[SIZE][30];
    char  S,
          C,
          R;
    //Initialize variables
    in.open("weather.txt");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < 30; j++) {
            in >> data[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        S = 0;
        R = 0;
        C = 0;
        if (i == 0) {
            cout << "June: ";
        }
        else if (i == 1) {
            cout << "July: ";
        }
        else {
            cout << "August: ";
        }
        for (int j = 0; j < 30; j++) {
            switch (data[i][j]) {
                case 'S' : S++; break;
                case 'R' : R++; break;
                case 'C' : C++; break;
            }
        }
        cout << (int)S << " sunny days, " << (int)R << " rainy days, and " << (int)C << " cloudy days.\n";
        cout << '\n';
    }
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    in.close();
    //Exit stage right
    return 0;
}