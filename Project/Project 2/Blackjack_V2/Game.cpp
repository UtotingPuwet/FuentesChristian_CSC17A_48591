/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "Game.h"
#include <iostream>


Game::Game(string name) {
    p1.setName(name);
}

void Game::game() {
    Dealer dealer;
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
    delMenu(dealer);

    chckWin(p1,dealer.getHand());
}

Player Game::p1Menu(Player p1) {
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


bool Game::check21 (int hand) {
    if (hand == 21) {
        return true;
    }
    return false;
}

Player chckWin (Player &p1, int dealer) {
    if (dealer == 21 && p1.getHand() == 21) {           //dealer compare for 21 and player 21
        cout << "PUSH!" << endl;
        p1.pushes++;
        return p1;
    }
    else if (dealer == 21 && p1.getHand() != 21) {     //dealer check for 21
        cout << "DEALER GOT 21!" << endl;
        p1.losses++;
        return p1;
    }
    else if (dealer != 21 && p1.getHand() == 21) {     //player check  for 21
        cout << "PLAYER GOT 21!" << endl;
        p1.wins++;
        return p1;
    }
    else {
        if (p1.getHand() > 21) {                            //check for player bust
            cout << "PLAYER BUSTED!" << endl;
            p1.losses++;
            return p1;
        }
        else if (dealer > 21) {                   //check for dealer bust
            cout << "DEALER BUSTED!" << endl;
            p1.wins++;
            return p1;
        }
        else {
            if (dealer > p1.getHand()) {              //check if dealer greater
                cout << "DEALER WINS!" << endl;
                p1.losses++;
                return p1;
            }
            else if (dealer == p1.getHand()) {        //check push
                cout << "PUSH!" << endl;
                p1.pushes++;
                return p1;
            }
            else if (dealer < p1.getHand()) {         //check player greater
                cout << "PLAYER WINS!" << endl;
                p1.wins++;
                return p1;
            }
        }
    }
    return p1;                                        //return to keep track of player.
}

Dealer& Game::delMenu(Dealer &dealer) {
    int random = rand()%52;
    while (dealer.getHand() < 17) {
        random = rand()%52;
        dealer.draw(random);
    }
    return dealer;
}