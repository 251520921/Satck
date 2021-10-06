#include <iostream>
#include "Stack.h"

int main() {
	Stack<int> s;
	std::cout << s.empty();
	Vector<int> v;
	v = s;
}