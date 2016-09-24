/**
 * @file PA01.cpp
 *
 * @brief Test driver for LinkedList
 * 
 * @author Anthony Bugatto
 * 
 * @details tests various parts of the LinkedList
 *
 * @version 0.10
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
*/

#ifndef PAO1_CPP
#define PAO1_CPP

#include <iostream>
#include "LinkedList.h"

using namespace std;

template<typename T>
void displayList(const LinkedList<T>& list, const string& message);

int main(int argc, char** argv) {
	LinkedList<int>* intlist = new LinkedList<int>;
	for(int i = 0; i < 10; i++) {
		intlist->insert(i, i);
	}
	displayList(*intlist, "This is an int list: ");

	LinkedList<int>* intlist_two = new LinkedList<int>(*intlist);
	displayList(*intlist_two, "This is an int list copy: ");

	for(int i = 0; i < 5; i++) {
		intlist_two->replace(i, intlist->getEntry(3 + i));
		bool useless = intlist->remove(3 + i);
	}

	displayList(*intlist, "List 1: ");
	displayList(*intlist_two, "List 2: ");

	cout << "The legnth of list 1 is: " << intlist->getLength() << endl;
	intlist->clear();
	cout << (intlist->isEmpty() ? "empty" : "not empty") << endl;

	cout << "The legnth of list 2 is: " << intlist_two->getLength() << endl;
	intlist_two->clear();

	cout << "lists cleared" << endl;

	return 0;
}

/**	Prints the LinkedList
    @pre  None.
    @post  prints out the linked List
    @param list  The list.
    @param message any words wanted before this */
template<typename T>
void displayList(const LinkedList<T>& list, const string& message) {
	T value;

	cout << endl << message;
	for(int i = 0; i < list.getLength(); i++) {
		value = list.getEntry(i);
		cout << "[" << value << "]";
	}
	cout << endl;
}

#endif