#include <iostream>
#include <iomanip>

using namespace std;

struct Weather {
    string name;   //what month it is
    float totRain;  //total rainfall
    float   hiTemp,   //high temperature
          loTemp;   //low temperature
    float avTemp;   //average temperature
};

enum MnthNam : int {
    JANUARY = 0, FEBRUARY, MARCH, APRIL, MAY, JUNE
};

void getData (Weather []);
void print (float, float, float, float);
float calc (Weather [], float &, float &, float &);

int main(){
    Weather months[JUNE+1];
    float avg,
          rain,
          highest,
          lowest;
        
    avg = 0;
    
    getData(months);
    rain = calc(months, avg, highest, lowest);
    print(avg, rain, highest, lowest);
    //Declare variables
  
	return 0;
}

void getData (Weather months[]) {
    for (int index = JANUARY; index <= JUNE; index++) {
        cout << "Enter the total rainfall for the month:\n";
        cin>>months[index].totRain;
        cout << "Enter the high temp:\n";
        cin>>months[index].hiTemp;
        cout << "Enter the low temp:\n";
        cin>>months[index].loTemp;
        months[index].avTemp = (months[index].loTemp + months[index].hiTemp)/2;
    }
}

void print (float avg, float rain, float  highest, float lowest) {
    cout << setprecision(2) << fixed;
    cout << "Average monthly rainfall:" << rain << '\n';
    cout << setprecision(0) << fixed << "High Temp:" << highest << '\n';
    cout << setprecision(0) << fixed << "Low Temp:" << lowest << '\n';
    cout << setprecision(1) << fixed << "Average Temp:" << avg;
    
}

float calc (Weather months [], float &avg, float &highest, float &lowest) {
    float rain = 0;
    highest = months[0].hiTemp;
    lowest = months[0].loTemp;
    for (int i = JANUARY; i <= JUNE; i++) {
        if (months[i].loTemp < lowest) {            //if month is lower than lowest then set lowest to that
            lowest = months[i].loTemp;
        }
        else if (months[i].hiTemp > highest) {           //if month is higher than highest then set highest to that
            highest = months[i].hiTemp;
        }
        avg += months[i].avTemp;
        rain += months[i].totRain;
    }
    avg /= 6;
    return rain/6;
}