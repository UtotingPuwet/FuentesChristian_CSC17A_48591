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
#include "Graded.h"
#include "Essay.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    float grammar,
          spell,
          length,
          content;
    //Initialize Variables
    cout << "What is the numerical score of the student's grammar?(can include decimals)(0-30 points)\n";
    cin>>grammar;
    cout << "What is the numerical score of the student's spelling?(can include decimals)(0-20 points)\n";
    cin>>spell;
    cout << "What is the numerical score of the student's length of essay?(can include decimals)(0-20 points)\n";
    cin>>length;
    cout <<  "What is the numerical score of the student's content within the essay?(can include decimals)(0-30 points)\n";
    cin>>content;
    //Process or map Inputs to Outputs
    Essay student(grammar,spell,length,content);
    //Display Outputs
    cout << student.getGrad();
    //Exit stage right!
    return 0;
}