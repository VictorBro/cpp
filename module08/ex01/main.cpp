#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main(void)
{
	std::cout << "=== PDF test ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n=== Overflow test ===" << std::endl;
	try {
		sp.addNumber(42);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== Too few elements ===" << std::endl;
	Span one(1);
	one.addNumber(5);
	try {
		std::cout << one.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "shortestSpan: " << e.what() << std::endl;
	}
	try {
		std::cout << one.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "longestSpan: " << e.what() << std::endl;
	}

	std::cout << "\n=== 10000 numbers ===" << std::endl;
	Span big(10000);
	std::srand(std::time(NULL));
	for (int i = 0; i < 10000; i++)
		big.addNumber(std::rand());
	std::cout << "shortest: " << big.shortestSpan() << std::endl;
	std::cout << "longest:  " << big.longestSpan() << std::endl;

	std::cout << "\n=== addRange ===" << std::endl;
	Span ranged(5);
	std::vector<int> vec;
	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);
	vec.push_back(400);
	vec.push_back(500);
	ranged.addRange(vec.begin(), vec.end());
	std::cout << "shortest: " << ranged.shortestSpan() << std::endl;
	std::cout << "longest:  " << ranged.longestSpan() << std::endl;

	std::cout << "\n=== addRange overflow ===" << std::endl;
	try {
		ranged.addRange(vec.begin(), vec.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
