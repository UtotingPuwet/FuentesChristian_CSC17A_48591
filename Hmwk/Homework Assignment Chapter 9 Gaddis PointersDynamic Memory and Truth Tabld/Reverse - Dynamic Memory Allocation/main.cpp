#include <iostream>

int *getData(int &);               //Fill the array
int *sort(int *,int);         //Sort smallest to largest
int *reverse(int *,int);  //Sort in reverse order
void prntData(int *,int); //Print the array
void destroy (int *);

using namespace std;

int main(){
    //Get the size of the array
    int size;
    //Create new dynamic array
    int *array = getData(size);
    //Sort the array
    array = sort(array,size);
    //Print the array
    prntData(array,size);
    cout<< '\n';
    //Reverse the array and print
    array = reverse(array,size);
    prntData(array,size);
    
    delete []array;
	//your code here
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

void prntData (int *a, int size) {      //normal print
    cout << a[0];
    for (int i = 1; i < size; i++) {
        cout << ' ' << a[i];
    }
}

int *sort (int *a, int size) {
    for (int i = 1; i < size; i++) {            //bubble sort, we use i=1 instead of i=0 because we dont want to go too far
        for (int j = 0; j <size-1; j++) {       //size-1 
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return a;
}

int *reverse (int *a, int size) {
    int count = size-1;
    for (int i = 0; i < size/2; i++) {          //half the array size because if not the array just resorts itself
        int temp = a[i];
        a[i] = a[count];
        a[count] = temp;
        count--;
    }
    return a;
}