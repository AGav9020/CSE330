#include <vector>
#include <iostream>


using namespace std;
class Sorted_Vector
{
private:
	vector<int> *sorted_vector; // sorted vector
	int binarySearch(vector<int> *input, int l, int r, int x) const;
	int capacity;


public:

	~Sorted_Vector();

	/*This is a constructor which takes initial capacity “cap”
	as a parameter. */
	Sorted_Vector();

	Sorted_Vector(int cap);

	/*Returns the capacity of the vector.*/
	int getCapacity() const;

	/*Returns the size of the vector.*/
	int getSize() const;

	/*Returns true if the vector is empty (i.e., size == 0). 
	Otherwise, returns false.*/
	bool isEmpty() const;
	
	bool isFull();

	void expand();

	/*Insert a given value “val” into the vector, while preserving 
	the non-decreasing order of the vector. Note that you cannot 
	use any built-in sort function in the implementation of this 
	function. Instead, you need to find the appropriate location 
	at which you should insert “val” into the vector.*/
	void insertVal(int val);



	/*Find a given value “val” in the vector and return the index. 
	If “val” is not in the vector, return -1. Hint: use binary search.*/
	int findVal(int val) const;

	/*Delete a given value “val” from the vector, while preserving 
	the non-decreasing order of the vector. If the deletion is
	successful, return true. Otherwise, if “val” is not in the
	vector, return false. Hint: “deleteVal” should call “find”*/
	bool deleteVal(int val);

	int valueAt(int idx) const;

	/*This should print out the elements of the vector 
	(i.e., from sorted_vector[0] to sorted_vector[getSize()-1]). 
	It should print out the elements, separated by a space, on a
	single line.*/
	friend ostream & operator<<(ostream &out, const Sorted_Vector &sV);

	// Homework, not part of lab
	int firstElementGreater(int val);
};

