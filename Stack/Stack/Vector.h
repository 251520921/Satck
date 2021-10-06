#pragma once

#define DEFAULT_CAPACITY 16
using Rank = int;

template<class T>
class Vector {
private:
	T* _elem;		//数据区
protected:
	Rank _size;		//大小
	Rank _capacity;	//规模
private:
	void expand();		//扩容
	void shrink();		//缩容
public:
	Vector(int c = 0, int s = 0, T const& e = 0);

	Rank size() const;
	bool empty() const;

};

template<class T>
void Vector<T>::expand() {
	if (_size < _capacity) return;
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}

template<class T>
void Vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY) return;
	if (_size << 2 > _capacity) return;
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}

template<class T>
Vector<T>::Vector(int c, int s, T const& e) {
	_elem = new T[_capacity = c];
	for (int i = 0; i < s; i++)
		_elem[i] = e;
}

template<class T>
Rank Vector<T>::size() const {
	return _size;
}

template<class T>
bool Vector<T>::empty() const {
	return !_size;
}