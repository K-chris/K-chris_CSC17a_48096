/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 26, 2016, 11:19 AM
 */
//System Libraries 
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Global Constants
//Function Prototypes
void prntarr(int,int*);
int *dynarry(int); //prob 1
void chap9prob1(); //prob 1
void chap9prob3();//prob 2 
void sortarr(int,int*);//prob2
int avgTest(int, int*);//prob2
//prob 3
void chap9prob6();
void arrSelectSort(int *, int);
void showArray(const int *, int);
void showArrPtr(int *, int);
//end of prob 3
void chap9prob8();
void mode(int, int*);

void chap9prob9(); //prob4
float median(int , int *);


//Execution Start Here
int main(int argc, char** argv) {
    //set randnumseed
    srand( time(0) );
    int choice=0;
    do{
    cout<<endl; 
    cout<<"Assignment 1 homework"<<endl;
    cout<<"1. Chap9 Problem 1 "<<endl;
    cout<<"2. Chap9 Problem 3 "<<endl;
    cout<<"3. Chap9 Problem 6 "<<endl;
    cout<<"4. Chap9 Problem 8 "<<endl;
    cout<<"5. Chap9 Problem 9 "<<endl;
    cout<<"enter in the program number you want to run anything else will exit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            chap9prob1();
            break;
        case 2: 
            chap9prob3();
            break;
        case 3:
            chap9prob6();
            break;
        case 4:
             chap9prob8();
             break;
        case 5:
            chap9prob9();
            break;
    }
    }while(choice>0&&choice<10);             
}

void chap9prob1(){  
    //variables
    int n=0;
    int *arr=nullptr;
    //ask user foe size(n) of array
    cout<<"enter in the number of intager values you want store"<<endl;
    cin>>n;
    arr=dynarry(n);
    //output array
    prntarr(n,arr);
    
    //unallocate memory 
    delete [] arr;
    arr=0;
    //exit
}
int *dynarry(int nEle){
    //
    //Chap 9 Problem 1
    //
    int *arr =nullptr;
    
    if(nEle<1)return nullptr;
    arr = new int[nEle];
    for(int i=0;i<nEle;i++){
        arr[i]=rand()%10;
    }
    return arr;
}

void chap9prob3(){
    int n;
    int *arr=nullptr;
    cout<<"enter in the number of student test scores needed to be entered"<<endl;
    cin>>n;
    arr = new int[n];
    for(int i=0;i<n;i++){
        *(arr+i)=rand()%100+1;
    }
    cout<<"unsorted array"<<endl;
    prntarr(n,arr);
    sortarr(n,arr);
    cout<<"sorted array"<<endl;
    prntarr(n,arr);
    //unallocate memory
    cout<<"lowest score dropped"<<endl;
    cout<<"average tests score :"<<avgTest(n,arr)<<endl;
    
    delete [] arr;
    arr=0;
    //exit
}

void sortarr(int nEle, int *arr){
    bool swap=false;
    do{
    swap=false;    
    for(int i=0;i<nEle-1;i++){
         if(*(arr+i)>*(arr+i+1)){
             *(arr+i)= *(arr+i)^*(arr+i+1);
             *(arr+i+1)= *(arr+i)^*(arr+i+1);
             *(arr+i)= *(arr+i)^*(arr+i+1);
             swap=true;
         }   
        }
    }while(swap==true);
    cout<<endl;
}

void prntarr(int nEle, int *arr){
    cout<<endl;
    for(int i=0;i<nEle;i++){
        cout<<*(arr+i)<<"   ";
        if((i+1)%10==0)cout<<endl;
}
}
int avgTest(int nEle, int *arr){
    int total=0;
    for(int i=nEle-1;i>0;i--){
        total+=*(arr+i);
    }
    total/=(nEle-1);
    return total;
}



void chap9prob6(){
   int NUM_DONATIONS = 10;  // Number of donations
   int *donations=nullptr;
   int *arrPtr =nullptr;
   int donate=0;
   // An array containing the donation amounts.
   do{
   cout<<"enter in the amount of donations"<<endl;
   cin>>NUM_DONATIONS;
   }while(NUM_DONATIONS<0);
   
   donations = new int[NUM_DONATIONS];
   
   // An array of pointers to int.
   arrPtr =new int[NUM_DONATIONS];
   // Each element of arrPtr is a pointer to int. Make each
   // element point to an element in the donations array.
   for (int count = 0; count < NUM_DONATIONS; count++){
       do{
       cout<<"enter in donation "<<count+1<<endl;
   cin>>donate;
       }while(donate<1);
        *(arrPtr+count)=donate;
        *(donations+count)=donate;
   }
   // Sort the elements of the array of pointers.
   arrSelectSort(arrPtr, NUM_DONATIONS);

   // Display the donations using the array of pointers. This
   // will display them in sorted order.
   cout << "The donations, sorted in ascending order are: \n";
   showArrPtr(arrPtr, NUM_DONATIONS);

   // Display the donations in their original order.
   cout << "The donations, in their original order are: \n";
   showArray(donations, NUM_DONATIONS);
   //realllocate memory
   delete [] donations;
   delete [] arrPtr;
   donations=0;
   arrPtr=0;
   
}

//****************************************************************
// Definition of function arrSelectSort.                         *
// This function performs an ascending order selection sort on   *
// arr, which is an array of pointers. Each element of array     *
// points to an element of a second array. After the sort,       *
// arr will point to the elements of the second array in         *
// ascending order.                                              *
//****************************************************************

void arrSelectSort(int *arr, int size){
   int startScan, minIndex;
   int *minElem;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      *minElem = *(arr+startScan);
      for(int index = startScan + 1; index < size; index++)
      {
         if (*(arr+index) < *minElem)
         {
            *minElem = *(arr+index);
            minIndex = index;
         }
      }
      *(arr+minIndex) = *(arr+startScan);
      *(arr+startScan) = *minElem;
   }
}

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of arr. size is the    *
// number of elements.                                        *
//*************************************************************

void showArray(const int *arr, int size){
   for (int count = 0; count < size; count++)
      cout << arr[count] << " ";
   cout << endl;
}

//**************************************************************
// Definition of function showArrPtr.                          *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements.                     *
//**************************************************************

void showArrPtr(int *arr, int size){
   for (int count = 0; count < size; count++)
      cout << *(arr+count) << " ";
   cout << endl;
}
void chap9prob8(){
    int n=10;
    int *arr=nullptr;
    arr=new int[n];
    for(int i=0;i<n;i++){
        *(arr+i)=rand()%10;
    }
    mode(n,arr);
    delete [] arr;
    arr=0;
    
}

void mode(int nEle, int *arr){
    int freq=0;
    int tempfreq=1;
    int nMode=0;
    int *modes=nullptr;
    sortarr(nEle,arr);
    cout<<"sorted array"<<endl;
    prntarr(nEle,arr);
    for(int i=0;i<nEle-1;i++){
        if(*(arr+i)==*(arr+i+1)){
            tempfreq++;    
        }
        else{
            if(tempfreq>freq) freq=tempfreq;
            tempfreq=1;
        }
    }
    for(int i=0;i<nEle-1;i++){
        int 
    }
    cout<<"the feequency is "<<freq<<endl;
}


void chap9prob9(){
    int n=rand()%100+1;
    int *arr=nullptr;
    arr=new int[n];
    for(int i=0;i<n;i++){
        *(arr+i)=rand()%100+1;
    }
    //unsorted arr
    printf("there are %d elements in the array \n",n);
    cout<<"showing unsorted array"<<endl;
    prntarr(n,arr);
    sortarr(n,arr);
    cout<<"showing sorted array"<<endl;
    prntarr(n,arr);
    cout<<"the median is "<<median(n,arr);
    delete [] arr;
    arr=0;
}
            
float median(int nEle, int *arr){
    float med=0;
    if(nEle%2==0){
        nEle/=2;
        med=*(arr+nEle-1)+*(arr+nEle);
        med/=2;
            cout<<"median in function "<<med<<endl;
    }
    else{
        nEle/=2;
        med=*(arr+nEle);
    }

    return med;
}
