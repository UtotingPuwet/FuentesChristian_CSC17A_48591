#include <iostream>

using namespace std;

int **getData(int &,int &);        //Return the 2-D array and its size.

void prntDat(const int* const *,int,int);//Print the 2-D Array

void destroy(int **,int,int);       //Deallocate memory

int sum(const int * const *, int,int);    //Return the Sum

int main(){
	//your code here
	int row,col;
	int **array = getData(row,col);
	prntDat(array,row,col);
	cout << sum(array,row,col);
	destroy(array,row,col);
	return 0;
}
int **getData(int &row, int &col) {
    cin>>row;
    cin>>col;
    int **a = new int *[row];             //creating a 2d dyanmic array by creating a row of pointers that point to more pointers [row] is to take in how many rows there are.
    for (int i = 0; i < row; i++) {
        a[i] = new int [col];           //this is creating a new row of columns, the [col] is so that it knows how many columns is in the row.
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin>>a[i][j];
        }
    }
    return a;
}

void prntDat (const int* const *a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j];
            if (j != col-1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int sum (const int * const *a, int row, int col) {
    int total = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            total += a[i][j];
        }
    }
    return total;
}

void destroy(int **a, int row, int col) {
    for (int i = 0; i < row; i++) {
        delete [] a[i];
    }
    delete []a;
}