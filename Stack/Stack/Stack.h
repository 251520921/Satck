#pragma once

#include "Vector.h"

template<class T>
class Stack : protected Vector<T> {
public:
	Stack();
	int size() const;
	bool empty() const;
};

template<class T>
Stack<T>::Stack(): Vector<T>(){
	std::cout << "StackÄ¬ÈÏ¹¹Ôì" << std::endl;
}

template<class T>
int Stack<T>::size()const {
	return Vector<T>::size();
}

template<class T>
bool Stack<T>::empty() const {
	return Vector<T>::empty();
}