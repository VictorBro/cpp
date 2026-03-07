#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
	std::cout << "=== vector ===" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 3);
	try {
		std::vector<int>::iterator it = easyfind(vec, 9);
		std::cout << "Found " << *it << " at index " << (it - vec.begin()) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(vec, 42);
	} catch (std::exception &e) {
		std::cout << "42: " << e.what() << std::endl;
	}

	std::cout << "\n=== list ===" << std::endl;
	std::list<int> lst;
	for (int i = 0; i < 5; i++)
		lst.push_back(i + 10);
	try {
		std::list<int>::iterator it = easyfind(lst, 12);
		std::cout << "Found " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(lst, 99);
	} catch (std::exception &e) {
		std::cout << "99: " << e.what() << std::endl;
	}

	std::cout << "\n=== deque ===" << std::endl;
	std::deque<int> deq;
	for (int i = 0; i < 5; i++)
		deq.push_back(i * 7);
	try {
		std::deque<int>::iterator it = easyfind(deq, 21);
		std::cout << "Found " << *it << " at index " << (it - deq.begin()) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(deq, -1);
	} catch (std::exception &e) {
		std::cout << "-1: " << e.what() << std::endl;
	}

	return 0;
}
