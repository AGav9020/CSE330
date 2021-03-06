/*
ALANNAH GAVUZZI
CSE 330 DATA STRUCTURES
LAB 01

THE UNION AND INTERSECTION OF TWO ARRAYS SORTED
CHRONOLOGICALLY, STORED IN A NEW ARRAY AND PRINTED

*/
#include  "pch.h" // this is unnecessary but needed to run this in VB :(
#include <iostream>
#include <algorithm>
using namespace std;

// union is a new set that contains all the elements that are in at least one of the two sets with no repeats
// this function assumes the arrays are in increasing order


int computeUnion(int input1[], int input2[], int output[], int sizeInput1, int sizeInput2) {
	int i = 0; // index of input1
	int j = 0; // index of input2
	int k = 0; // index of union array

	// Want to output the union of the two sets without repeats, so need to check each individual element
	// first need to gather all elements that are in at least one of the sets
	while (i < sizeInput1 && j < sizeInput2) {
		// For debugging purposes
		/*
		cout << input1[i] << " - ";
		cout << input2[j] << "\n";
		*/
		// is the element in the first array 
		// LESS than the element in the second array?
		// if so, store the element from the first array in the new array
		if (input1[i] < input2[j]) {
			if (output[k - 1] != input1[i]) {
				output[k] = input1[i];
				k++;
			}
			i++;

		}

		// is the element in the first array 
		// GREATER than the element in the second array?
		// if so, store the element from the second array in the new array
		else if (input1[i] > input2[j]) {
			if (output[k - 1] != input2[j]) {
				output[k] = input2[j];
				k++;
			}
			j++;
		}

		// are the two elements from the array exactly equivalent?
		// if so, store one and move to the next elements in both
		else {
			if (output[k - 1] != input1[i]) {
				output[k] = input1[i];
				k++;
			}
			i++;
			j++;
		}

	}

	// new loop to print out the remainder of the larger array

	// if the first array is larger, then store out the remainder of array
	while (i < sizeInput1) {
		if (output[k - 1] != input1[i]) {
			output[k] = input1[i];
			k++;
		}
		i++;
	}

	// if the second array is larger, store the remainder
	while (j < sizeInput2) {
		if (output[k - 1] != input2[j]) {
			output[k] = input2[j];
			k++;
		}
		j++;
	}

	// return the value to obtain the new array size
	return k;
}

// intersection is a new set that contains all the elements that are in both sets
// this function assumes the arrays are in increasing order
int computeIntersection(int input1[], int input2[], int output[], int sizeInput1, int sizeInput2) {
	int i = 0; // index of input1
	int j = 0; // index of input2
	int k = 0; // index of intersection array

	//have to print out only the elements that are in both sets
	while (i < sizeInput1 || j < sizeInput2) {
		/* For debugging purposes
		cout << input1[i] << " - ";
		cout << input2[j] << "\n";*/

		// is the element in the first array 
		// LESS than the element in the second array?
		// if so, go to the next element in the first array
		if (input1[i] < input2[j]) {
			i++;

		}

		// is the element in the first array 
		// GREATER than the element in the second array?
		// if so, go to the next element in the second array
		else if (input1[i] > input2[j]) {
			j++;

		}

		// are the elements exactly alike?
		// if so, store the element in an output array
		// and move on to the next element in both input arrays
		else { 
			// store element in new array
			if (output[k - 1] != input1[i]) {
				output[k] = input1[i];
				k++;
			}
			// increase the index of all arrays
			i++;
			j++;
		}
	}
	// return the value to obtain the new array size
	return k;
}

// print will print out an array when used
void print(const int arr[], int size) {
	cout << "{ ";
	for (int i = 0; i < size; ++i) {
		cout << arr[i];
		if (i < size - 1) {
			cout << ", ";
		}
	}

	cout << " }" << endl;
	cout << size << " elements" << endl;
}

//void scenarioOne();

int main()
{
	int arr1[] = { -5,-5,-3,0,1,1,2,3,3,4,5,9 };
	int arr2[] = { -5,-3,-3,0,0,1,1,2,3,5,7,8 };

	int const unionSize = 24; // this must be at least arr1 + arr2
	int const intersectionSize =  12; // this must be at most arr1 or arr2
	
	int resultCount;
	int arrOutputIntersection[intersectionSize] = {};
	int arrOutputUnion[unionSize] = {};

	// These only work for fixed size arrays, so no cin in this program
	// This is to get the sizes of the arrays
	int arrayFirstSize = sizeof(arr1) / sizeof(arr1[0]);
	int arraySecondSize = sizeof(arr2) / sizeof(arr2[0]);


	cout << "First Array: " << endl;
	print(arr1, arrayFirstSize);
	cout << endl;

	cout << "Second Array: " << endl;
	print(arr2, arraySecondSize);
	cout << endl;

	// result count is used for intersection first
	resultCount = computeIntersection(arr1, arr2, arrOutputIntersection, arrayFirstSize, arraySecondSize);

	cout << "For Intersection, these are the elements and the size for the above arrays:" << endl;
	print(arrOutputIntersection, resultCount);

	cout << "For Union, these are the elements and the size for the above arrays:" << endl;

	// change the value of result count to union
	resultCount = computeUnion(arr1, arr2, arrOutputUnion, arrayFirstSize, arraySecondSize);
	print(arrOutputUnion, resultCount);

	return 0;
}