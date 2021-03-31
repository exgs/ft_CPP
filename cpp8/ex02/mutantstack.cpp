#ifndef MUTANTSTACK_CPP
# define MUTANTSTACK_CPP

#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{
   
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &other)
	: std::stack<T>(other)
{

}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &other)
{
	MutantStack<T>::stack.operator=(other);
	this->iterator = other.iterator;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	typename std::deque<T> container;
	iterator ret =  container.end();
	return (ret);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	typename std::deque<T> container;
	iterator ret =  container.begin();
	return (ret);
}

#endif
