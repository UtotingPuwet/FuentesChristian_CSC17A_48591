/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on November 29, 2021. 8:13 PM
 * Purpose:  Creating cards using classes.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Card.h"
//Global Constants - No Global Variables

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Card card(0);
    Card card1(1);
    Card card2(2);
    Card card3(3);
    Card card4(4);
    Card card5(5);
    Card card6(6);
    Card card7(7);
    Card card8(8);
    Card card9(9);
    Card card10(10);
    Card card11(11);
    Card card12(12);
    Card card13(13);
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    cout <<  card.getSuit() << " of " << card.getFace() << " is equal to " << card.getVal() << '\n';
    cout <<  card1.getSuit() << " of " << card1.getFace() << " is equal to " << card1.getVal() << '\n';
    cout <<  card2.getSuit() << " of " << card2.getFace() << " is equal to " << card2.getVal() << '\n';
    cout <<  card3.getSuit() << " of " << card3.getFace() << " is equal to " << card3.getVal() << '\n';
    cout <<  card4.getSuit() << " of " << card4.getFace() << " is equal to " << card4.getVal() << '\n';
    cout <<  card5.getSuit() << " of " << card5.getFace() << " is equal to " << card5.getVal() << '\n';
    cout <<  card6.getSuit() << " of " << card6.getFace() << " is equal to " << card6.getVal() << '\n';
    cout <<  card7.getSuit() << " of " << card7.getFace() << " is equal to " << card7.getVal() << '\n';
    cout <<  card8.getSuit() << " of " << card8.getFace() << " is equal to " << card8.getVal() << '\n';
    cout <<  card9.getSuit() << " of " << card9.getFace() << " is equal to " << card9.getVal() << '\n';
    cout <<  card10.getSuit() << " of " << card10.getFace() << " is equal to " << card10.getVal() << '\n';
    cout <<  card11.getSuit() << " of " << card11.getFace() << " is equal to " << card11.getVal() << '\n';
    cout <<  card12.getSuit() << " of " << card12.getFace() << " is equal to " << card12.getVal() << '\n';
    cout <<  card13.getSuit() << " of " << card13.getFace() << " is equal to " << card13.getVal() << '\n';
    //Display Outputs
    
    //Exit stage right!
    return 0;
}