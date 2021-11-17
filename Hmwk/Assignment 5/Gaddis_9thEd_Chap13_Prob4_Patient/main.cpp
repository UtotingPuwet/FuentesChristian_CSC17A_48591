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
#include "Patient.h"
#include "Prcdre.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    string name,
           address,
           phone,
           emerCont;
    int zip,
        total;
    
    
    
    
    

    //Initialize Variables
    total = 0;
    
    cout << "Please enter patient name.\n";
    getline(cin,name);
    cout << "Please enter patient address.\n";
    getline(cin,address);
    cout << "Please enter patient phone number.\n";
    getline(cin,phone);
    cout << "please enter patient emergency contact.\n";
    getline(cin,emerCont);
    cout << "Please enter patient zip code.\n";
    cin>>zip;
    cin.ignore();
    
    
    //Process or map Inputs to Outputs
    Patient person(name,address,phone,emerCont,zip);
    

     
    cout << "Now enter procedure information.\n";
    
    //Procedure classes next
    Prcdre prcdre1("","","",0);
    cin.ignore();
    
    Prcdre prcdre2("","","",0);
    cin.ignore();

    Prcdre prcdre3("","","",0);
    
    
    //Display Outputs
    cout << "All information is here: \n";
    cout << person.getName() << '\n';
    cout << person.getAdd() << '\n';
    cout << person.getPhn() << '\n';
    cout << person.getEmerc() << "\n\n\n";
    
    
    
    cout << prcdre1.getName() << '\n' << prcdre1.getDate() << '\n' << prcdre1.getDoc() << '\n' << prcdre1.getChrg() << '\n';
    cout << prcdre2.getName() << '\n' << prcdre2.getDate() << '\n' << prcdre2.getDoc() << '\n' << prcdre2.getChrg() << '\n';
    cout << prcdre3.getName() << '\n' << prcdre3.getDate() << '\n' << prcdre3.getDoc() << '\n' << prcdre3.getChrg() << '\n';

    
    total = prcdre1.getChrg() + prcdre2.getChrg() + prcdre3.getChrg(); 
    cout << "Total cost of all 3 procedures: " << total;
    
    
    //Exit stage right!
    return 0;
}