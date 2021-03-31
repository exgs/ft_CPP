#ifndef ARRAY_CPP
# define ARRAY_CPP
# include "Array.hpp"

template <typename T>
Array<T>::Array() :
	array(new T[0]), size_(0) // new T[0] or NULL
{

}

template <typename T>
Array<T>::Array(Array const &ref) : // 깊은 복사.
	size_(ref.size_)
{
	if (this->size_ == 0)
		this->array = new T[0];
	else
	{
		this->array = new T[this->size_];
		for (unsigned int i = 0; i < this->size_; i++)
		{
			this->array[i] = ref.array[i];
		}
	}
}

template <typename T>
Array<T>::Array(unsigned int n) :
	size_(n)
{
	this->array = new T[n]; // 값 할당을 안해도, new를 하면, 0으로 값이 들어감
}

template <typename T>
Array<T>::~Array()
{
	delete []this->array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &ref)
{
	if (this == &ref)
		return (*this);
	delete [](this->array);
	this->size_ = ref.size_;
	if (this->size_ == 0)
		this->array = new T[0];
	else
	{
		this->array = new T[this->size_];
		for (unsigned int i = 0; i < this->size_; i++)
		{
			this->array[i] = ref.array[i];
		}
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](int i)
{
	if (i >= (int)this->size_ || i < 0)
		throw ArrayException();
	else
		return ((T &)this->array[i]);
}

template <typename T>
T &Array<T>::operator[](size_t i)
{
	if (i >= this->size_)
		throw ArrayException();
	else
		return ((T &)this->array[i]);
}

template <typename T>
const char *Array<T>::ArrayException::what() const _NOEXCEPT
{
	return ("Array Exception");
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->size_);
}
#endif
