/*
ALANNAH GAVUZZI
CSE 330 
Lab 02 - Sorted Array Class
*/



/*
Your code should consist of three files: 
1) class header file, 
2) class implementation file, and 
3)file containing the main function.


Inside the main function, perform the following steps/operations:
1. Create an object of type “SortedArray” with initial capacity = 10.

2. Call “isEmpty” and print out an appropriate message (either array is empty or not
empty).

3. Call “insertVal” 15 times. After each insert, print out the array. You may choose which
values to insert. However, please make sure that there are at least 8 unique values out
of the 15. Also, make sure there is at least two repeated values (e.g., insert “7” twice
and insert “16” twice).

4. Call “isEmpty” and print out an appropriate message (either array is empty or not
empty).

5. Call “deleteVal” 5 times. After each delete, print out the array. One of the values to be
deleted should not be present in the array. You should print out an appropriate message
if a given value is not in the array (e.g., “Error: Value 58 not found in array.”).
*/

//BONUS
/*
Actually, since one of our data members is a pointer to dynamically allocated memory, you
should implement all Big Three functions (or in C++11, the Big Five functions). Note that you
already implemented one of the Big Three (which is the destructor). For this bonus activity,
implement the copy constructor and copy assignment operator shown below.

SortedArray(const SortedArray & sA);
This is a copy constructor.

const SortedArray & operator=(const SortedArray & sA)
This is a copy assignment operator.
*/

#include "pch.h"
#include "Sorted_Array.h"
#include <iostream>

using namespace std;

int main() {



	// 1. Create an object of type “SortedArray” 
	// with initial capacity = 10.
	Sorted_Array arrTest = Sorted_Array(10);


	// 2. Call “isEmpty” and print out an appropriate message 
	// (either array is empty or not empty)

	if (arrTest.isEmpty() == true) {
		cout << "\nThe sorted array is empty.\n";
	}
	else {
		cout << "\nThe sorted array is not empty.\n";
	}



	// 3. Call “insertVal” 15 times. 
	// After each insert, print out the array.
	// You may choose which values to insert.
	// However, please make sure that there are 
	// at least 8 unique values out of the 15. 
	// Also, make sure there is at least two repeated values
	// (e.g., insert “7” twice and insert “16” twice).

	arrTest.insertVal(1);
	cout << arrTest;
	arrTest.insertVal(7);
	cout << arrTest;
	arrTest.insertVal(2);
	cout << arrTest;
	arrTest.insertVal(5);
	cout << arrTest;
	arrTest.insertVal(4);
	cout << arrTest;
	arrTest.insertVal(1);
	cout << arrTest;
	arrTest.insertVal(2);
	cout << arrTest;
	arrTest.insertVal(8);
	cout << arrTest;
	arrTest.insertVal(0);
	cout << arrTest;
	arrTest.insertVal(9);
	cout << arrTest;
	arrTest.insertVal(-11);
	cout << arrTest;
	arrTest.insertVal(10);
	cout << arrTest;
	arrTest.insertVal(-12);
	cout << arrTest;
	arrTest.insertVal(13);
	cout << arrTest;
	arrTest.insertVal(15);
	cout << arrTest;
	arrTest.insertVal(14);
	cout << arrTest;

	// BONUS: COPY CONSTRUCTOR
	//Sorted_Array arrCopy = Sorted_Array(arrTest);

	


	// 4. Call “isEmpty” and print out an appropriate message 
	// (either array is empty or not empty).

	if (arrTest.isEmpty() == true) {
		cout << "\nThe sorted array is empty.\n";
	}
	else {
		cout << "\nThe sorted array is not empty.\n";
	}

	// 5. Call “deleteVal” 5 times.After each delete, print out the array.
	// One of the values to be deleted should not be present in the array.
	// You should print out an appropriate message if a given value
	// is NOT in the array
	// (e.g., “Error: Value 58 not found in array.”).
	
	cout << arrTest.numOfTimes(1);


	if (arrTest.deleteVal(1)) {
		cout << "Value 1 deleted.\n";
	}
	else {
		cout << "Value 1 not found.\n";
	}
	cout << arrTest;
	if (arrTest.deleteVal(1)) {
		cout << "Value 1 deleted.\n";
	}
	else {
		cout << "Value 1 not found.\n";
	}
	cout << arrTest;	
	if (arrTest.deleteVal(1)) {
		cout << "Value 1 deleted.\n";
	}
	else {
		cout << "Value 1 not found.\n";
	}
	cout << arrTest;
	if (arrTest.deleteVal(15)) {
		cout << "Value 15 deleted.\n";
	}
	else {
		cout << "Value 15 not found.\n";
	}
	cout << arrTest;	
	if (arrTest.deleteVal(-12)) {
		cout << "Value -12 deleted.\n";
	}
	else {
		cout << "Value -12 not found.\n";
	}
	cout << arrTest;
	return 0;
}