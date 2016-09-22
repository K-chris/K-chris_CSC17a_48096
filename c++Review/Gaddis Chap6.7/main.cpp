/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 12:29 PM
 */
//System Libraries 
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Global Constants

//Function Prototypes
float celsius(int);
//execution of main
int main(int argc, char** argv) {
    float f;
    cout<<"| Fahrenheit  |  Celsius |"<<endl;
    cout<<"|------------------------|"<<endl;  
    cout<<fixed<<setprecision(2);
    for(int i=0;i<=20;i++){
        f=celsius(i);
        if(i<=9){
            cout<<"|      "<<i<<"      |  "<<f<<"  |"<<endl;
        }
        else if(i>=15){
            cout<<"|     "<<i<<"      |  "<<f<<"   |"<<endl;
        }
        else{
            cout<<"|     "<<i<<"      |  "<<f<<"  |"<<endl;
        }
    }
    return 0;
}

float celsius(int f){
    double c;
    c=5555.5556e-4;
    c*=(f-32);
    return c;
}