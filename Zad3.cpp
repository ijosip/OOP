#include<iostream>
#include<string>
#include<cctype>

int main() {
	std::string s;
	std::getline(std::cin,s);
	//std::cout << "Linija: " << s << '\n';

	for (int n : s)
	{
		if (n == ' ') { std::cout << '_'; continue; }

		else if (n >= 48 && n <= 57) { std::cout << '*'; continue; }

		std::cout << (char)toupper(n);
	}

	std::cout << '\n';
}