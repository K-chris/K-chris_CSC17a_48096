/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author:Christopher Kooyman
 *
 * Created on September 21, 2016, 4:47 PM
 */
//System Libraries 
#include <string>
#include <iostream>
using namespace std;

//function prototypes
int binarySearch(char *[], int, string);
void sortArray(char *[], int);

//global constants
const int SIZE = 20;

//execution begins here
int main()
{
   char *name[] = {"Collins, Bill",  "Smith, Bart",  "Michalski, Joe", "Griffin, Jim",
	               "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
	               "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
	               "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   "Harrison, Rose",
                   "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth"};

	
    string search;
    int results;

    //Get a name to search for
    cout << "Enter the name you wish to search for: ";
    //cin >> search;
    getline(cin, search);

    //Sort the names
    sortArray(name, SIZE);



	//Sort the names
	sortArray(name, SIZE);

	//Search for the name
	results = binarySearch(name, SIZE, search);

	//If binarySearch returned -1, the name was not found
	if (results == -1)
		cout << "That name does not exist in the array.\n";
	else
	{
		cout << "Name " << search << " was found in element "
			<< results << " of the array.\n";
	}


   return 0;
}

void sortArray(char *string[], const int size)
{
   int pass, i;
   char *temp;

   for (pass=0; pass < size - 1; pass++) 
   {
      for (i=0; i<size - 1; i++) 
	  {
         if (strcmp(string[i], string[i+1]) > 0) 
		 {
            temp = string[i];
            string[i] = string[i+1];
            string[i+1] = temp;
         }
      }
   }
}

int binarySearch(char *word[], int size, string value)
{
	int first = 0,
		last = size - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (word[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (word[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}


