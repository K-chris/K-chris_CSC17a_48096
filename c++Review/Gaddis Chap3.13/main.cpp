/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 11:52 AM
 */
//System Libraries 
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Global Constants

//Function Prototypes

//Execution Start Here

int main(int argc, char** argv) {
    //not real constants rates always change!
    float YEN_PER_DOLLAR=101.58;
    float EUROS_PER_DOLLAR=0.90;
    float usd=0;
    cout<<"enter in how much USD you want to exchange for YEN and EURO's"<<endl;
    cin>>usd;
    cout<<fixed<<setprecision(2)<<showpoint<<endl;
    cout<<"USD: "<<usd<<endl<<"YEN: "<<usd*YEN_PER_DOLLAR<<endl<<"EURO's: "<<usd*EUROS_PER_DOLLAR<<endl;
    //exit
    return 0;
}

