#pragma once

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
public:
	Vector(int c = 0, int s = 0, T const& e = 0);

	Rank size() const;
	bool empty() const;


};
template<class T>
Vector<T>::Vector(int c, int s, T const& e) {
	std::cout << "Vector构造" << std::endl;
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