/* 
 */

//System Libraries Here
#include <iostream>


using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary


//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    const int SIZE = 6;
    
    int a[SIZE] = {1,2,3,1,2,1};
    int freq, mSIZE, count, maxCount;
    mSIZE = 0;
    int *modeSet = new int(mSIZE);
    
    
    count = 0;
    freq = 0;
    mSIZE = 0;
    maxCount = 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = i+1; j < SIZE; j++) {
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            if (a[j] == a[i]) {
                count++;
                if (count > maxCount) {
                    maxCount = count;
                }
                mSIZE++;
            }
        }
    }
    cout << maxCount << '\n';
    
    
    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " ";
    }
    
    delete []modeSet;
    
    return 0;
}
