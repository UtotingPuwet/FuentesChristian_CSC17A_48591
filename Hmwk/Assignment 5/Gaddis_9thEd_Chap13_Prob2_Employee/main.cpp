/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 15, 2021 2:55PM
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries
#include "Emplye.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    int id;
    string name,
           depart,
           pos;
    
    
    //Showing all the constructors.
    //Constructor 1:
    Emplye worker1;
    //Fill information using setter functions.
    cout << "Input information for worker1: \n";
    cout << "Name of worker?\n";
    getline(cin,name);
    
    cout << "Worker department?\n";
    getline(cin,depart);
    
    cout << "Worker position?\n";
    getline(cin,pos);
    
    cout << "Worker ID?\n";
    cin>>id;
    cin.ignore();
    
    worker1.setName(name);
    worker1.setDep(depart);
    worker1.setPos(pos);
    worker1.setId(id);
    
    //Constructor 2:
    //Only partially fill in the object on creation.
    cout << "Input information for worker2: \n";
    cout << "Name of worker?\n";
    getline(cin,name);
    
    cout << "Worker department?\n";
    getline(cin,depart);
    
    cout << "Worker position?\n";
    getline(cin,pos);
    
    cout << "Worker ID?\n";
    cin>>id;
    cin.ignore();
    
    Emplye worker2(name,id);
    
    worker2.setPos(pos);
    worker2.setDep(depart);
    
    //Constructor 3:
    //Fill in in the object completely on creation.
    cout << "Input information for worker3: \n";
    cout << "Name of worker?\n";
    getline(cin,name);
    
    cout << "Worker department?\n";
    getline(cin,depart);
    
    cout << "Worker position?\n";
    getline(cin,pos);
    
    cout << "Worker ID?\n";
    cin>>id;
    cin.ignore();
    
    Emplye worker3(name,depart,pos,id);
    
    //Display Outputs
    cout << left << '\n';
    cout << setw(30) << worker1.getName() << setw(30) << worker1.getId() << setw(30) << worker1.getDep() << setw(30) << worker1.getPos() << '\n';
    cout << setw(30) << worker2.getName() << setw(30) << worker2.getId() << setw(30) << worker2.getDep() << setw(30) << worker2.getPos() << '\n';
    cout << setw(30) << worker3.getName() << setw(30) << worker3.getId() << setw(30) << worker3.getDep() << setw(30) << worker3.getPos() << '\n';
    //Exit stage right!
    return 0;
}