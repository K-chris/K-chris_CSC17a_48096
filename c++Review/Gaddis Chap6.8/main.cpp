/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 6:08 PM
 */
//System Libraries 
#include <cstdlib>
#include <iostream>
using namespace std;
//Global Constants
int coinToss();
//Function Prototypes

//Execution Start Here

int main(int argc, char** argv) {
srand(static_cast<unsigned int>(time(0)));
int numtoss=0;
cout<<"enter in the amount of coin tosses"<<endl;
cin>>numtoss;

for(int i=0;i<numtoss;i++){
    if(coinToss()==true){
        cout<<"Heads"<<endl;
    }
    else{
        cout<<"Tails"<<endl;
    }
}
    return 0;
}

int coinToss(){
    bool result=0;
    result=rand()%2;
    return result;
}