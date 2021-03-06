/*
ALANNAH GAVUZZI
CSE 330
Lab 03 - Sorted Vector Class
*/

#include "pch.h"
#include "Sorted_Vector.h"
#include <iostream>

using namespace std;
int main()

{
   /*Inside the main function, perform the following steps/operations:
		1. Create an object of type “SortedVector” with initial capacity = 10.
		2. Call “getSize” and print out the size of the vector.
		3. Call “getCapacity” and print out the capacity of the vector.
		4. Call “isEmpty” and print out an appropriate message (either vector is empty or not
		empty).
		5. Call “insertVal” 15 times. After each insert, print out the vector. You may choose which
		values to insert. However, please make sure that there are at least 8 unique values out
		of the 15. Also, make sure there is at least two repeated values (e.g., insert “7” twice
		and insert “16” twice).
		6. Call “getSize” and print out the size of the vector.
		7. Call “isEmpty” and print out an appropriate message (either vector is empty or not
		empty).
		8. Call “deleteVal” 5 times. After each delete, print out the vector. One of the values to be
		deleted should not be present in the vector. You should print out an appropriate
		message if a given value is not in the vector (e.g., “Error: Value 58 not found in vector.”).
		9. Call “getSize” and print out the size of the vector.*/

	// 1.
	Sorted_Vector arrTest = Sorted_Vector(10);

	// 2.
	cout << arrTest.getSize() << " is the vector size.\n" ;

	// 3.
	cout << arrTest.getCapacity()<< " is the vector capacity.\n";

	// 4.
	if (arrTest.isEmpty() == true) {
		cout << "\nThe sorted array is empty.\n";
	}
	else {
		cout << "\nThe sorted array is not empty.\n";
	}
	// 5.
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

	// 6. 
	cout << arrTest.getSize() << " is the new size of the vector.\n";

	// 7. 
	if (arrTest.isEmpty() == true) {
		cout << "\nThe sorted array is empty.\n";
	}
	else {
		cout << "\nThe sorted array is not empty.\n";
	}



	// 8.
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

	// 9.
	cout << arrTest.getSize() << " is the size of the vector.\n";
}

