/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp1(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}

int read (char a[][COLMAX], int &rowDet) {
    int count = 0;
    int colDet = 0;
    for (int i = 0; i < 3; i++) {
        cin>>a[i];
    }
    for (int i = 0; i < rowDet; i++) {
        if (strlen(a[i]) > colDet) {
            colDet = strlen(a[i]);
        }
    }
    return colDet;
}

void print (const char a[][COLMAX], int rowIn, int colIn) {
    for (int i = 0; i < rowIn; i++) {
        cout << a[i] << '\n';
    }
}

int strcmp1 (char a[], char b[], const char replace[], const char with[]) {
    int size = strlen(a) > strlen(b) ? strlen(a) : strlen(b);               //determine largest size of string.
    char ascii[127];                                                        //create array of ascii characters all 0-127
    int string1 = 0;                                                        //going to use an integer and add the numerical value of each character in the a[].
    int string2 = 0;                                                        //going to use an integer and add the numberical value of each character in the b[].
    char count = 0;                                                         //count for ascii code fill in.
    for (int i = 0; i < 127; i++) {
        ascii[i] = count;
        count++;
    }
    
    for (int i = 0; i < strlen(replace); i++) {                             //
        char temp = replace[i];
        char temp2 = with[i];
        ascii[replace[i]] = with[i];
        ascii[with[i]] = replace[i];
    }
    for (int i = 0; i < 127; i++) {
        cout << ascii[i] << '\n';
    }
    exit (EXIT_FAILURE);
    for (int i = 0; i < size; i++) {
        char tempA = a[i];
        char tempB = b[i];
        string1 += ascii[static_cast<char>(tempA)];
        string2 += ascii[static_cast<char>(tempB)];
    }
    if (string1 == string2) {
        return 0;
    }
    else if (string1 > string2) {
        return 1;
    }
    else if (string2 > string1) {
        return -1;
    }
    else return 0;
}

void sort(char a[][COLMAX],int rowIn,int colIn,const char replace[],const char with[]) {
    char temp[rowIn][colIn];
    for (int i = 0; i < rowIn; i++) {
        for (int j = i+1; j < rowIn; j++) {
            if (strcmp1(a[j],a[i],replace,with) > 0) {
                strcpy (temp[0],a[i]);
                strcpy (a[i],a[j]);
                strcpy (a[j],temp[0]);
            }
        }
    }
}