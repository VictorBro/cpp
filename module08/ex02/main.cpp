#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "=== MutantStack ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n=== std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\n=== Reverse iterate ===" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	while (rit != mstack.rend())
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "\n=== Copy test ===" << std::endl;
	MutantStack<int> copy(mstack);
	mstack.push(999);
	std::cout << "original top: " << mstack.top() << std::endl;
	std::cout << "copy top: " << copy.top() << std::endl;

	std::cout << "\n=== Const iterate ===" << std::endl;
	const MutantStack<int> cstack(mstack);
	MutantStack<int>::const_iterator cit = cstack.begin();
	while (cit != cstack.end())
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	std::cout << "\n=== Const reverse iterate ===" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = cstack.rbegin();
	while (crit != cstack.rend())
	{
		std::cout << *crit << std::endl;
		++crit;
	}

	return 0;
}
