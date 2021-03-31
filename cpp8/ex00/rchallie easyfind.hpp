# include <iostream>
# include <algorithm>
using namespace std;

class NotFound : public std::exception
{
    virtual const char* what() const throw() { return ("Not found."); }
};

template < template < typename , typename> class T>
typename T<int, std::allocator<int> >::iterator
    easyfind(T<int, std::allocator<int> > &array, int n)
{   
    typename T<int, std::allocator<int> >::iterator itpos;
    if ((itpos = std::find(array.begin(), array.end(), n)) != array.end())
        return (itpos);
    else
        throw NotFound();
}


template < template < typename , typename> class T>
typename T<std::string, std::allocator<std::__1::basic_string<char> > >::iterator
    easyfind(T<std::string, std::allocator<std::__1::basic_string<char> > > &array, int n)
{   
    std::cout << "string container" << std::endl;
}

