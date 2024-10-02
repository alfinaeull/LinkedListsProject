#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>

typedef std::string ItemType;

struct Node {
	ItemType value;
	Node* next;
};

class LinkedList {
	private:
		Node* head;

		void printReverseHelper(const LinkedList& rhs, int i) const;

	public:

		LinkedList(); // constructor

		LinkedList(const LinkedList& rhs); // copy constructor

		~LinkedList(); // destructor

		const LinkedList& operator=(const LinkedList& rhs); // assignment operator

		void insertToFront(const ItemType& val); // inserts val to front of list

		void printList() const; // prints the list

		bool get(int i, ItemType& item) const;
		// sets item to value at pos i in list and returns true
		// returns false if no element i

		void reverseList(); // reverses the list

		void printReverse() const; // prints list in reverse order

		void append(const LinkedList& other); // append values of other list onto end of this list

		void swap(LinkedList& other); // swaps contents of this list with other list

		int size() const; // returns number of items in the list

};

#endif