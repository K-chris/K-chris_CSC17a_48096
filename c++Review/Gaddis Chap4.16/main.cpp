/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 5:24 PM
 */
//System Libraries 
#include <cstdlib>
#include <iostream>
using namespace std;
//Global Constants

//Function Prototypes

//Execution Start Here

int main(int argc, char** argv){
    string runr[3];
    float runs[3];

    for(int i=0;i<3;i++){
        cout<<"enter in name for runner "<<i+1<<":"<<endl;
        cin>>runr[i];
        cout<<"enter in the time for runner"<<i+1<<":"<<endl;
        cin>>runs[i];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            if(runs[i]>runs[i+1]){
                float temp=runs[i];
                runs[i]=runs[i+1];
                runs[i+1]=temp;
                string tempstr=runr[i];
                runr[i]=runr[i+1];
                runr[i+1]=temp;
            }
    }
    for(int i=0;i<3;i++){
        cout<<i+1<<": Time:"<<runs[i]<<" Name:"<<runr[i]<<endl;
    }
    //exit
    return 0;
}

