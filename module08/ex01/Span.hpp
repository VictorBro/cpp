#pragma once

#include <vector>
#include <limits>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
	unsigned int _max;
	std::vector<int> _data;
	int _maxNum;
	int _minNum;
	unsigned int _minDiff;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);

	template <typename InputIterator>
	void addRange(InputIterator begin, InputIterator end)
	{
		for (InputIterator it = begin; it != end; ++it)
			addNumber(*it);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};
