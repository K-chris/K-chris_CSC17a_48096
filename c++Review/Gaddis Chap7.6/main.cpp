/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 4:39 PM
 */
//System Libraries 
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
//global constants 
const int ROWS=3;

//execution of main
int main(int argc, char** argv) {
    fstream raindata;
    int cols=30;
    int wethr[ROWS][3]={0};
    char mondata[ROWS][cols];
    raindata.open("RainOrShine.txt");
    
    for(int i=0;i<3;++i){
        if(i==0){
            cout<<"June weather"<<endl;
        }
        if(i==1){
            cout<<"July weather"<<endl;
        }
        if(i==2){
            cout<<"August weather"<<endl;
        }
        for(int j=0;j<30;++j){
            raindata.get(mondata[i][j]);
            cout<<mondata[i][j]<<endl;
            if(mondata[i][j]=='R'){
                wethr[i][0]++;
            }
            else if(mondata[i][j]=='C'){
                wethr[i][1]++;
            }
            else if(mondata[i][j]=='S'){
                wethr[i][2]++;
            }
        }
    }
    cout<<"number of rainy days in june is "<<wethr[0][0]<<endl;
    cout<<"number of cloudy days in june is "<<wethr[0][1]<<endl;
    cout<<"number of sunny days in june is "<<wethr[0][2]<<endl<<endl;;
    
     cout<<"number of rainy days in july is "<<wethr[1][0]<<endl;
    cout<<"number of cloudy days in july is "<<wethr[1][1]<<endl;
    cout<<"number of sunny days in july is "<<wethr[1][2]<<endl<<endl;;
    
     cout<<"number of rainy days in August is "<<wethr[2][0]<<endl;
    cout<<"number of cloudy days in August is "<<wethr[2][1]<<endl;
    cout<<"number of sunny days in August is "<<wethr[2][2]<<endl<<endl;
    cout<<"the total number of rainy days is "<<wethr[0][0]+wethr[1][0]+wethr[2][0]<<endl;
    cout<<"the total number of cloudy days is "<<wethr[0][1]+wethr[1][1]+wethr[2][1]<<endl;
    cout<<"the total number of sunny days is "<<wethr[0][2]+wethr[1][2]+wethr[2][2]<<endl<<endl;
    raindata.close();
    return 0;
}

