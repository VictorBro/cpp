#include <iostream>
#include <string>
#include <cstddef>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

void increment(int &x)
{
	x++;
}

void toUpper(std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = std::toupper(s[i]);
}

int main(void)
{
	std::cout << "=== int array ===" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	::iter(arr, 5, print<int>);

	std::cout << "\n=== increment ===" << std::endl;
	::iter(arr, 5, increment);
	::iter(arr, 5, print<int>);

	std::cout << "\n=== string array ===" << std::endl;
	std::string strs[] = {"hello", "world", "foo"};
	::iter(strs, 3, print<std::string>);

	std::cout << "\n=== toUpper ===" << std::endl;
	::iter(strs, 3, toUpper);
	::iter(strs, 3, print<std::string>);

	std::cout << "\n=== const array ===" << std::endl;
	int const carr[] = {10, 20, 30};
	::iter(carr, 3, print<int>);

	return 0;
}
