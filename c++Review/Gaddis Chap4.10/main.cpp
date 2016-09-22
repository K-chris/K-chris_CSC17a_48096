/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 12:13 PM
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
    int month;
    int year;
    bool leap=false;
    //ask user for month with input value validation 
    do{
    cout<<"enter a month(1-12): ";
    cin>>month;
    }while(month<1||month>12);
    
    //ask user for year
    do{
    cout<<"enter a year: ";
    cin>>year;
    }while(year<0);
    //only execute if month is febuary
    if(month==2){
        //if year is div to 100 and 400 it is leap year
        if(year%100==0){
            if(year%400==0){
                leap=true;
            }
        }
        //or if the year is only div by 4 it is a leap year as well 
        else if(year%4==0){
            leap=true;
            }
    }
    //output how many days in the month there are
    switch(month){
    case 1:
        cout<<"31 days"<<endl;
        break;
    case 2:
        if(leap==true){
            cout<<"29 days"<<endl;
        }
        else{
            cout<<"28 days"<<endl;
        }
        break;
    case 3:
        cout<<"31 days"<<endl;
        break;
    case 4:
        cout<<"30 days"<<endl;
        break;
    case 5:
        cout<<"31 days"<<endl;
        break;
    case 6:
        cout<<"30 days"<<endl;
        break;
    case 7:
        cout<<"31 days"<<endl;
        break;
    case 8:
        cout<<"31 days"<<endl;
        break;
    case 9:
        cout<<"30 days"<<endl;
        break;
    case 10:
        cout<<"31 days"<<endl;
        break;
    case 11:
        cout<<"30 days"<<endl;
        break;
    case 12:
        cout<<"31 days"<<endl;
        break;
    }
    //exit program 
    return 0;

}

