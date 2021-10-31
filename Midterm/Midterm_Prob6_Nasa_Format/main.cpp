/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 22,  2021  3:20 PM
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Display Outputs
    cout << "base 10    " << '\t' << "base 16" << '\t' << "base 8" << '\t' << "base 2       " << '\t' << "Nasa Format" << endl;
    cout << "0.2        " << '\t' << "0.3    " << '\t' << "0.1463" << '\t' << "0.0011       " << '\t' << "666666FE   " << endl;
    cout << "3.07421875 " << '\t' << "3.13   " << '\t' << "3.046 " << '\t' << "0011.00010011" << '\t' << "62600002   " << endl;
    cout << "49.1875    " << '\t' << "31.3   " << '\t' << "61.14 " << '\t' << "00110001.0011" << '\t' << "62600006   " << endl;
    cout << "Negative versions\n";
    cout << "-0.2       " << '\t' << "0.13   " << '\t' << "0.6315" << '\t' << "0.1101       " << '\t' << "99999902   " << endl;
    cout << "-3.07421875" << '\t' << "C.ED   " << '\t' << "4.712 " << '\t' << "1100.11101101" << '\t' << "9D9FFFFE   " << endl;
    cout << "-49.1875   " << '\t' << "CE.D   " << '\t' << "16.64 " << '\t' << "11001110.1101" << '\t' << "9D9FFFFA   " << endl;
    
    
    //Exit stage right!
    return 0;
}