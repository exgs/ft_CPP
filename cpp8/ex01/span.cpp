#include "span.hpp"

span::span() :
	max_size_(0), size_(0)
{

}

span::span(unsigned int max_size) :
	max_size_(max_size), size_(0)
{

}

span::span(span& ref) //ref.list_.begin()이 ref를 변경시킨다고 생각함
{
	this->max_size_ = ref.max_size_;
	this->size_ = ref.size_;
	std::list<int>::iterator i = this->list_.begin();
	std::list<int>::iterator j = ref.list_.begin(); 

	while (j != ref.list_.end())
	{
		*i = *j;
		i++;
		j++;
	}
}

span::~span()
{

}

span &span::operator=(span& ref) // const로 하는 방법이 없음
{
	if (this == &ref)
		return (*this);
	if (this->max_size_ < ref.max_size_)
		throw maxSizeException();
	this->max_size_ = ref.max_size_;
	this->size_ = ref.size_;
	std::list<int>::iterator i = this->list_.begin();
	std::list<int>::iterator j = ref.list_.begin();
	while (j != ref.list_.end())
	{
		*i = *j;
		i++;
		j++;
	}
	return (*this);
}

void span::addNumber(int n)
{
	if (this->size_ >= this->max_size_)
		throw maxSizeException();
	this->size_++;
	this->list_.push_back(n);
	this->list_.sort();
	this->list_.reverse();
}

void span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	if (this->size_ + std::distance(begin, end) > this->max_size_)
		throw maxSizeException();
	this->list_.insert(list_.end(), begin, end);  // _v에 begin부터 end까지의 원소를 다넣음
}

unsigned int span::shortestSpan()
{
	if (this->size_ <= 1)
		throw noNumberstored();
	long min;
	long temp;
	long before;
	long after;
	unsigned int i = 0;
	std::list<int>::iterator it = this->list_.begin();
	before = *it;
	after = *(++it);
	min = before - after; i++;
	// std::cout << "size: "<< this->size_ << std::endl;
	while (i < this->size_ - 1)
	{
		before = *it;
		after = *(++it);
		temp = before - after;
		if (min > temp)
			min = temp;
		i++;
	}
	if (min > 4294967295)
	{
		std::cout << "min value : " << min << std::endl;
		throw overFlowException();
	}
	return ((unsigned int)min);
}

unsigned int span::longestSpan()
{
	if (this->size_ <= 1)
		throw noNumberstored();
	std::list<int>::iterator begin = this->list_.begin();
	std::list<int>::iterator end = this->list_.end();
	long max;
	long before;
	long after;
	before = *begin;
	after = *(--end);
	max = before - after;
	if (max > 4294967295)
	{
		std::cout << "max value : " << max << std::endl;
		throw overFlowException();
	}
	return ((unsigned int)max);
}


const char *span::addNumberException::what() const _NOEXCEPT
{
	return ("add Number Exception");
}

const char *span::maxSizeException::what() const _NOEXCEPT
{
	return ("max Size Exception");
}

const char *span::overFlowException::what() const _NOEXCEPT
{
	return ("overFlow Exception");
};

const char *span::noNumberstored::what() const _NOEXCEPT
{
	return ("no Number stored");
};
