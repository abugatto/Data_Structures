#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template<class T>
class Stack;

template<class S>
class SNode {
private:
	SNode(S, SNode<S>*);
	S data;
	SNode<S>* next;

	template<class T>
	friend class Stack;
};

template<class T>
class Stack {
public:
    Stack(int = 0);
    Stack(const Stack<T>&);
    ~Stack();
    Stack& operator=(const Stack<T>&);
    bool push(T);
    bool pop(T&);
    bool empty() const;
    bool clear();

private:
	SNode<T>* top;
};

template <class S>
SNode<S>::SNode(S temp, SNode<S>* node) {
    data = temp;
    next = node;
}

template <class T>
Stack<T>::Stack(int i) {
    top = NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T>& copy) {
    top = new SNode<T>(copy.top->data, copy.top->next);
    SNode<T>* temp = top->next;
    SNode<T>* tempc = copy.top->next;

    while(tempc) {
        temp = new SNode<T>(tempc->data, tempc->next);
        temp = temp->next;
        tempc = tempc->next;
    }

    temp = tempc = NULL;
}

template <class T>
Stack<T>::~Stack() {
    if(top) {
        top = top->next;
    }
}

template <class T>
bool Stack<T>::clear() {
    if(empty()) {
        return false;
    }

    while(top) {
        top = top->next;
    }

    return true;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& copy) {
    if(this != &copy) { 
        clear();

        top = new SNode<T>(copy.top->data, copy.top->next);
        SNode<T>* temp = top->next;
        SNode<T>* tempc = copy.top->next;

        while(tempc) {
            temp = new SNode<T>(tempc->data, tempc->next);
            temp = temp->next;
            tempc = tempc->next;
        }

        temp = tempc = NULL;
    }

    return *this;
}

template <class T>
bool Stack<T>::empty() const {
    return !top;
}

template <class T>
bool Stack<T>::push(T c) {
    top = new SNode<T>(c, top);
    return true;
}

template <class T>
bool Stack<T>::pop(T& c) {
    if(empty()) {
        return false;
    }

    SNode<T>* temp = top;
    c = top->data;
    top = top->next;
    delete[] temp;
    return true;
}

#endif