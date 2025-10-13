#include <iostream>

void fun(int a) {
	int low = -5, high = 5;
	if (a < low) 	std::cout << low << '\n';
	else if (a > high) 	std::cout << high << '\n';
	else 	std::cout << a << '\n';
}

void fun(double a) {
	int low = -5, high = 5;
	if (a < low) 	std::cout << low << '\n';
	else if (a > high) 	std::cout << high << '\n';
	else 	std::cout << a << '\n';
	}

int main2() {
	int n;
	std::cout << "Unesi n: " << std::endl;
	std::cin >> n;
	std::cout << n << '\n';
	fun(n);
	return 0;
	}

