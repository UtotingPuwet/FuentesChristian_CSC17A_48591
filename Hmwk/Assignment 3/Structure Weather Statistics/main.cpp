#include <iostream>
#include <iomanip>

using namespace std;

struct Weather {
    string name;   //what month it is
    short totRain,  //total rainfall
          hiTemp,   //high temperature
          loTemp;   //low temperature
    int avTemp;   //average temperature
};
void getData (Weather [], int);

int main(){
    //Declare variables
    const int SIZE = 12;
    int   highest,
          lowest;
    float rain,
          avg;
    string loMonth,
           hiMonth;
    Weather months[SIZE];
    
    //Initialize variables
    avg = 0;
    rain = 0;
    
    //Gather Data
    getData(months,SIZE);
    
    //Initialize more variables
    highest = months[0].hiTemp;
    hiMonth = months[0].name;
    lowest = months[0].loTemp;
    loMonth = months[0].name;
    
    //Calculate
    for (int i = 0; i < SIZE; i++) {
        if (months[i].loTemp < lowest) {            //if month is lower than lowest then set lowest to that
            lowest = months[i].loTemp;
            loMonth = months[i].name;
        }
        else if (months[i].hiTemp > highest) {           //if month is higher than highest then set highest to that
            highest = months[i].hiTemp;
            hiMonth = months[i].name;
        }
        avg += months[i].avTemp;
        rain += months[i].totRain;
    }
    cout << "Average Rainfall " << setprecision(1) << fixed << rain/12 <<" inches/month\n";
    cout << "Lowest  Temperature " << loMonth << "  " << lowest << " Degrees Fahrenheit\n";
    cout << "Highest Temperature " << hiMonth << "  " << highest << " Degrees Fahrenheit\n";
    cout << "Average Temperature for the year " << setprecision(0) << fixed << avg/12 << " Degrees Fahrenheit\n";
	//your code here
	return 0;
}

void getData (Weather months[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cin>>months[i].name;
        cin>>months[i].totRain;
        cin>>months[i].loTemp;
        cin>>months[i].hiTemp;
        months[i].avTemp = (months[i].loTemp + months[i].hiTemp)/2;
    }
    
}


