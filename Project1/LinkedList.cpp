/**
 * @file LinkedList.cpp
 *
 * @brief implementation file for LinkedList class
 * 
 * @author Anthony Bugatto
 * 
 * @details Implementation of the LinkedList class
 *
 * @version 0.10
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 */

#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include <iostream>
#include "LinkedList.h"
#include <cassert>

using namespace std;

	template<class ItemType>
	Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
		assert((position >= 1) && (position <= itemCount));

		Node<ItemType>* curPtr = headPtr;
		for(int i = 0; i < position; i++) {
			curPtr = curPtr->getNext();
		}

		return curPtr;
	}

  template<class ItemType>
	LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {
		int pos = 0;
    int my_legnth = 0;
		while(my_legnth != aList.getLength()) {
			insert(pos, aList.getEntry(pos));
			my_legnth = getLength();
		}
	}

  template<class ItemType>
	LinkedList<ItemType>::~LinkedList() {
		clear();
	}

/** Sees whether this list is empty.
    @return True if the list is empty; otherwise returns false. */
   template<class ItemType>
   bool LinkedList<ItemType>::isEmpty() const {
   		return itemCount == 0;
   }
   
   /** Gets the current number of entries in this list.
    @return The integer number of entries currently in the list. */
   template<class ItemType>
   int LinkedList<ItemType>::getLength() const {
   		return itemCount;
   }
   
   /** Inserts an entry into this list at a given position.
    @pre  None.
    @post  If 1 <= position <= getLength() + 1 and the insertion is
       successful, newEntry is at the given position in the list,
       other entries are renumbered accordingly, and the returned
       value is true.
    @param newPosition  The list position at which to insert newEntry.
    @param newEntry  The entry to insert into the list.
    @return  True if insertion is successful, or false if not. */
   template<class ItemType>
   bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
   		bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);

   		if(ableToInsert) {
   			Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

   			if(newPosition == 1) {
   				newNodePtr->setNext(headPtr);
   				headPtr = newNodePtr;
   			} else {
   				Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

   				newNodePtr->setNext(prevPtr->getNext());
   				prevPtr->setNext(newNodePtr);
   			}

   			itemCount++;
   		}

   		return ableToInsert;
   }
   
   /** Removes the entry at a given position from this list.
    @pre  None.
    @post  If 1 <= position <= getLength() and the removal is successful,
       the entry at the given position in the list is removed, other
       items are renumbered accordingly, and the returned value is true.
    @param position  The list position of the entry to remove.
    @return  True if removal is successful, or false if not. */
   template<class ItemType>
   bool LinkedList<ItemType>::remove(int position) {
   		bool ableToRemove = (position >= 1) && (position <= itemCount);

   		if(ableToRemove) {
   			Node<ItemType>* curPtr = nullptr;

   			if(position == 1) {
   				curPtr = headPtr;
   				headPtr = headPtr->getNext();
   			} else {
   				Node<ItemType>* prevPtr = getNodeAt(position - 1);
   				curPtr = prevPtr->getNext();
   				prevPtr->setNext(curPtr->getNext());
   			}

   			curPtr->setNext(nullptr);
   			delete curPtr;
   			curPtr = nullptr;

   			itemCount--;
   		}

   		return ableToRemove;
   }
   
   /** Removes all entries from this list.
    @post  List contains no entries and the count of items is 0. */
   template<class ItemType>
   void LinkedList<ItemType>::clear() {
   		while(!isEmpty()) {
   			remove(1);
   		}
   }
   
   /** Gets the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The desired entry has been returned.
    @param position  The list position of the desired entry.
    @return  The entry at the given position. */
   template<class ItemType>
   ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep) {
   		bool ableToGet = (position >= 1) && (position <= itemCount);

   		if(ableToGet) {
   			Node<ItemType>* nodePtr = getNodeAt(position);
   			return nodePtr->getItem();
   		} else {
   			string message = "getEntry() called withb an empty list or ";
   			message = message + "invalid position.";
   			throw(PrecondViolatedExcep(message));
   		}
   }
   
   /** Replaces the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The entry at the given position is newEntry.
    @param position  The list position of the entry to replace.
    @param newEntry  The replacement entry. */
   template<class ItemType>
   void LinkedList<ItemType>::replace(int position, const ItemType& newEntry)  throw(PrecondViolatedExcep) {
   		bool ableToReplace = (position >= 1) && (position <= itemCount);

   		if(ableToReplace) {
   			remove(position);
   			insert(position - 1, newEntry);
   		} else {
   			string message = "replace() called withb an empty list or ";
   			message = message + "invalid position.";
   			throw(PrecondViolatedExcep(message));
   		}
   }

#endif