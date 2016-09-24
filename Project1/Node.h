/**
 * @file ListInterface.h
 *
 * @brief Interface file for the List ADT
 * 
 * @author Anthony Bugatto
 * 
 * @details Specifies the implementation contract of the List ADT
 *
 * @version 0.10
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
*/

#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node {
public:
	 /** Node Constructor */
	Node();
	/** Node Copy Constructor
    @param anItem a variable of the template variable type.*/
	Node(const ItemType& anItem);
	 /** Node Copy Constructor
    @param anItem a variable of the template variable type.
    @param nextNodePtr a pointer to the node after the given node*/
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	 /** Sets the item of the Node
    @pre  None.
    @param anItem the item that is imported into the node*/
	void setItem(const ItemType& anItem);
	 /** Sets the next pointer of the Node
    @pre  None.
    @param nextNodePtr the pointer that is imported into the node*/
	void setNext(Node<ItemType>* nextNodePtr);
	/** Gets the item of the Node
    @pre None.
    @return the item in the given Node*/
	ItemType getItem() const;
	 /** Gets the next node of the list
    @pre  None.
    @return returns the next pointer of the given node*/
	Node<ItemType>* getNext() const;

private:
	ItemType item;
	Node<ItemType>* next;
};

#include "Node.cpp"
#endif