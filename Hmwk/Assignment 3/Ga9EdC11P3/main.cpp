/* 
 * File:   
 * Author: Christian Fuentes
 * Created on September  30,2021, 7:00PM
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Division {
  float sale1,
      sale2,
      sale3,
      sale4;
      float avg;
      float total;
};
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    Division north,south,east,west;
    //Initialize Variable
    
    //For the North division
    cout << "North\n";
    cout << "Enter first-quarter sales:\n";
    cin>>north.sale1;
    cout << "Enter second-quarter sales:\n";
    cin>>north.sale2;
    cout << "Enter third-quarter sales:\n";
    cin>>north.sale3;
    cout << "Enter fourth-quarter sales:\n";
    cin>>north.sale4;
    north.avg = (north.sale1+north.sale2+north.sale3+north.sale4)/4;
    north.total = north.sale1+north.sale2+north.sale3+north.sale4;
    
    //Print annual and quarterly sales.
    cout << setprecision(2) << fixed;
    cout << "Total Annual sales:$" << north.total << '\n';
    cout << "Average Quarterly Sales:$" << north.avg <<  '\n';
    //-----------------------------------------------------------------------------------------------------------------------------------------
    //For West division
    cout << "West\n";
    cout << "Enter first-quarter sales:\n";
    cin>>west.sale1;
    cout << "Enter second-quarter sales:\n";
    cin>>west.sale2;
    cout << "Enter third-quarter sales:\n";
    cin>>west.sale3;
    cout << "Enter fourth-quarter sales:\n";
    cin>>west.sale4;
    west.avg = (west.sale1+west.sale2+west.sale3+west.sale4)/4;
    west.total = west.sale1+west.sale2+west.sale3+west.sale4;
    //print annual and quarterly sales
    cout << setprecision(2) << fixed;
    cout << "Total Annual sales:$" << west.total << '\n';
    cout << "Average Quarterly Sales:$" << west.avg <<  '\n';
    //-----------------------------------------------------------------------------------------------------------------------------------------
    //For East division
    cout << "East\n";
    cout << "Enter first-quarter sales:\n";
    cin>>east.sale1;
    cout << "Enter second-quarter sales:\n";
    cin>>east.sale2;
    cout << "Enter third-quarter sales:\n";
    cin>>east.sale3;
    cout << "Enter fourth-quarter sales:\n";
    cin>>east.sale4;
    east.avg = (east.sale1+east.sale2+east.sale3+east.sale4)/4;
    east.total = east.sale1+east.sale2+east.sale3+east.sale4;
    //print annual and quarterly sales
    cout << setprecision(2) << fixed;
    cout << "Total Annual sales:$" << east.total << '\n';
    cout << "Average Quarterly Sales:$" << east.avg <<  '\n';
    //-----------------------------------------------------------------------------------------------------------------------------------------
    //For South  Division
    cout << "South\n";
    cout << "Enter first-quarter sales:\n";
    cin>>south.sale1;
    cout << "Enter second-quarter sales:\n";
    cin>>south.sale2;
    cout << "Enter third-quarter sales:\n";
    cin>>south.sale3;
    cout << "Enter fourth-quarter sales:\n";
    cin>>south.sale4;
    south.avg = (south.sale1+south.sale2+south.sale3+south.sale4)/4;
    south.total = south.sale1+south.sale2+south.sale3+south.sale4;
    //print annual and quarterly sales
    cout << setprecision(2) << fixed;
    cout << "Total Annual sales:$" << south.total << '\n';
    cout << "Average Quarterly Sales:$" << south.avg;

    //Exit stage right!
    return 0;
}