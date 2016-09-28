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


void chap9prob8(); //prob4
void mode(int, int*);

void chap9prob9(); //prob5
float median(int , int *);

void chap9prob10(); //prob6
int *revarr(int , int *);//prob6

void chap9prob11();//prob 7
int *exparr(int, int *);

void chap9prob12();//prob 7
int *arrshift(int, int *);
float mean(int,int*);
void meanmedmode();
//Execution Start Here
int main(int argc, char** argv) {
    //set randnumseed
    srand( time(0) );
    int choice=0;
    do{
    cout<<endl; 
    cout<<"Assignment 1 homework"<<endl;
    cout<<"1. Chap9 Problem 1 "<<endl;
    cout<<"2. Chap9 Problem 2/3 "<<endl;
    cout<<"3. Chap9 Problem 6 "<<endl;
    cout<<"4. Chap9 Problem 8 "<<endl;
    cout<<"5. Chap9 Problem 9 "<<endl;
    cout<<"6. Chap9 Problem 10 "<<endl;
    cout<<"7. Chap9 Problem 11 "<<endl;
    cout<<"8. Chap9 Problem 12 "<<endl;
    cout<<"9. Mean,Median,Mode"<<endl;
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
        case 6:
            chap9prob10();
            break;
        case 7:
            chap9prob11();
            break;
        case 8:
            chap9prob12();
            break;
        case 9:
            meanmedmode();
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
}

void prntarr(int nEle, int *arr){
    cout<<endl;
    for(int i=0;i<nEle;i++){
        cout<<*(arr+i)<<"   ";
        if((i+1)%10==0)cout<<endl;
}
    cout<<endl;
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
    int n=100;
    int *arr=nullptr;
    arr=new int[n];
    for(int i=0;i<n;i++){
        *(arr+i)=rand()%100;
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
    //learn the frequency
    for(int i=0;i<nEle-1;i++){
        if(*(arr+i)==*(arr+i+1)){
            tempfreq++;    
        }
        else{
            if(tempfreq>freq) freq=tempfreq;
            tempfreq=1;
        }
        
    }
    if(freq>1){
    //counter for number of modes in the frequency;
    tempfreq=1;
    for(int i=0;i<nEle;i++){
        if(*(arr+i)==*(arr+i+1)){
            tempfreq++;
        }
        else{
            if(tempfreq==freq)nMode++;
            tempfreq=1;
        }
    }
    
    int *modarr=nullptr;
    modarr = new int[nMode+2];
    *(modarr+0)=freq;
    *(modarr+1)=nMode;
    tempfreq=1;
    int j=0;
    for(int i=0;i<nEle;i++){
        if(*(arr+i)==*(arr+i+1)){
            tempfreq++;
        }
        else{
            if(tempfreq==freq){
                *(modarr+j+2)=*(arr+i-1);
                j++;
            }
            tempfreq=1;
        }
    }
    for(int i=0;i<nMode+2;i++){
        if(i==0) cout<<"the frequency is "<<*(modarr+i)<<endl;
        else if(i==1) cout<<"the number of modes is "<<*(modarr+i)<<endl<<"{";
        else cout<<"  "<<*(modarr+i);
     
    }
    cout<<" }"<<endl;
    delete [] modarr;
    modarr =0;
    }
    else{
        cout<<"there is no mode"<<endl;
        cout<<"the frequency is "<<freq<<endl;

    }
}


void chap9prob9(){
    int n=rand()%100+1;
    int *arr=nullptr;
    arr=new int[n];
    for(int i=0;i<n;i++){
        *(arr+i)=rand()%100;
    }
    //unsorted arr
    printf("there are %d elements in the array \n",n);
    //cout<<"showing unsorted array"<<endl;
    //prntarr(n,arr);
    //sortarr(n,arr);
    //cout<<"showing sorted array"<<endl;
    prntarr(n,arr);
    cout<<"the median is "<<median(n,arr);
    delete [] arr;
    arr=0;
}
            
float median(int nEle, int *arr){
    sortarr(nEle,arr);
    float med=0;
    if(nEle%2==0){
        nEle/=2;
        med=*(arr+nEle-1)+*(arr+nEle);
        med/=2;
    }
    else{
        nEle/=2;
        med=*(arr+nEle);
    }

    return med;
}

void chap9prob10(){
    int n=10;
    int *arr=nullptr;
    arr=new int[n];
    for(int i=0;i<n;i++){
        *(arr+i)=rand()%100;
    }
    cout<<"normal array"<<endl;
    prntarr(n,arr);
    int *rev=revarr(n,arr);
    cout<<"reversed array"<<endl;
    prntarr(n,rev);
    delete [] rev;
    rev=0;
    delete [] arr;
    arr= 0;
}

int *revarr(int nEle, int *arr){
    int *revarr=nullptr;
    revarr= new int[nEle];
    for(int i=0;i<nEle;i++){
        *(revarr+i)=*(arr+(nEle-1)-i);
    }
    return revarr;
}

void chap9prob11(){
    int n=10;
    int *arr=nullptr;
    arr=new int[n];
    for(int i=0;i<n;i++){
        *(arr+i)=rand()%100;
    }
    cout<<"normal array"<<endl;
    prntarr(n,arr);
    int *dbl=exparr(n,arr);
    cout<<"double size array "<<endl;
    prntarr(n*2,dbl);
    delete [] dbl;
    dbl=0;
    delete [] arr;
    arr= 0;
}

int *exparr(int nEle, int *arr){
    int *dblarr=nullptr;
    dblarr= new int[nEle*2];
    for(int i=0;i<nEle*2;i++){
        if(i<nEle){
        *(dblarr+i)=*(arr+i);
        }
        else{
            *(dblarr+i)=0;
        }
    }
    return dblarr;
}

void chap9prob12(){
    int n=10;
    int *arr=nullptr;
    arr=new int[n];
    for(int i=0;i<n;i++){
        *(arr+i)=rand()%100;
    }
    cout<<"normal array"<<endl;
    prntarr(n,arr);
    int *shift=arrshift(n,arr);
    cout<<"shifted array "<<endl;
    prntarr(n+1,shift);
    delete [] shift;
    shift=0;
    delete [] arr;
    arr= 0;
}

int *arrshift(int nEle, int *arr){
    int *arrshift=nullptr;
    arrshift= new int[nEle+1];
    for(int i=0;i<nEle;i++){
        *(arrshift+i+1)=*(arr+i);
    }
    return arrshift;
}

float mean(int nEle, int *arr){
    int mean=0;
    for(int i=0;i<nEle;i++){
        mean+=*(arr+i);
    }
    return mean/nEle;
}
void meanmedmode(){
    int n=100;
    int *arr=nullptr;
    arr = new int[n];
    for(int i=0;i<n;i++){
        *(arr+i)=rand()%100;
    }
    prntarr(n,arr);
    cout<<"the mean is: "<<mean(n,arr)<<endl;
    cout<<"the median is: "<<median(n,arr)<<endl;
    mode(n,arr);
}