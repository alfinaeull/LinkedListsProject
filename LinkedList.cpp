#include "LinkedList.h"

#include <iostream>
using namespace std;

// Constructor
LinkedList::LinkedList()
: head(nullptr)
{

}

// Copy Constructor
LinkedList::LinkedList(const LinkedList& rhs)
: head(nullptr)
{
	if (rhs.head == nullptr) {
		return;
	}
	else {
		Node* current_clone = new Node;
		current_clone->value = rhs.head->value;
		current_clone->next = nullptr;
		head = current_clone;
		
		Node* current_original = rhs.head->next;
		
		// copy over nodes from rhs to clone
		while (current_original != nullptr) {
			Node* next_clone = new Node;
			next_clone->value = current_original->value;
			current_clone->next = next_clone;

			current_clone = current_clone->next;

			current_original = current_original->next;

			next_clone->next = nullptr;
		}
	}
}


// Destructor
LinkedList::~LinkedList()
{
	while (head != nullptr) {
		Node* to_destruct = head->next;
		delete head;
		head = to_destruct;
	}

	head = nullptr;
}


// assignment operator
const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{	
	if (rhs.head == nullptr) {
		return *this;
	}
	else {
		// check for aliasing, don't let self = self
		if (&rhs == this) {
			return *this;
		}

		// copy over destructor logic
		while (head != nullptr) {
			Node* to_destruct = head->next;
			delete head;
			head = to_destruct;
		}
		head = nullptr;

		// copy constructor logic
		Node* current_clone = new Node;
		current_clone->value = rhs.head->value;
		current_clone->next = nullptr;
		head = current_clone;

		Node* current_original = rhs.head->next;

		// copy over nodes from rhs to clone
		while (current_original != nullptr) {
			Node* next_clone = new Node;
			next_clone->value = current_original->value;
			current_clone->next = next_clone;

			current_clone = current_clone->next;

			current_original = current_original->next;

			next_clone->next = nullptr;
		}
	}

}


// insert val to front of list
void LinkedList::insertToFront(const ItemType& val)
{
	Node* to_insert = new Node;
	to_insert->value = val;
	to_insert->next = head;
	head = to_insert;
}


// prints the list
void LinkedList::printList() const
{
	Node* track;
	
	if (head == nullptr) {
		return;
	}
	else {
		track = head;
		while (track != nullptr) {
			cout << track->value << endl;
			track = track->next;
		}
	}
}


// sets item to value at position i in list and returns true
// returns false if no element i
bool LinkedList::get(int i, ItemType& item) const
{
	Node* current = head;

	for (int k = 0; k < i-1; k++) {
		current = current->next;
	}
	
	if (current != nullptr) {
		item = current->value;
		return true;
	}
	return false;
}


// reverses the list
void LinkedList::reverseList()
{
	Node* current = head;
	Node* previous = nullptr;
	Node* next = nullptr;

	while (current->next != nullptr) {
		next = current->next;
		
		current->next = previous;

		previous = current;

		current = next;
	}
	// stops right before printing the last node, so one more time:
	current->next = previous;

	previous = current;

	current = next;

	head = current;
}


// prints list in reverse order
void LinkedList::printReverse() const
{
	printReverseHelper(*this, size());
}

//helper function for printReverse
void LinkedList::printReverseHelper(const LinkedList& rhs, int i) const
{
	ItemType value;
	// call get function
	rhs.get(i, value);
	cout << value << endl;
	// base case
	if (i == 0) {
		return;
	}
	// recursive call, going backwards through the list
	printReverseHelper(rhs, i-1);
}


// append values of other list onto end of this list
void LinkedList::append(const LinkedList& other)
{
	Node* current = head;

	// traverse to the end of this list
	while (current->next != nullptr) {
		current = current->next;
	}
	
	// create deep copy of other list
	if (other.head == nullptr) {
		return;
	}
	else {
		LinkedList copy_other(other);
		
		// connect last node of current list to first element of other list
		current->next = copy_other.head;

		copy_other.head = nullptr; // for destructor
	}
}

// swaps contents of this list with other list
void LinkedList::swap(LinkedList& other)
{
	Node* p = head;
	head = other.head;
	other.head = p;

}


// returns number of items in list
int LinkedList::size() const
{
	int count = 0;
	Node* current = head;

	while (current != nullptr) {
		current = current->next;
		count++;
	}

	return count;
}
