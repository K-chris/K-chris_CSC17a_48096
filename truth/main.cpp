/* 
 * File:   main.cpp
 * Purpose:  truth table
 * Christopher Kooyman
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
//Function Prototypes
//Execution Start Here
int main(int argc, char** argv) {
    //Declare variables
    bool x=true;
    bool y=true;
    //Output the headings
    cout<<"X Y !X !Y X||Y X&&Y ";
    cout<<"X^Y X^Y^X X^Y^Y !(X&&Y) ";
    cout<<"!x&&!y !(X||Y) !X||!Y"<<endl;
    //Output the truth table for loop
    for(int i=0;i<4;i++){
        if(i==1)y=false;
        if(i==2)y=true, x=false;
        if(i==3)y=false;
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"   ";
    cout<<(x||y?'T':'F')<<"    ";
    cout<<(x&&y?'T':'F')<<"   ";
    cout<<(x^y?'T':'F')<<"    ";
    cout<<(x^y^x?'T':'F')<<"     ";
    cout<<(x^y^y?'T':'F')<<"      ";
    cout<<(!(x&&y)?'T':'F')<<"      ";
    cout<<(!x&&!y?'T':'F')<<"       ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F');
    cout<<endl;
    }
    //Exit stage right
    return 0;
}

