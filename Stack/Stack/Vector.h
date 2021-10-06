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
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T const& e = 0);

	Rank size() const;
	bool empty() const;

	Rank insert(T const& e, Rank r);
	Rank insert(T const& e);
	int remove(Rank lo, Rank hi);
	T remove(Rank r);
	int clear();
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

template<class T>
Rank Vector<T>::insert(T const& e, Rank r) {
	expand();
	for (int i = _size; i > r; i--)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;
	_size++;
	return r;
}

template<class T>
Rank Vector<T>::insert(T const& e) {
	return insert(e, _size);
}

template<class T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0;
	while (hi < _size) 
		_elem[lo++] = _elem[hi++];
	_size = lo;
	return hi - lo;
}

template<class T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}

template<class T>
int Vector<T>::clear() {
	int oldSize = _size;
	T* oldElem = _elem;
	_elem = new T[_capacity = DEFAULT_CAPACITY];
	delete[] oldElem;
	_size = 0;
	return oldSize;
}