/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Menu.h"


/* 
 * File:   Menu.h
 * Author: UtotingPuwet
 *
 * Created on December 3, 2021, 1:02 PM
 */
#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(string name) {
    this->name = name;
    p1.setName(name);
}

void Menu::useMenu() {
    char again;
    char *choice = new char [32];
    try {
        do {
            cout << "Welcome to Christian's c++ Blackjack game!" << '\n';
            cout << "Press 1 to start.\n"
                 << "Press 2 to see how to play Blackjack\n"
                 << "Press 3 to enter admin mode.(This will let you play around with certain objects that are to prove concepts.)\n"
                 << "Press 4 to exit.\n"
                 << "Any number higher than 4 will cause error 99.\n"
                 << "Any number lower than 1 will cause error 25.\n";
            cin>>choice;
            if (*choice == '2') {
                cout << "The goal of blackjack is to get a hand equal to 21." <<
                        "Each card is worth its numerical value, face cards " <<
                        "are worth 10, and ace is worth either 1 or 11.\n" << 
                        "Both the player and the dealer start with 2 cards " <<
                        "and the dealer flips " <<
                        "only 1 card up to show to the player. The player must " <<
                        "then decide if they want to hit (draw)\nor stand (not " <<
                        "draw).Press 1 to hit and 2 to stand.\n";
            }
            else if (*choice == '3') {
                
                admin();
            }
            else if (*choice == '4') {
                delete []choice;
                exit(0);
            }
            else if (*choice > '4') {
                throw 99;
            }
            else if (*choice < '1') {
                throw 25;
            }
        }while (*choice != '1');
        delete []choice;
        Game blckjack(name);
        do {
            blckjack.game(p1);
            cout << "Do you want to play again?(Enter y or Y).\n";
            cin>>again;
        }while (again == 'y' || again == 'Y');
        cout << "Name:    " << p1.getName() << '\n';
        cout << "Wins:    " << p1.getWins() << '\n';
        cout << "Losses:  " << p1.getLoss() << '\n';
        cout << "Pushes:  " << p1.getPush() << '\n';
    }
    catch(int x) {
        delete []choice;
        cout << "ERROR:" << x << '\n';
    } 
}


//Admin function where I let users play around with dummy object
//This is to specifically show off: templates and operator overloading.
//This isn't too complicated to follow along with and also has 
//Exception handling.
void Menu::admin() {
    char choice;
    cout << "Welcome to admin mode of my game!\n"
         << "Here we can do lots of stuff just to prove that I understand certain concepts :)\n"
         << "Press 1 to play around with the Dummy Player object.\n"
         << "Press 2 to exit.\n";
    cin>>choice;
    try {
        if (choice < '1') {
            throw 0;
        }
        if (choice > '2') {
            throw 3;
        }
        if (choice == '2') {
            return;
        }
        Dummy <int>p1;
        Dummy <int>p2;
        
        do {
            cout << "Hello! This is a Dummy player that only contains wins,losses, and draws." 
                 << "It uses a template and you can add or subtract two dummies.\n"
                 << "Press 1 to add 1 to all variables to dummy 1.\n"
                 << "press 2 to subtract 1  to all variables to dummy 1.\n"
                 << "Press 3 to add dummy 1 and dummy 2 and get the result to dummy 1.\n"
                 << "Press 4 to subtract dummy 1 and dummy 2 and get the results to dummy 1.\n"
                 << "Press 5 to add 1 to all variables to dummy 2.\n"
                 << "press 6 to subtract 1  to all variables to dummy 2.\n"
                 << "Press 7 to add dummy 2 and dummy 1 and get the result to dummy 2.\n"
                 << "Press 8 to subtract dummy 2 and dummy 1 and get the results to dummy 2.\n"  
                 << "Press 9 to print.\n"
                 << "Press a to exit.\n";
            cin>>choice;
            switch (choice) {
                case '1': p1++;break;
                case '2': p1--;break;
                case '3': p1 = p1+p2;break;
                case '4': p1 = p1-p2;break;
                case '5': p2++;break;
                case '6': p2--;break;
                case '7': p2 = p1+p2;break;
                case '8': p2 = p2-p1;break;
                case '9': {
                    cout << "Dummy 1:\n" << "Wins: " << p1.getWin() << '\n' << "Losses: " << p1.getLoss() << '\n' << "Pushses: " << p1.getPush() << '\n';
                    cout << "Dummy 2:\n" << "Wins: " << p2.getWin() << '\n' << "Losses: " << p2.getLoss() << '\n' << "Pushses: " << p2.getPush() << '\n';break;        
                }
            }
        }while (choice != 'a');
        return;
    }
    catch (int x) {
        cout << "ERROR:" << x << '\n';
        exit(x);
    }
}