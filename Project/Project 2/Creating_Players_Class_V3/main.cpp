/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on December 1, 2021. 7:36 PM
 * Purpose:  Creating players using classes. Adding dealer.
 * Below is plan from last version.
 * Plan: Add operator overloading to wins/draws/losses. Eventually.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Player.h"
#include "Dealer.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {

    //Random number seed
    srand(static_cast<unsigned int>(time(NULL)));
    //Declare Variable Data Types and Constants
    Player p1("Christian");
    Player p2 = p1;
    Dealer dealer;
    int random = rand()%52;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    cout << "p1 :\n";
    cout << p1.getName() << '\n';
    cout << p1.getWins() << '\n';
    cout << p1.getLoss() << '\n';
    cout << p1.getPush() << '\n';
    cout << p1.getHand() << '\n';
    cout << "p2 :\n";
    cout << p2.getName() << '\n';
    cout << p2.getWins() << '\n';
    cout << p2.getLoss() << '\n';
    cout << p2.getPush() << '\n';
    cout << p2.getHand() << '\n';
    
    
    p1++;
    p2++;
    
    cout << "p1 wins after ++ operator: " << p1.getWins() << '\n';
    
    p1+p2;
    
    cout << "p1 wins after + operator with p2: " << p1.getWins() << '\n';
    
    p1-p2;
    
    cout << "p1 wins after - operator with p2: " << p1.getWins() << '\n';
    
    //Display Outputs
    
    //Reallocate Memory
    
    //Exit stage right!
    return 0;
}