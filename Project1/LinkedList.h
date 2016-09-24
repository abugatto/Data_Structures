/**
 * @file LinkedList.h
 *
 * @brief inherited class declaration file for ADT
 * 
 * @author Anthony Bugatto
 * 
 * @details Specifies the implementation of the LinkedList class
 *
 * @version 0.10
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

using namespace std;

template<class ItemType>
class LinkedList : ListInterface<ItemType> {
private:
	Node<ItemType>* headPtr;
	int itemCount;

	Node<ItemType>* getNodeAt(int position) const;

public:
	LinkedList() : headPtr(nullptr), itemCount(0) {}
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();
	/** Sees whether this list is empty.
    @return True if the list is empty; otherwise returns false. */
   bool isEmpty() const;
   
   /** Gets the current number of entries in this list.
    @return The integer number of entries currently in the list. */
   int getLength() const;
   
   /** Inserts an entry into this list at a given position.
    @pre  None.
    @post  If 1 <= position <= getLength() + 1 and the insertion is
       successful, newEntry is at the given position in the list,
       other entries are renumbered accordingly, and the returned
       value is true.
    @param newPosition  The list position at which to insert newEntry.
    @param newEntry  The entry to insert into the list.
    @return  True if insertion is successful, or false if not. */
   bool insert(int newPosition, const ItemType& newEntry);
   
   /** Removes the entry at a given position from this list.
    @pre  None.
    @post  If 1 <= position <= getLength() and the removal is successful,
       the entry at the given position in the list is removed, other
       items are renumbered accordingly, and the returned value is true.
    @param position  The list position of the entry to remove.
    @return  True if removal is successful, or false if not. */
   bool remove(int position);
   
   /** Removes all entries from this list.
    @post  List contains no entries and the count of items is 0. */
   void clear();
   
   /** Gets the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The desired entry has been returned.
    @param position  The list position of the desired entry.
    @return  The entry at the given position. */
   ItemType getEntry(int position) const throw(PrecondViolatedExcep);
   
   /** Replaces the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The entry at the given position is newEntry.
    @param position  The list position of the entry to replace.
    @param newEntry  The replacement entry. */
   void replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);
};

#include "LinkedList.cpp"
#endif