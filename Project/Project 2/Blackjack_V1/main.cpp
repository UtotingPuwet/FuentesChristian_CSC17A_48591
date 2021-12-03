/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on December 2, 2021. 3:38 PM
 * Purpose:  Blackjack in function form. Not going to make the game an object yet.
 * Going to use logic from last project 1.
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
void game(Player&,Dealer&);
Player p1Menu(Player);
Dealer dealerMenu(Dealer);
bool check21(int);
Player chckWin(Player&,Dealer&);
//Execution Begins Here
int main(int argc, char** argv) {

    //Random number seed
    srand(static_cast<unsigned int>(time(NULL)));
    //Declare Variable Data Types and Constants
    Player p1("Christian");
    Dealer dealer;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    game(p1,dealer);
    //Display Outputs
    
    //Reallocate Memory
    
    //Exit stage right!
    return 0;
}

void game(Player &p1, Dealer &dealer) {
    int random = rand()%52;
    p1.iniHand();
    dealer.iniHand();
    
    if (check21(dealer.getHand()) == true) {
        cout << "Dealer got 21.\n";
        return;
    }
    else if (check21(p1.getHand()) == true) {
        cout << "Player got 21.\n";
        return;
    }
    
    p1Menu(p1);
    while (dealer.getHand() < 17) {
        random = rand()%52;
        dealer.draw(random);
    }

    chckWin(p1,dealer);
}

Player p1Menu(Player p1) {
    char choice;
    int random = rand()%52;
    do {
        cout << "Press 1 to hit.\n";
        cout << "Press 2 to stand.\n";
        cin>>choice;
        if (choice == '1' && p1.getHand() < 21) {
            p1.draw(random);
        }
        cout << p1.getName() << " hand is " << p1.getHand() << '\n';
        random = rand()%52;
    }while (choice == '1' && p1.getHand() < 21);
    return p1;
}


bool check21 (int hand) {
    if (hand == 21) {
        return true;
    }
    return false;
}

Player chckWin (Player &p1, Dealer &dealer) {
    if (dealer.getHand() == 21 && p1.getHand() == 21) {           //dealer compare for 21 and player 21
        cout << "PUSH!" << endl;
        return p1;
    }
    else if (dealer.getHand() == 21 && p1.getHand() != 21) {     //dealer check for 21
        cout << "DEALER GOT 21!" << endl;
        return p1;
    }
    else if (dealer.getHand() != 21 && p1.getHand() == 21) {     //player check  for 21
        cout << "PLAYER GOT 21!" << endl;
        return p1;
    }
    else {
        if (p1.getHand() > 21) {                            //check for player bust
            cout << "PLAYER BUSTED!" << endl;
            return p1;
        }
        else if (dealer.getHand() > 21) {                   //check for dealer bust
            cout << "DEALER BUSTED!" << endl;
            return p1;
        }
        else {
            if (dealer.getHand() > p1.getHand()) {              //check if dealer greater
                cout << "DEALER WINS!" << endl;
                return p1;
            }
            else if (dealer.getHand() == p1.getHand()) {        //check push
                cout << "PUSH!" << endl;
                return p1;
            }
            else if (dealer.getHand() < p1.getHand()) {         //check player greater
                cout << "PLAYER WINS!" << endl;
                return p1;
            }
        }
    }
    return p1;                                        //return to keep track of player.
}
