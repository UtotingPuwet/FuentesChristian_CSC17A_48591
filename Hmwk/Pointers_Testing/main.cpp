#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data/
void prntMed(float *,int);     //Print the median Array

int main(){
	//your code here
	int size;
	cin>>size;
	int *array = new int (size);
	array = getData(size);
	prntDat(array,size);
	float *med = new float(size + 2);
	med = median(array,size);
	prntMed(med,size+2);
	
        
        delete  []array;
        delete  []med;
        
	return 0;
}

int *getData(int &size) {
    int val;                //just input from file
    int count = 0;
    int *a = new int (size);
    for (int i = 0; i < size; i++) {
        cin>>a[i];
    }
    return a;
}

void prntDat(int *a, int size) {
    cout << a[0];
    for (int i = 1; i < size; i++) {
        cout << ' ' << a[i];
    }
    cout << endl;
}

float *median (int *a, int size) {
    int count = 0;
    float med;
    int nSize  = size + 2;                  //new size because we need to add 2.
    float* fArray = new float (nSize);      //float array
    if (size%2 == 0) {
        float b,c;
        b  = a[size/2];
        c = a[(size/2) - 1];
        med = (b+c)/2;
    }
    else {
        med = a[size/2] + 1;
    }
    fArray[1] = med;
    fArray[0] = nSize;
    for (int i = 2; i < nSize; i++) {
        fArray[i] = a[count];
        count++;
    }
    return fArray;
}

void prntMed(float *a, int size) {
    cout << a[0];
    cout << setprecision(2) << fixed;
    for (int i = 1; i < size; i++) {
        cout << ' ' << a[i];
    }
}