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
    //format output
    cout<<fixed<<setprecision(2)<<showpoint<<endl;
    //prompt user for input
    cout<<"enter in a number in degrees Celsius to convert to Fahrenheit "<<endl;
    cin>>cels;
    //calculation
    faher=18e-1*cels+32;
    //output results
    cout<<cels<<" Degrees Celsius = "<<faher<<" Degrees Fahrenheit"<<endl;
    return 0;
}

