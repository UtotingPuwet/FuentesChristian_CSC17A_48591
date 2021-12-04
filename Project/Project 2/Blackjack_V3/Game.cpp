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

//This menu is for player once they get their initial 2 cards they then get to choose whether to
//Stand or hit and they are only allowed to draw if their hand isn't over 21 becasue if it is
//Then the player busted.
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


//Checking for if either person got 21.
//Check game() function to see how it works
bool Game::check21 (int hand) {
    if (hand == 21) {
        return true;
    }
    return false;
}

//So here it will check who won if neither the  player or the dealer got 21
//in the initial 2 cards. It will return player object with either a win,loss, or push
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

//Menu for dealer. The dealer will keep drawing cards until the dealer is at 17 or busts.
Dealer& Game::delMenu(Dealer &dealer) {
    int random = rand()%52;
    while (dealer.getHand() < 17) {
        random = rand()%52;
        dealer.draw(random);
    }
    return dealer;
}