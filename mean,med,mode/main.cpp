/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 1:46 PM
 */
//System Libraries 
#include <iostream>
#include <cstdlib>

using namespace std;

//function prototypes
void bubble(int[],int);
void prnt(int[],int);
float mean(int[],int);
void median(int[], int);
int *mode(int*,int);

//execution of main
int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    int size=11;
    int array[size];

    for(int i=0;i<size;i++){
        array[i]=rand()%10+1;
        cout<<array[i]<<"   ";
    }
    cout<<endl;
    bubble(array, size);
    cout<<"mean = "<<mean(array,size)<<endl;
    bubble(array, size);
    median(array, size);
    return 0;
}

float mean(int array[],int size){
    float m=0;
    for(int i=0;i<size;i++){
        m+=array[i];
    }
    m/=size;
    return m;
}

void median(int array[],int size){
    float mid=0;
    int middle=size/2;
    if (size%2!=0) {
         mid=array[middle];
        cout<<"the median equals "<<mid<<endl;
    }
    else{
         mid=(array[middle]+array[middle-1]);
         mid/=2;
         cout<<"the median equals "<<mid<<endl;
        
    }
}
//bubble sort
void bubble(int array[],int size){
    for(int a=0;a<size;a++){
        for(int b=a; b<size;b++){
            if(array[a]>array[b]){
                array[a]=array[a]^array[b];
                array[b]=array[a]^array[b];
                array[a]=array[a]^array[b];
            }
        }
    }
    prnt(array,size);
}
//print the array
void prnt(int array[],int size){
    for(int count=0;count<size;count++){
        cout<<count+1<<".  "<<array[count]<<endl;
    }
}
int *mode(int*,int){
    
    return 0;
}
