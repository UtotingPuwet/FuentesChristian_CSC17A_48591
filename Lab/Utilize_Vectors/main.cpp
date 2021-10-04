/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on September 25th, 2021, 11:46 PM
 * Purpose:  Utilize vectors
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prntVec(vector<int> ,int,int);
void prntVec(vector<vector <int> >,int,int);
void fillVec(vector<int> &,int,int,int);
void fillVec(vector<vector<int> > &,int,int);
void fillVec(vector<vector <int> >&,vector <int> &,int,int);
void fillVec(vector<vector <int> >&,vector <int> &,int,int,int);
void swap(int &,int &);
void smlLst(vector <int> &,int,int);
void mrkSort(vector <int> &,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays
    int colsize=3;//The column size for a 2 dimensional Array
    vector <int> avector;
    vector <int> bvector;
    vector <int> cvector;
    vector <vector <int> > table;
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    fillVec(avector,rowsize,highRng,lowRng);
    fillVec(bvector,rowsize,highRng/10,lowRng/10);
    fillVec(cvector,rowsize,highRng/100,lowRng/100);
    
    //Sort the array the for all positions
    mrkSort(avector,rowsize);
    mrkSort(bvector,rowsize);
    mrkSort(cvector,rowsize);
    
    //Fill the 2-D array
    fillVec(table,rowsize,colsize);
    fillVec(table,avector,rowsize,0);
    fillVec(table,bvector,rowsize,1);
    fillVec(table,cvector,rowsize,2);
    
    //Print the values in the array
    prntVec(avector,rowsize,perLine);
    prntVec(bvector,rowsize,perLine);
    prntVec(cvector,rowsize,perLine);
    prntVec(table,rowsize,colsize);

    //Exit
    return 0;
}

void fillVec(vector<vector <int> > &a,vector<int> &c,int rowSize,int wchCol){
    for(int row=0;row<rowSize;row++){
        a[row][wchCol]=c[row];
    }
}

void fillVec(vector<int> &a,int n,int hr,int lr){
    n=n<2?2:n;
    for(int indx=0;indx<n;indx++){
        int val=rand()%(hr-lr+1)+lr;
        a.push_back (val);
    }
}

void fillVec(vector<vector <int> > &a,int rows,int cols){
    //Allocate Memory for 2-D Array
    rows=rows<2?2:rows;
    cols=cols<2?2:cols;
    for(int row=0;row<rows;row++){
        vector<int>temp;
        for (int col = 0; col < cols; col++) {
            temp.push_back(0);
        }
        a.push_back(temp);
    }
}

void prntVec(vector <vector <int> > a,int rowsize,int colsize){
     cout<<endl<<"The Vector Values"<<endl;
    for(int row=0;row<rowsize;row++){
        for(int col=0;col<colsize;col++){
            cout<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}

void prntVec(vector <int> a,int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Vector Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(vector<int> &a,int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(vector <int> &a,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}