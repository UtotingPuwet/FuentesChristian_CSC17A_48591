/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables

//Function Prototypes
template <class Num>
Num total (Num n, Num &a) {
    int user;
    if (n > 0) {
        cout << "Input next number\n";
        cin>>user;
        a += user;
        return total(n-1,a);
    }
    else {
        return a;
    }
}
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int a;
    int b;
    //Initialize Variables
    b = 0;
    cout << "How many number do you want to input?\n";
    cin>>a;
    //Process or map Inputs to Outputs
    
    //Display Outputs
    cout << total(a,b);
    //Exit stage right!
    return 0;
}





