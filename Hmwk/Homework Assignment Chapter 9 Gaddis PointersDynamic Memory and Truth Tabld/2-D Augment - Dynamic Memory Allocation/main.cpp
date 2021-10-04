#include <iostream>

using namespace std;

int **getData(int &,int &);//Get the Matrix Data

void printDat(const int * const *,int,int);//Print the Matrix

int **augment(const int * const *,int,int);//Augment the original array

void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory


int main(){
	//your code here
	int row, 
	    col;
	int **array = getData(row,col); 
	printDat(array,row,col);
	cout << '\n';
	array = augment(array,row + 1,col + 1);
	printDat(array,row + 1,col + 1);
    destroy(array,row + 1);
	
	
	return 0;
}

int **getData(int &row, int &col) {
    cin>>row;
    cin>>col;
    int **a = new int *[row];
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

void printDat(const int* const *a, int row, int col) {
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j];
            if (j != col-1) {
                cout << ' ';
            }
        }
        if (i != row-1) {
            cout << '\n';
        }
    }
}

int **augment(const int* const *a, int row, int col) {
    int **aug = new int *[row];
    for (int i = 0; i < row; i++) {
        aug[i] = new int [col];
        for (int j = 0; j < col; j++) {
            if (i == 0 || j ==0) {
                aug[i][j] = 0;
            }
            else {
                aug[i][j] = a[i-1][j-1];
            }
        }
    }
    return aug;
}

void destroy (int **a, int row) {
    for (int i = 0; i < row; i++) {
        delete []a [row];
    }
    delete []a;
}