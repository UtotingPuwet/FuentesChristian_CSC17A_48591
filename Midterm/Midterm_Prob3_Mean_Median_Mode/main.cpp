/* 
 * File:   main.cpp
 * Author: Christian Fuentes
 * Created on October 20, 2021 8:42 PM
 * Purpose:  
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats; 
    
    
    //Looking for frequency
    stats->modFreq = 1;                                 //max Frequency
    
    for (int i = 0; i < array->size; i++) {             //checking frequency
        int curFreq = 0;
        for (int j = 0; j < array->size; j++) {
            if (array->data[i] == array->data[j]) {     //checking array->data[i] and array->data[j]
                curFreq++;
            }
        }
        if (curFreq > stats->modFreq && curFreq > 1) {  //has to occur more than once because j starts at 0 and will count the element i is looking for
            stats->modFreq = curFreq;
        }
    }
    
    //Find number of modes
    int nModes = 0;
    if (stats->modFreq > 1) {                           //if not over 1 then we want program to print null
        for (int i = 0; i < array->size; i++) {
            int curFreq = 0;                            //check frequency again
            for (int j = 0;j < array->size; j++) {
                if (array->data[i] == array->data[j]) {
                    curFreq++;
                }
            }
            if (curFreq == stats->modFreq) {            //if curFreq == modFreq then that means we have another mode
                nModes++;
            }
            i+= curFreq-1;                              //make "i" skip over already scanned elements, subtract 1 because we go too far(assume sorted)
        }
    }
    
    
    //Allocate mode
    int count = 0;                                      //separate count for the mode->data array 
    stats->mode=new Array;
    stats->mode->size=nModes;
    if(nModes!=0)stats->mode->data=new int[nModes];     //allocating mode's array
    if (stats->modFreq > 1) {
        for (int i = 0; i < array->size; i++) {         //nothing new here, 3rd time using this for loop, read above if needed
            int curFreq = 0;
            for (int j = 0; j < array->size; j++) {
                if (array->data[i] == array->data[j]) {
                    curFreq++;
                }
            }
            if (curFreq == stats->modFreq) {
                stats->mode->data[count] = array->data[i];
                count++;
            }
            i += curFreq-1;
        }
        
    }
    
    //Median
    if (array->size % 2) {
        stats->median = array->data[array->size/2];                                         //just divide by 2 to find middle number.
    }
    else {
        stats->median = (array->data[(array->size-1)/2] + array->data[array->size/2])/2.0f; //getting the two numbers in the middle, adding then div by 2
    }
    
    //Average
    stats->avg = 0;
    for (int i = 0; i < array->size; i++) {
        stats->avg += array->data[i];
    }
    
    stats->avg /= array->size;
    
    return stats;
}