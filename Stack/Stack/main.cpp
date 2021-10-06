#include <iostream>
#include "Stack.h"

int main() {
	Stack<int> s;
	int num = 4095;
	while (num > 0) {
		s.push(num % 2);
		num /= 2;
	}
	while (!s.empty())
		std::cout << s.pop();
}