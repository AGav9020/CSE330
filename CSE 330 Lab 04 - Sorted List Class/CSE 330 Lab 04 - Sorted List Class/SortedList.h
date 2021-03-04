#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
using namespace std;

template <typename Object>
class SortedList
{
  private:    
    struct Node
    {
      Object  data;
      Node   *prev;
      Node   *next;

      Node( const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr )
        : data{ d }, prev{ p }, next{ n } { }
    };

    int  theSize;
    Node *head;
    Node *tail;

  
  public:
    SortedList( )
    { 
      theSize = 0;
      head = new Node;
      tail = new Node;
      head->next = tail;
      tail->prev = head;
    }

	/* Insert a given item “x” into the list, while preserving 
	the non-decreasing order of the list. Note that you cannot 
	use any sort function in the implementation of this function. 
	Instead, you need to find the appropriate location at which 
	you should insert “x” into the list.*/
	void insertItem(const Object & x) {
		Node *newNode = new Node;
		newNode->data = x;
		if (this->empty() == true) {
			this->head->next = newNode;
			this->tail->prev = newNode;
			newNode->prev = head;
			newNode->next = tail;
		}
		else {
			Node *tempNode = new Node;

			tempNode = this->head->next;

			while (tempNode != tail) {
				if (tempNode->data > newNode->data) {
 					tempNode->prev->next = newNode;
					newNode->prev = tempNode->prev;
					newNode->next = tempNode;
					tempNode->prev = newNode;
					break;
				}
				tempNode = tempNode->next;
			}
			// went through entire loop which means
			// we add this before tail
			// Last element in the list
			if (tempNode == tail){
				tail->prev->next = newNode;
				newNode->prev = tail->prev;
				newNode->next = tail;
				this->tail->prev = newNode;
			}
		}

		this->theSize++;
	}


	/* Delete a given item “x” from the list, while preserving 
	the non-decreasing order of the list. If the deletion is 
	successful, return true. Otherwise, if “x” is not in the 
	list, return false.*/
	bool deleteItem(const Object & x) {
		//TODO
		Node *tempNode;

		tempNode = this->head->next;

		while (tempNode != tail) {
			if (tempNode->data == x) {
				tempNode->prev->next = tempNode->next;
				tempNode->next->prev = tempNode->prev;
				delete tempNode;
				theSize--;
				return true;
			}
			tempNode = tempNode->next;
		}
		return false;

	}


	/* This should print out the elements of the list. It 
	should print out the elements, separated by a space, 
	on a single line.*/
	friend ostream & operator<<(ostream &out, const SortedList &sL) {
		out << "{ ";
		Node *theNode = sL.head->next;
		while (theNode != sL.tail) {
			out << theNode->data;
			theNode = theNode->next;
			out << " ";
		}
		out << "}\n";

		return out;

	}


	/* This is a destructor. 
	This is an optional exercise.*/
	~SortedList() {
		Node *currentNode = head;
		while (currentNode != tail) {
			head = head->next;
			delete currentNode;
			currentNode = head;

		}
		delete tail;


	}


	/* This returns the size of the list.*/
	int size() const {
		return this->theSize;
	}


	/* Returns true if list is empty. 
	Otherwise, returns false.*/
	bool empty() const {
		return (this->theSize == 0);
	}

	int sum() {
		Node *currentNode = head->next;
		int sumOfElements = 0;
		while (currentNode != tail) {
			sumOfElements += currentNode->data;
			currentNode = currentNode->next;
		}
		return sumOfElements;
	}

};

#endif

	
