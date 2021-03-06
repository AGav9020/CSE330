/*
Alannah Gavuzzi
CSE 330 Lab 04 - Sorted List Class

Implement a class named “SortedList” that represents a linked list that is sorted 
in nondecreasing order. Note that you cannot use any sort function in the implementation of this
class. First, download the “SortedList.h” file on Blackboard. This file utilizes a template, but in
the main program, we will specifically create an object of type SortedList<int> (in other words,
we will create an instance of a linked list of integers). After downloading the aforementioned
file, implement and add the following public functions to the SortedList class.

*/
#include "pch.h"
#include "SortedList.h"
#include <iostream>

using namespace std;

/*Create a main program. Inside the main program, 
perform the following steps/operations:


1. 
Create an object of type SortedList<int>.


2. 
Call “empty” and print out an appropriate message 
(either list is empty or not empty).


3. 
Call “insertItem” 15 times. After each insert, 
print out the list. You may choose which values to insert. 
However, please make sure that there are at least 8 unique values out
of the 15. Also, make sure there are at least two repeated values 
(e.g., insert “7” twice and insert “16” twice).


4. 
Call “empty” and print out an appropriate message 
(either list is empty or not empty).


5. 
Call “deleteItem” 5 times. After each delete, print out the list.
One of the values to be deleted should not be present in the list. 
You should print out an appropriate message if a given value 
is not in the list (e.g., “Error: Value 58 not found in list.”)
*/




int main()
{
	// 1
	SortedList<int> linkTest = SortedList<int>();

	// 2
	if (linkTest.empty() == true) {
		cout << "\nThe sorted list is empty.\n";
	}
	else {
		cout << "\nThe sorted list is not empty.\n";
	}

	// 3 
	linkTest.insertItem(1);
	cout << linkTest;
	linkTest.insertItem(7);
	cout << linkTest;
	linkTest.insertItem(2);
	cout << linkTest;
	linkTest.insertItem(5);
	cout << linkTest;
	linkTest.insertItem(4);
	cout << linkTest;
	linkTest.insertItem(1);
	cout << linkTest;
	linkTest.insertItem(2);
	cout << linkTest;
	linkTest.insertItem(8);
	cout << linkTest;
	linkTest.insertItem(0);
	cout << linkTest;
	linkTest.insertItem(9);
	cout << linkTest;
	linkTest.insertItem(-11);
	cout << linkTest;
	linkTest.insertItem(10);
	cout << linkTest;
	linkTest.insertItem(-12);
	cout << linkTest;
	linkTest.insertItem(13);
	cout << linkTest;
	linkTest.insertItem(15);
	cout << linkTest;
	linkTest.insertItem(14);
	cout << linkTest;

	// 4
	if (linkTest.empty() == true) {
		cout << "\nThe sorted list is empty.\n";
	}
	else {
		cout << "\nThe sorted list is not empty.\n";
	}


	// 5
	if (linkTest.deleteItem(1)) {
		cout << "Value 1 deleted.\n";
	}
	else {
		cout << "Value 1 not found.\n";
	}
	cout << linkTest;
	if (linkTest.deleteItem(1)) {
		cout << "Value 1 deleted.\n";
	}
	else {
		cout << "Value 1 not found.\n";
	}
	cout << linkTest;
	if (linkTest.deleteItem(1)) {
		cout << "Value 1 deleted.\n";
	}
	else {
		cout << "Value 1 not found.\n";
	}
	cout << linkTest;
	if (linkTest.deleteItem(15)) {
		cout << "Value 15 deleted.\n";
	}
	else {
		cout << "Value 15 not found.\n";
	}
	cout << linkTest;
	if (linkTest.deleteItem(-12)) {
		cout << "Value -12 deleted.\n";
	}
	else {
		cout << "Value -12 not found.\n";
	}
	cout << linkTest;

	// This is for the homework.
	cout << linkTest.sum();
	return 0;
}

