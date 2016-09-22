/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 12:22 PM
 */
//System Libraries 
#include <cstdlib>
#include <iostream>
using namespace std;
//Global Constants

//Function Prototypes

//Execution Start Here

int main(int argc, char** argv) {
    //variables
int popsize=0;
    int pct=0;
    int days=0;
    float total=0;
    
    do{
    cout<<"Enter in the size of your population"<<endl;
    cin>>popsize;
    }
    while(popsize<2);
    do{
    cout<<"Enter in the average percent of growth"<<endl;
    cin>>pct;
    }
    while(pct<0);
    do{
    cout<<"Enter in the number of days they will grow for "<<endl;
    cin>>days;
    }
    while(days<1);
    total=popsize;
    for(int i=0;i<days;i++){
        //output for day i+1
        cout<<"Day "<<i+1<<":    Population: "<<total<<endl;
        //calculation for next day(i+2)
        total+=total*pct*1e-2;
    }
    //exit
    return 0;
}

