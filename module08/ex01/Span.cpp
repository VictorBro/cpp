#include "Span.hpp"

Span::Span()
	: _max(0)
	, _maxNum(std::numeric_limits<int>::min())
	, _minNum(std::numeric_limits<int>::max())
	, _minDiff(std::numeric_limits<unsigned int>::max()) {}

Span::Span(unsigned int n)
	: _max(n)
	, _maxNum(std::numeric_limits<int>::min())
	, _minNum(std::numeric_limits<int>::max())
	, _minDiff(std::numeric_limits<unsigned int>::max()) {}

Span::Span(const Span &other)
	: _max(other._max)
	, _data(other._data)
	, _maxNum(other._maxNum)
	, _minNum(other._minNum)
	, _minDiff(other._minDiff) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_max = other._max;
		_data = other._data;
		_maxNum = other._maxNum;
		_minNum = other._minNum;
		_minDiff = other._minDiff;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_data.size() >= _max)
		throw std::overflow_error("Span is full");
	if (number > _maxNum)
		_maxNum = number;
	if (number < _minNum)
		_minNum = number;
	_data.push_back(number);
	size_t i = _data.size() - 1;
	while (i > 0 && _data[i] < _data[i - 1])
	{
		std::swap(_data[i], _data[i - 1]);
		i--;
	}
	if (i > 0)
		_minDiff = std::min(_minDiff, static_cast<unsigned int>(_data[i] - _data[i - 1]));
	if (i < _data.size() - 1)
		_minDiff = std::min(_minDiff, static_cast<unsigned int>(_data[i + 1] - _data[i]));
}

unsigned int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw std::logic_error("Not enough elements for a span");
	return _minDiff;
}

unsigned int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw std::logic_error("Not enough elements for a span");
	return static_cast<unsigned int>(_maxNum - _minNum);
}
