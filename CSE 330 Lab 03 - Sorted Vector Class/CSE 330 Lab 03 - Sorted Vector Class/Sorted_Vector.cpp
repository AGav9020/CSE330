#include "pch.h"
#include "Sorted_Vector.h"


Sorted_Vector::~Sorted_Vector()
{
	this->sorted_vector->clear();
	delete sorted_vector;



}

Sorted_Vector::Sorted_Vector()
{
	this->capacity = 10;
	this->sorted_vector = new vector<int>;
}

Sorted_Vector::Sorted_Vector(int cap)
{
	this->capacity = cap;
	this->sorted_vector = new vector<int>;
}

int Sorted_Vector::getCapacity() const
{
	
	return this->capacity;

}

int Sorted_Vector::getSize() const
{

	return (sorted_vector->size());	

}


bool Sorted_Vector::isEmpty() const
{
	return (sorted_vector->size() == 0);
}
bool Sorted_Vector::isFull()
{

	return (sorted_vector->size() == capacity);
}

void Sorted_Vector::expand()
{
	this->capacity = this->capacity * 2;

}

void Sorted_Vector::insertVal(int val)
{

	int insertLocation = 0;

	if (this->isFull()) {
		this->expand();
	}
	while ((insertLocation < this->sorted_vector->size()) 
		&& (this->sorted_vector->at(insertLocation) <= val)) {
		//DEBUG
		//cout << this->sorted_vector->at(insertLocation) << " - " << val << endl;
		insertLocation++;

	}


	if (insertLocation == sorted_vector->size()) {
		sorted_vector->push_back(val);
	}
	else {
		sorted_vector->insert(sorted_vector->begin() + insertLocation, val);
	}



}
int Sorted_Vector::findVal(int val) const
{
	int ret;
	ret = this->binarySearch(sorted_vector, 0, sorted_vector->size() - 1, val);
	return ret;
}
int Sorted_Vector::binarySearch(vector<int> *input, int left, int right, int value) const
{
	while (left <= right) {
		int mid = left + (right - left) / 2;

		// Check if x is present at mid 
		if (input->at(mid) == value)
			return mid;

		// If x greater, ignore left half 
		if (input->at(mid) < value)
			left = mid + 1;

		// If x is smaller, ignore right half 
		else
			right = mid - 1;
	}

	// if we reach here, then element was 
	// not present 
	return -1;
}

bool Sorted_Vector::deleteVal(int val)
{
	int indexLocation = this->findVal(val);
	if (indexLocation == -1) {
		return false;
	}
	else {
		sorted_vector->erase(sorted_vector->begin()+indexLocation);

		return true;
	}


	return false;
}

int Sorted_Vector::valueAt(int idx) const
{

	return sorted_vector->at(idx);
}

// this is part of the homework, not the lab
int Sorted_Vector::firstElementGreater(int val)
{
	int insertLocation = 0;
	while ((insertLocation < this->sorted_vector->size()) 
		&& (this->sorted_vector->at(insertLocation) <= val)) {
		insertLocation++;

	}

	if (insertLocation == sorted_vector->size()) {
		return -1;
	}
	else {
		return insertLocation;
	}
}




ostream & operator<<(ostream & out, const Sorted_Vector &sV)
{
	out << "{ ";


	for (int idx = 0; idx < sV.getSize(); idx++) {
		out << sV.valueAt(idx) << " ";

	}

	out << "}" << endl;
	return out;

}
