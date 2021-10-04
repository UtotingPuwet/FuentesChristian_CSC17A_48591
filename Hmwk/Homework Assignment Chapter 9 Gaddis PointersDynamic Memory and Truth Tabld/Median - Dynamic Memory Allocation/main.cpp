#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data/
void prntMed(float *);     //Print the median Array
void sort(int *, int);    //sort

int main(){
	//your code here
	int size;
	int *array = getData(size);
	prntDat(array,size);
    float *middle = median(array,size);
    prntMed(middle);
    
    
	delete []array;
	delete []middle;
	return 0;
}

int *getData(int &size) {
    cin>>size;
    int *a = new int [size];
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
    float *fArray = new float [nSize];      //float array
        for (int i = 2; i < nSize; i++) {
        fArray[i] = a[count];
        count++;
    }
    sort(a,size);
    if (size%2) {
        med = a[size/2];
    }
    else {
        med = (a[(size-1)/2]+a[size/2])/2.0f;
    }
    fArray[1] = med;
    fArray[0] = nSize;
    return fArray;
}

void sort(int *a, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void prntMed(float *a) {
    cout << a[0];
    cout << setprecision(2) << fixed;
    for (int i = 1; i < a[0]; i++) {
        cout << ' ' << a[i];
    }
}