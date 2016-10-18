#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template<class T>
class Stack;

template<class S>
class Node{
private:
	Node(char, Node<S>*);
	char data;
	Node<S>* next;
	friend class Stack;
};

template<class T>
class Stack{
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
	Node<T>* top;
};

template <class S>
Node::Node(S c, Node<S>* node) 
{
    data = c;
    next = node;
}

template <class T>
Stack<T>::Stack(int i)
{
    top = NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T>& copy)
{
    top = new Node(copy.top->data, copy.top->next);
    Node<T>* temp = top->next;
    Node<T>* tempc = copy.top->next;

    while(tempc) {
        temp = new Node(tempc->data, tempc->next);
        temp = temp->next;
        tempc = tempc->next;
    }

    temp = tempc = NULL;
}

template <class T>
Stack<T>::~Stack()
{
    if(top) {
        top = top->next;
    }
}

template <class T>
bool Stack<T>::clear()
{
    if(empty()) {
        return false;
    }

    while(top) {
        top = top->next;
    }

    return true;
}

template <class T>
Stack& Stack<T>::operator=(const Stack<T>& copy)
{
    if(this != &copy) { 
        clear();

        top = new Node(copy.top->data, copy.top->next);
        Node<T>* temp = top->next;
        Node<T>* tempc = copy.top->next;

        while(tempc) {
            temp = new Node(tempc->data, tempc->next);
            temp = temp->next;
            tempc = tempc->next;
        }

        temp = tempc = NULL;
    }

    return *this;
}

template <class T>
bool Stack<T>::empty() const
{
    return !top;
}

template <class T>
bool Stack<T>::push(T c)
{
    if(full()) {
        return false;
    }

    top = new Node(c, top);
    return true;
}

template <class T>
bool Stack<T>::pop(T& c)
{
    if(empty()) {
        return false;
    }

    Node<T>* temp = top;
    c = top->data;
    top = top->next;
    delete[] temp;
    return true;
}

#endif