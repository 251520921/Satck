#pragma once

#include "Vector.h"

template<class T>
class Stack : protected Vector<T> {
public:
	Stack();

	int size() const;
	bool empty() const;

	void push(T const& e);
	T	pop();
};

template<class T>
Stack<T>::Stack(): Vector<T>(){
	
}

template<class T>
int Stack<T>::size()const {
	return Vector<T>::size();
}

template<class T>
bool Stack<T>::empty() const {
	return Vector<T>::empty();
}

template<class T>
void Stack<T>::push(T const& e) {
	Vector<T>::insert(e);
}

template<class T>
T Stack<T>::pop() {
	return Vector<T>::remove(Vector<T>::_size - 1);
}