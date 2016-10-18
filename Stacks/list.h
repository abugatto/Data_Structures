
#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

using namespace std;

template <typename T>
class ListNode;

template <class S>
class Node {
private:
    Node(S, Node<S>*);
    S data;
    Node<S> *next;
    
    template <class T>
    friend class ListNode;

    template <class P>
    friend ostream& operator << (ostream&, const ListNode<P>&);
};

template <class T>
class ListNode {
public:
    ListNode();
    ListNode(const ListNode<T>&);
    ~ListNode();
    
    bool insertAfter(T);
    bool insertBefore(T);
    bool get(T&);
    bool remove(T&);
    
    void clear();
    
    bool goToBeginning();
    bool goToEnd();
    
    bool goToNext();
    bool goToPrior();
    
    bool isEmpty() const;
    bool isFull() const;
    
    ListNode<T>& operator = (const ListNode<T>&);
    
    template <class P>
    friend ostream& operator << (ostream&, const ListNode<P>&);
    
private:
    Node<T> *head;
    Node<T> *cursor;
};

//******************************************************************

template <class S>
Node<S>::Node(S i, Node* link) {
	data = i;
	next = link;
}

template <class T>
ListNode<T>::ListNode() {
	head = cursor = NULL;
}

template <class T>
ListNode<T>::ListNode(const ListNode<T>& copy) {
	head = cursor = NULL;
	
	head = new Node<T>(copy.head->data, copy.head->next);
	cursor = head->next;
	Node<T>* temp = copy.cursor;
	temp = copy.head->next;
	temp = temp->next;
	
	while(temp) {
		cursor->next = new Node<T>(temp->data, temp->next);
		cursor = cursor->next;
		temp = temp->next;
	}

	temp = NULL;
}

template <class T>
ListNode<T>::~ListNode() {
	Node<T>* temp;
	while(temp) {
		Node<T>* temp = head;
		head = head->next;

		delete temp;
		temp = NULL;
	}

	head = cursor = NULL;
}

template <class T>
void ListNode<T>::clear() {
	Node<T>* temp;
	while(temp) {
		Node<T>* temp = head;
		head = head->next;

		delete temp;
		temp = NULL;
	}

	head = cursor = NULL;
}

template <class T>
bool ListNode<T>::isEmpty() const {
	return !head;
}

template <class T>
bool ListNode<T>::isFull() const {
	return false;
}

template <class T>
ListNode<T>& ListNode<T>::operator = (const ListNode<T>& copy) {
	if(this != &copy) {
		head = cursor = NULL;

		head = new Node<T>(copy.head->data, copy.head->next);
		cursor = head->next;
		Node<T>* temp = copy.cursor;
		temp = copy.head->next;
		temp = temp->next;
		
		while(temp) {
			cursor->next = new Node<T>(temp->data, temp->next);
			cursor = cursor->next;
			temp = temp->next;
		}

		temp = NULL;
	}

	return *this;
}

template <class T>
bool ListNode<T>::goToPrior() {
	if(isEmpty() || cursor == head) {
		return false;
	}

	Node<T>* temp = head;
	while(temp->next != cursor) {
		temp = temp->next;
	}
	cursor = temp;
	temp = NULL;

	return true;
}

template <class T>
bool ListNode<T>::insertAfter(T nodespace) {
	Node<T>* temp = new Node<T>(nodespace, (isEmpty() || !cursor->next) ? NULL : cursor->next);
	if(isEmpty()) {
		head = temp;
		cursor = head;
	} else {
		cursor->next = temp;
		cursor = temp;
	}

	delete temp;
	temp = NULL;

	return true;
}

template <class T>
bool ListNode<T>::insertBefore(T nodespace) {
	if(isEmpty()) {
		Node<T>* temp = new Node<T>(nodespace, NULL);
		head = cursor = temp;

		delete temp;
		temp = NULL;
		return false;
	}

	if(cursor == head) {
		Node<T>* temp = new Node<T>(nodespace, head);
		head = cursor = temp;

		delete temp;
		temp = NULL;
		return true;
	}

	goToPrior();
	insertAfter(nodespace);

	return true;
}

template <class T>
bool ListNode<T>::get(T& nodespace) {
	if(isEmpty()) {
		return false;
	}
	nodespace = cursor->data;

	return true;
}

template <class T>
bool ListNode<T>::remove(T& nodespace) {
	if(isEmpty()) {
		return false;
	}
	nodespace = cursor->data;

	Node<T>* temp = cursor; //cout << cursor->data << endl;
	goToPrior();
	cursor->next = temp; //cout << temp->data << endl;
	cursor = cursor->next; 
	temp = NULL; 

	return true;
}

template <class T>
bool ListNode<T>::goToBeginning() {
	if(isEmpty()) {
		return false;
	}
	cursor = head;

	return true;
}

template <class T>
bool ListNode<T>::goToEnd() {
	if(isEmpty()) {
		return false;
	}

	while(cursor->next) {
		cursor = cursor->next;
	}

	return true;
}

template <class T>
bool ListNode<T>::goToNext() {
	if(isEmpty()) {
		return false;
	}
	cursor = cursor->next;

	return true;
}

template <class P>
ostream& operator << (ostream& c_out, const ListNode<P>& print) {
	if(!print.head) {
		c_out << "Empty List" << endl << endl;
	} else {
		Node<P>* temp = print.head;
		while(temp) {
			c_out << temp->data << " -> ";
			temp = temp->next;
		}
		temp = NULL;
		c_out << endl << endl;
	}

	return c_out;
}

#endif