/* 
 * File:
 * Author: Christian Fuentes
 * Date: 3/9/2021
 * Purpose:
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
     float a,b,c,d;
    //Initialize or input data here
    
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cout<<setw(9)<<a<<
        setw(10)<<setprecision(1)<<fixed<<a<<
            setw(10)<<setprecision(2)<<fixed<<a<<endl;
//----------------------------------------------------------------------------------------------------
    cout<<setw(9)<<setprecision(0)<<b<<
        setw(10)<<setprecision(1)<<fixed<<b<<
            setw(10)<<setprecision(2)<<fixed<<b<<endl;
//----------------------------------------------------------------------------------------------------
    cout<<setw(9)<<setprecision(0)<<c<<
        setw(10)<<setprecision(1)<<fixed<<c<<
            setw(10)<<setprecision(2)<<fixed<<c<<endl;
//----------------------------------------------------------------------------------------------------      
    cout<<setw(9)<<setprecision(0)<<d<<
        setw(10)<<setprecision(1)<<fixed<<d<<
            setw(10)<<setprecision(2)<<fixed<<d;
//----------------------------------------------------------------------------------------------------
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}