/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 28, 2016, 1:01 PM
 * Purpose:  Shortest Sort using array structure
 * ver 1 no sort
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number generator Library
#include <ctime>     //Time Library
using namespace std;
//User Libraries
#include "Array.h"
//Global Constants

//Function Prototypes

Array fillAry(int);
void prntAry(Array *, int);
void mrkSort(int [],int);
void destroy(Array *);

//Execution Begin Here!
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int perLine=10;
    const int SIZE=100;
    
    //Input data
    Array *array=fillAry(SIZE);
    
    //Display initialization
    prntAry(array,perLine);
    
    //Process -> Map the input data to the output
    //mrkSort(array,SIZE);
    
    //Display/Output solution here
    prntAry(array,perLine);

    //destroy array struct and its contants
    destroy(Array *array);
    //Exit stage right!
    return 0;
}

void mrkSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void prntAry(Array *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n){
    Array *a=new Array;
    a->size=n;
    a->data=new int[n];
    for(int i=0;i<n;i++){
        a->data[i]=rand()%90+10;//Random 2 digit numbers
    }
}

void destroy(Array *a){
    delete []a->data;
    delete a;
}