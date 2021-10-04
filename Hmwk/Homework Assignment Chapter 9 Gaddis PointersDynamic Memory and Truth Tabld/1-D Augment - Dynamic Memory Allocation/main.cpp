#include <iostream>

using namespace std;

int *getData(int &);//Read the array

int *augment(const int *,int);//Augment and copy the original array

void prntAry(const int *,int);//Print the array


int main(){
    int size;
    int *array = getData(size);
    prntAry(array,size);
    cout << endl;
    array = augment(array,size+1);
    prntAry(array,size+1);
    
    delete []array;
	//your code here
	return 0;
}

int *getData (int &size) {
    cin>>size;
    int *a = new int [size];
    for (int i = 0; i < size; i++) {
        cin>>a[i];
    }
    return a;
}

int *augment (const int*a, int size) {
    int *aug = new int [size];
    aug[0] = 0;
    for (int i = 1; i < size; i++) {
        aug[i] = a[i-1];
    }
    return aug;
}

void prntAry (const int*a, int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i];
        if (i != size-1) {
            cout << ' ';
        }
    }
}