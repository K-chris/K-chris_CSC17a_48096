/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 4:56 PM
 */
//System Libraries 
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Global Constants
const float PI=31415e-4;
//Function Prototypes

//Execution Start Here

int main(int argc, char** argv) {
    
    int menu=0;
    float area=0;
    float length=0,width=0,height=0,base=0,radius=0;
    bool exit=false;
    cout<<fixed<<setprecision(2);
    do{
    do{
        
    cout<<"1. Calculate the Area of a Circle"<<endl;
    cout<<"2. Calculate the Area of a Rectangle"<<endl;       
    cout<<"3. Calculate the Area of a Triangle"<<endl;
    cout<<"4. Quit"<<endl;
    cin>>menu;
    }while(menu<1||menu>4);
    switch (menu){
        case 1:
            cout<<"enter in the radius of the circle"<<endl;
            cin>>radius;
            area=PI*(radius*radius);
            cout<<"area of the circle= "<<area<<endl;
            break;
        case 2:
            cout<<"enter in the length of the rectangle"<<endl;
            cin>>length;
            cout<<"enter in the width of the rectangle"<<endl;
            cin>>width;
            area=length*width;
            cout<<"area of the rectangle= "<<area<<endl;
            break;
        case 3:
            cout<<"enter in the base of the triangle"<<endl;
            cin>>base;
            cout<<"enter in the height of the triangle"<<endl;
            cin>>height;
            area=base*height*5e-1;
            cout<<"area of the triangle= "<<area<<endl;
            break;
        case 4:
            exit=true;
            break;  
    }
    }while(exit!=true);
    //exit
    return 0;
}

