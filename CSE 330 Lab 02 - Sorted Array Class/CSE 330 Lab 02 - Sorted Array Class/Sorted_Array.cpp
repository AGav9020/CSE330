#include "pch.h"
#include "Sorted_Array.h"
#include <iostream>
using namespace std;


Sorted_Array::Sorted_Array(int val)
{
	this->size = 0;
	this->capacity = val;
	this->arr = new int[this->capacity];
}
/*
Sorted_Array::Sorted_Array(const Sorted_Array & sA)
{
	//size = ;
	//this->size = sA.getSize();
	this->capacity = sA.getCapacity();
	this->arr = sA.getArray();
}
*/
/*
const Sorted_Array & Sorted_Array::operator=(const Sorted_Array & sA)
{
	// TODO: insert return statement here
}
*/
Sorted_Array::~Sorted_Array()
{

}

const int Sorted_Array::getCapacity()
{
	return this->capacity;
}

int Sorted_Array::getSize()
{
	return this->size;
}

int * Sorted_Array::getArray()
{
	return this->arr;
}

bool Sorted_Array::isFull()
{
	
	return (size == capacity);
}

bool Sorted_Array::isEmpty()
{
	return (size == 0);
}

// expand and 
void Sorted_Array::expand()
{
	this->capacity = this->capacity * 2;
	int *arrTemp = new int[this->capacity] ;
	for (int i = 0; i < size; i++) {
		arrTemp[i] = arr[i];

	}


	this->arr = arrTemp;
}

void Sorted_Array::shiftRight(int location) {
	// just in case it's used elsewhere
	if (this->isFull()) {
		this->expand();
	}
	// shifts it right using for loop
	for (int index = this->size; index > location; index--) {
		this->arr[index] = this->arr[index - 1];
	}
	this->size++;


}

// function states it
void Sorted_Array::shiftLeft(int location) {
	for (int index = location; index < size; index++) {
		this->arr[index] = this->arr[index + 1];
	}
	this->size--;
}


void Sorted_Array::insertVal(int val)
{

	int insertLocation = 0;

	if (this->isFull()) {
		this->expand();
	}

	// Finding location to insert val
	while((insertLocation < this->size) && (this->arr[insertLocation] <=val)){
		insertLocation++;

	}
	this->shiftRight(insertLocation);

	this->arr[insertLocation] = val;

}
// no recursion
int Sorted_Array::binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid 
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half 
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half 
		else
			r = m - 1;
	}

	// if we reach here, then element was 
	// not present 
	return -1;
}

int Sorted_Array::find(int val)
{
	return this->binarySearch(arr, 0, this->size -1, val);
}

bool Sorted_Array::deleteVal(int val)
{
	int indexLocation = this->find(val);
	if (indexLocation == -1) {
		return false;
	}
	else {
		shiftLeft(indexLocation);

		return true;
	}


}

int Sorted_Array::numOfTimes(int val)
{
	int indexLocation = 0;
	int countOfVal = 0;
	while ((indexLocation < this->size) 
		&& (this->arr[indexLocation] != val)) {
		indexLocation++;
		//debug
		//cout << "f" << indexLocation << endl;
	}

	//debug
	//cout << indexLocation << endl;
	while ((indexLocation < this->size)
		&& (this->arr[indexLocation] == val)) {
		indexLocation++;
		countOfVal++;
		//debug
		//cout << "c" << indexLocation;
	}

	return countOfVal;
}

ostream & operator<<(ostream & out, Sorted_Array & sA)
{
	out <<"{ ";

	
	for (int idx = 0; idx < sA.getSize(); idx++) {
		out << sA.getArray()[idx] << " ";

	}

	out << "}"<< endl;
	return out;
	// TODO: insert return statement here
}
