#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Drink{
    string name;
    float cost;
    int amount;
};

void prntDnk (string, float, int);
void prntMnu (Drink, Drink, Drink, Drink, Drink);
int pay (string,float, Drink , Drink, Drink, Drink, Drink);

int main() {
    //Declare all variables
    Drink cola,             //cola 
          root,             //root beer
          lemlim,           //lemon lime soda
          grape,            //grape soda
          cream;            //cream soda
    string user;            //the name of the drink the user wants
    float paid;             //amount user paid
    float profit = 0;           //profits
    float change;
    string leave = "Quit";
    
    //Initialize all variables
    cola.name     = "Cola";
    cola.cost     = 75;
    cola.amount   = 20;
    
    root.name     = "Root Beer";
    root.cost     = 75;
    root.amount   = 20;
    
    lemlim.name   = "Lemon-Lime";
    lemlim.cost   = 75;
    lemlim.amount = 20;
    
    grape.name    = "Grape Soda";
    grape.cost    = 80;
    grape.amount  = 20;
    
    cream.name    = "Cream Soda";
    cream.cost    = 80;
    cream.amount  = 20;
    
    while(user != leave) {
        prntMnu (cola,root,lemlim,grape,cream);
        getline(cin,user);
        if (user == "Quit") {
            break;
        }
        cin>>paid;
        cin.ignore();
        if (user == cola.name) {
            cola.amount -= 1;
            profit+=cola.cost;
            change = paid-cola.cost;
        }
        else if (user == root.name) {
            root.amount -= 1;
            profit+=root.cost;
            change = paid-root.cost;
        }
        else if (user == lemlim.name) {
            lemlim.amount -= 1;
            profit+=lemlim.cost;
            change = paid-lemlim.cost;
        }
        else if (user == grape.name) {
            grape.amount -= 1;
            profit+=grape.cost;
            change = paid-grape.cost;
        }
        else if (user == cream.name){
            cream.amount -= 1;
            profit+= cream.cost;
            change = paid-cream.cost;
        }
        cout << change << '\n';
        
    }
    cout << profit << '\n';
    
	//your code here
	return 0;
}
void prntDnk (string name, float cost, int amount) {
    short spaces = 3;
    if (name.length() == 4) {
        spaces = 9;
    }
    else if (name.length() == 9) {
        spaces = 4;
    }
    cout << name << setw(spaces) << cost << setw(4) << amount << '\n';
}

void prntMnu (Drink cola, Drink root, Drink lemlim, Drink grape, Drink cream) {
    prntDnk(cola.name,cola.cost,cola.amount);
    prntDnk(root.name,root.cost,root.amount);
    prntDnk(lemlim.name,lemlim.cost,lemlim.amount);
    prntDnk(grape.name,grape.cost,grape.amount);
    prntDnk(cream.name,cream.cost,cream.amount);
    cout << "Quit\n";
}
