/*
 * File:   main.cpp
 * Author: christopherkooyman
 * Created on September 14, 2016, 12:25 PM
 */
//System Constants 
//#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
//Function Prototypes
//Execution Start Here

int main(int argc, char** argv) {
    //variables
    float cels=0;
    float faher=0;
    cout<<setprecision(3)<<showpoint<<endl;
    cout<<"enter in a number in degrees Celsius to convert to Fahrenheit "<<endl;
    cin>>cels;
    
    faher=((9/5)*cels)+32;
    
    cout<<cels<<" Degrees Celsius = "<<faher<<" Degrees Fahrenheit"<<endl;
    //exit 
    return 0;
}

