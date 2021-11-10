/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 30, 2021. 10:46 PM
 * Purpose:  Game without menu
 * Modularize and optimize the game 
 * (Really terrible version 1 in my opinion....)
 * Create logic for Ace card.
 * Added menu
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

//User Libraries
#include "Deck.h"
#include "Player.h"
//Global Constants - No Global Variables

//Function Prototypes
void destroy (Deck *);
Deck *iniDeck ();
int draw(Deck *, string);
int hidDraw (Deck *);
void print (Deck *);
int p1Menu (Deck *, Player);
bool check21 (Player);
bool chckFrst (Player &, Player);
Player game (Deck *, Player, Player);
int delMenu (Deck *, Player);
Player chckWin (Player, Player);
void menu(Deck *);



Deck *binDeck(Deck *);
void toFile (Deck *, fstream &);
Deck *frmFile (Deck *, fstream &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed
    srand (static_cast<unsigned int> (time(NULL)));
    //Declare Variable Data Types and Constants
    Deck *deck = iniDeck();
    Deck *deck2 = binDeck(deck);
    Player p1,
           dealer;
    char again = 'y';
    //Initialize Variables
    
    
    //Process or map Inputs to Outputs
    menu(deck2);
    do {
        p1 = game (deck, p1, dealer);
        cout << "Would you like to play again? Enter y or Y.\n";
        cin >> again;
    }while (again == 'y' || again == 'Y');
    
    
    //Display Outputs
    destroy (deck);
    delete deck2;
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

void print (Deck *deck) {                                                                           //Print for the deck
    for (int i = 0; i < 52; i++) {
        cout << deck->cards[i].face << " of " << deck->cards[i].suit << " has value of " << deck->cards[i].val << '\n';
    }
}


Player game (Deck *deck, Player p1, Player dealer) {
    //Initialize player and dealer
    p1.hand = 0;
    p1.ref = "You";
    
    dealer.hand = 0;
    dealer.ref = "Dealer";
    //Initialize player draw
    p1.hand += draw(deck,p1.ref);
    p1.hand += draw(deck,p1.ref);
    
    cout << "Your hand is " << p1.hand << '\n';

    //Initialize dealer hand
    dealer.hand += draw(deck,dealer.ref);
    dealer.hand += hidDraw(deck);                   //Doesn't print out this card
    
    //Check if either player got ace from first turn.
    if (chckFrst(p1,dealer) == true) {
        return p1;
    }
    
    //p1menu will ask player if stand or hit.
    p1.hand = p1Menu(deck, p1);
    
    cout << "\nDealer hand is " << dealer.hand << '\n' << '\n';
    dealer.hand = delMenu(deck, dealer);
    
    cout << "\nDealer hand is " << dealer.hand << '\n';
    
    //Compare hands and check 21
    p1 = chckWin(p1,dealer);
    
    return p1;
}


//Using this to check if anyone got 21 within the first cards that were drawn
//If anyone did the function will return true and in the game function
//The game function will return and exit the game announcing the winner
bool chckFrst (Player &p1, Player dealer) {
    //Check 21 for the player.
    if (check21(p1) == true) {
        p1.frstTrn = true;
    }
    //Check 21 for dealer
    if (check21(dealer) == true) {
        dealer.frstTrn = true;
    }
    //Fully check all possibilities for player or dealer getting 21
    if (dealer.frstTrn == true && p1.frstTrn == true) {
        cout << "PUSH!" << endl;
        p1.pushes++;
        return true;
    }
    else if (dealer.frstTrn == true && p1.frstTrn == false) {
        cout << "DEALER WON!" << endl;
        p1.loss++;
        return true;
    }
    else if (dealer.frstTrn == false && p1.frstTrn == true) {
        cout << "PLAYER GOT 21!" << endl;
        p1.wins++;
        return true;
    }
    return false;
}


bool check21 (Player player) {
    if (player.hand == 21) {
        return true;
    }
    return false;
}


Player chckWin (Player p1, Player dealer) {
    if (dealer.hand == 21 && p1.hand == 21) {           //dealer compare for 21 and player 21
        cout << "PUSH!" << endl;
        p1.pushes++;
        return p1;
    }
    else if (dealer.hand == 21 && p1.hand != 21) {     //dealer check for 21
        cout << "DEALER WON!" << endl;
        p1.loss++;
        return p1;
    }
    else if (dealer.hand != 21 && p1.hand == 21) {     //player check  for 21
        cout << "PLAYER GOT 21!" << endl;
        p1.wins++;
        return p1;
    }
    else {
        if (p1.hand > 21) {                            //check for player bust
            cout << "PLAYER BUSTED!" << endl;
            p1.loss++;
            return p1;
        }
        else if (dealer.hand > 21) {                   //check for dealer bust
            cout << "DEALER BUSTED!" << endl;
            p1.wins++;
            return p1;
        }
        else {
            if (dealer.hand > p1.hand) {              //check if dealer greater
                cout << "DEALER WINS!" << endl;
                p1.loss++;
                return p1;
            }
            else if (dealer.hand == p1.hand) {        //check push
                cout << "PUSH!" << endl;
                p1.pushes++;
                return p1;
            }
            else if (dealer.hand < p1.hand) {         //check player greater
                cout << "PLAYER WINS!" << endl;
                p1.wins++;
                return p1;
            }
        }
    }
    return p1;                                        //return to keep track of player.
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

void menu (Deck *deck2) {
    char choice;
    do {
        cout << "Welcome to Christian's Blackjack!" << '\n';
        cout << "Press 1 to play Blackjack.\n"
             << "Press 2 to see how to play Blackjack.\n"
             << "Press 3 to print binary file version of deck.\n";
        cin>>choice;
        if (choice == '2') {
            cout << "The goal of blackjack is to get a hand equal to 21." <<
                        "Each card is worth its numerical value, face cards " <<
                        "are worth 10, and ace is worth either 1 or 11.\n" << 
                        "Both the player and the dealer start with 2 cards " <<
                        "and the dealer flips " <<
                        "only 1 card up to show to the player. The player must " <<
                        "then decide if they want to hit (draw)\nor stand (not " <<
                        "draw).Press 1 to hit and 2 to stand.\n";
        }
        else if (choice == '3') {
            print(deck2);
        }
        else if (choice == '4') {
            exit(0);
        }
        else if (choice > '5' || choice < '1') {
            cout << "Please enter  valid number\n";
        }
    }while (choice != '1');
}

Deck *binDeck (Deck *deck) {
    fstream binFile;
    Deck *deck2;
    binFile.open("card.bin", ios::binary | ios::in | ios::out);
    
    toFile(deck,binFile);
    
    deck2 = frmFile(deck2,binFile);
    
    binFile.close();
    
    return deck2;
}

void toFile (Deck *deck, fstream &binFile) {
    long cursor = 0L;

    binFile.seekp(cursor,ios::beg);
    binFile.write(reinterpret_cast<char *> (deck->cards),sizeof(Card) * 52);

}

Deck *frmFile(Deck *deck2, fstream &binFile) {
    long cursor = 0L;
    
    Deck *deck =  new Deck;
    binFile.seekg(cursor,ios::beg);
    binFile.read(reinterpret_cast<char *> (deck->cards), sizeof(Card) * 52);
    
    
    return deck;
}