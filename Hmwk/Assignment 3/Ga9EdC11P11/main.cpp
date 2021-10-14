/* 
 * File:   
 * Author: Christian Fuentes
 * Created on September 30, 2021, 7:30PM
 * Purpose: 
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries
struct MnthBil {
    float house = 500.00;       //housing 
    float util = 150.00;        //utilities
    float hhexpen = 65.00;      //household expenses
    float trans = 50.00;        //transportation
    float food = 250.00;        //food
    float med = 30.00;          //medical
    float insur = 100.00;       //insurance
    float entrtan = 150.00;     //entertainment
    float cloth = 75.00;        //clothing
    float misc = 50.00;         //miscellaneous
    float total = house+util+hhexpen+trans+food+med+insur+entrtan+cloth+misc;
};
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void compare (float, float);
MnthBil getData (MnthBil user);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    MnthBil user = getData(user);
    MnthBil limit;
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    
    //Display Outputs
    cout << "Housing";
    compare(user.house,limit.house);
    cout << "Utilities";
    compare(user.util,limit.util);
    cout<< "Household Expenses";
    compare(user.hhexpen,limit.hhexpen);
    cout<< "Transportation";
    compare(user.trans,limit.trans);
    cout << "Food";
    compare(user.food,limit.food);
    cout << "Medical";
    compare(user.med,limit.med);
    cout << "Insurance";
    compare(user.insur,limit.insur);
    cout << "Entertainment";
    compare(user.entrtan,limit.entrtan);
    cout << "Clothing";
    compare(user.cloth,limit.cloth);
    cout << "Miscellaneous";
    compare(user.misc,limit.misc);
    //----------------------------------------------------------------------
    
    //Compare totals
    cout << setprecision(2) << fixed;
    if (user.total > limit.total) {
        cout << "You were $" << user.total-limit.total << " over budget";
    }
    else if (user.total < limit.total) {
        cout << "You were $" << limit.total-user.total << " under budget";
    }
    //Exit stage right!
    return 0;
}

MnthBil getData (MnthBil user) {
    cout << "Enter housing cost for the month:$\n";
    cin>>user.house;
    cout << "Enter utilities cost for the month:$\n"; 
    cin>>user.util;
    cout << "Enter household expenses cost for the month:$\n";
    cin>>user.hhexpen;
    cout << "Enter transportation cost for the month:$\n";
    cin>>user.trans;
    cout << "Enter food cost for the month:$\n";
    cin>>user.food;
    cout << "Enter medical cost for the month:$\n";
    cin>>user.med;
    cout << "Enter insurance cost for the month:$\n";
    cin>>user.insur;
    cout << "Enter entertainment cost for the month:$\n";
    cin>>user.entrtan;
    cout << "Enter clothing cost for the month:$\n";
    cin>>user.cloth;
    cout << "Enter miscellaneous cost for the month:$\n";
    cin>>user.misc;
    user.total = user.house+user.util+user.hhexpen+user.trans+user.food+user.med+user.insur+user.entrtan+user.cloth+user.misc;
    return user;
}

void compare (float user, float limit) {
    if (user > limit) {
        cout << " Over\n";
    }
    else if (user == limit) {
        cout << " Even\n";
    }
    else {
        cout << " Under\n";
    }
}