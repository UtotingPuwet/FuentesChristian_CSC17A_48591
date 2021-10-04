#include <iostream>

using namespace std;

int *getData(int &);             //Return the array size and the array from the inputs

int *sumAry(const int *,int);//Return the array with successive sums

void prntAry(const int *,int);//Print the array

int main(){
	//your code here
	//Ask for size of array 
	int size;
	//Get Data for array 
	int *array = getData(size);
	//Print array 
	prntAry(array,size);
	cout << '\n';
	//sum
	array = sumAry(array,size);
	//Print
	prntAry(array,size);
	
	delete []array;
	
	return 0;
}

int *getData (int &size) {
    cin>>size;
    int *a = new int (size);
    for(int i = 0; i < size; i++) {
        cin>>a[i];
    } 
    return a;
}
int *sumAry(const int *array, int size) {
    int *a = new int [size];
    a[0] = array[0];
    for (int i = 1; i < size; i++) {
        a[i] = array[i] + a[i-1];
    }
    return a;
}

void prntAry (const int *a, int size) {
    cout << a[0];
    for (int i = 1; i < size; i++) {
        cout << ' ' << a[i];
    }
}