#include <iostream>
using namespace std;

class Sorted_Array
{
private:
	// “capacity” represents the capacity of the array
	int capacity;

	// “size” represents the actual number of elements in the array
	int size;

	// “arr” is a pointer to the first element of the array
	// Note: “arr” should be a pointer to a dynamically allocated array 
	// (i.e., using the new keyword)
	int *arr;

	int binarySearch(int arr[], int l, int r, int x);

public:
	


	// This is a constructor which takes initial capacity "cap"
	// as a parameter.
	Sorted_Array(int val);

	// BONUS - did not do
	// This is a copy constructor.
	//Sorted_Array(const Sorted_Array & sA);

	// BONUS
	// This is a copy assignment operator
	//const Sorted_Array & operator=(const Sorted_Array & sA);

	// This is a destructor.
	~Sorted_Array();

	// Returns the capacity of the array
	const int getCapacity();

	// Returns the size of the array
	int getSize();

	// 
	int* getArray();

	// returns TRUE if array is full
	bool isFull();

	// returns TRUE if array is empty
	bool isEmpty();

	// this doubles the capacity of the array
	void expand();

	void shiftRight(int location);
	void shiftLeft(int location);

	// Insert a given value “val” into the array, while preserving the 
	// non-decreasing order of the array.If the array is full, you should 
	// first call “expand” and then insert the value “val” into the array.
	// Note that you cannot use any built - in sort function in the
	// implementation of this function.Instead, you need to find the 
	// appropriate location at which you should insert “val” into the array.
	void insertVal(int val);

	// Find a given value “val” in the array and return the index. 
	// If “val” is not in the array, return -1. Hint: use binary search.
	int find(int val);

	// Delete a given value “val” from the array, while preserving the 
	// non-decreasing order of the array.If the deletion is successful, return true
	// Otherwise, if “val” is not in the array, return false.
	// Hint: “delete” should call “find”.
	bool deleteVal(int val);

	// This should print out the elements of the array 
	// (i.e., from array[0] to array[size-1]). It should print out the 
	// elements, separated by a space, on a single line.
	friend ostream & operator<<(ostream &out, Sorted_Array &sA);

	int numOfTimes(int val);

};

