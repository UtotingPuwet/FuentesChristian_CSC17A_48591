/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 28, 2021. 1:46 AM
 * Purpose:  Game without menu
 * Probably get most of it down...?
 * FIXED DECK BUGS (random number was = to value of a card..???
 * FIXED ACE BUG
 * 
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries
#include "Deck.h"
#include "Player.h"
//Global Constants - No Global Variables

//Function Prototypes
void destroy (Deck *);
Deck *iniDeck ();
int draw(Deck *, string);
void print (Deck *);
int p1Menu (Deck *, Player);
bool check21 (Player);
void game (Deck *, Player, Player);
int delMenu (Deck *, Player);


//Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed
    srand (static_cast<unsigned int> (time(NULL)));
    //Declare Variable Data Types and Constants
    Deck *deck = iniDeck();
    Player p1,
           dealer;
    //Initialize Variables
    
    
    //Process or map Inputs to Outputs
    
    game (deck, p1, dealer);
    
    //Display Outputs
    destroy (deck);
    //Exit stage right!
    return 0;
}

void destroy (Deck *deck) {
    delete []deck->cards;
    delete deck;
}

Deck *iniDeck () {
    Deck *deck = new Deck;
    

    for (int i = 0; i < 52; i++) {
        switch (i%4) {
            case 0: deck->cards[i].suit = "Hearts"; break;
            case 1: deck->cards[i].suit = "Diamonds"; break;
            case 2: deck->cards[i].suit = "Spades"; break;
            case 3: deck->cards[i].suit = "Clubs"; break;
        }
        if ((i%13)+1 > 10) {
            switch ((i%13)+1) {
                case 11: deck->cards[i].face = "Jack"; break;
                case 12: deck->cards[i].face = "Queen"; break;
                case 13: deck->cards[i].face = "King"; break;
            }
            deck->cards[i].val = 10;
        }
        else if ((i%13)+1 == 1) {
            deck->cards[i].face  = "Ace";
            deck->cards[i].val = 1;
        }
        else {
            deck->cards[i].val = (i%13)+1;
            deck->cards[i].face = to_string(deck->cards[i].val);
        }
    }
    return deck;
}

int draw (Deck *deck, string person) {
    int random = rand()%52;
   
    cout << person << " got a " << deck->cards[random].face << " of " << deck->cards[random].suit << '\n'; //Open draw for player and dealer
    
    return deck->cards[random].val;
}

int hidDraw (Deck *deck) {                                                                          //Hidden draw for dealer
    int random = rand()%52;
    
    return deck->cards[random].val;
}

void print (Deck *deck) {
    for (int i = 0; i < 52; i++) {
        int random = rand()%52;
        cout << deck->cards[random].face << " of " << deck->cards[random].suit << " has value of " << deck->cards[random].val << '\n';
    }
}


void game (Deck *deck, Player p1, Player dealer) {
    //Initialize player and dealer
    p1.hand = 0;
    p1.ref = "You";
    
    dealer.hand = 0;
    dealer.ref = "Dealer";
    //Initialize player draw
    p1.hand += draw(deck,p1.ref);
    p1.hand += draw(deck,p1.ref);
    
    cout << "Your hand is " << p1.hand << '\n';
    //Check 21 for the player.
    if (check21(p1) == true) {
        p1.frstTrn = true;
    }
    //Initialize dealer hand
    dealer.hand += draw(deck,dealer.ref);
    dealer.hand += hidDraw(deck);                   //Doesn't print out this card
    //Check 21 for dealer
    if (check21(dealer) == true) {
        dealer.frstTrn = true;
    }
    //Fully check all possibilities for player or dealer getting 21
    if (dealer.frstTrn == true && p1.frstTrn == true) {
        cout << "PUSH!" << endl;
        p1.pushes++;
        return;
    }
    else if (dealer.frstTrn == true && p1.frstTrn == false) {
        cout << "DEALER WON!" << endl;
        p1.loss++;
        return;
    }
    else if (dealer.frstTrn == false && p1.frstTrn == true) {
        cout << "PLAYER GOT 21!" << endl;
        p1.wins++;
        return;
    }
    
    
    
    p1.hand = p1Menu(deck, p1);
    
    cout << "\nDealer hand is " << dealer.hand << '\n' << '\n';
    dealer.hand = delMenu(deck, dealer);
    
    cout << "\nDealer hand is " << dealer.hand << '\n';
    
    //Compare hands and check 21
    if (dealer.hand == 21 && p1.hand == 21) {
        cout << "PUSH!" << endl;
        p1.pushes++;
        return;
    }
    else if (dealer.hand == 21 && p1.hand != 21) {
        cout << "DEALER WON!" << endl;
        p1.loss++;
        return;
    }
    else if (dealer.hand != 21 && p1.hand == 21) {
        cout << "PLAYER GOT 21!" << endl;
        p1.wins++;
        return;
    }
    else {
        if (p1.hand > 21) {
            cout << "PLAYER BUSTED!" << endl;
        }
        else if (dealer.hand > 21) {
            cout << "DEALER BUSTED!" << endl;
        }
        else {
            if (dealer.hand > p1.hand) {
            cout << "DEALER WINS!" << endl;
            }
            else if (dealer.hand == p1.hand) {
                cout << "PUSH!" << endl;
            }
            else if (dealer.hand < p1.hand) {
                cout << "PLAYER WINS!" << endl;
            }
        }
    }
}

bool check21 (Player player) {
    if (player.hand == 21) {
        return true;
    }
    return false;
}

int p1Menu (Deck *deck, Player p1) {
    char choice;
    do {
        cout << "Press 1 to hit." << endl;
        cout << "Press 2 to stand." << endl;
        cin>>choice;
        if (choice == '1' && p1.hand < 21) {
            p1.hand += draw(deck,p1.ref);
        }
        cout << "Your hand is " << p1.hand << endl;
    }while (choice == '1' && p1.hand < 21);
    return p1.hand;
}

int delMenu(Deck *deck, Player dealer) {
    while (dealer.hand < 17) {
        dealer.hand += draw(deck,dealer.ref);
        cout << "Dealer hand is now " << dealer.hand << '\n';
    }
    return dealer.hand;
}