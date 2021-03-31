// ikpil.com or ikpil.tistory.com
#include <iostream>
#include <vector>

template <typename _T>	// class _T 와 같은 의미
class babo
{
public:
	void Draw( void )
	{
		std::cout << sizeof(p) << "의 용량을 가진 클래스" <<std::endl;
	}
private:
	_T *p;
public:
	typename _T::iterator muhaha; // typename 작성해주기!
};

template < template < typename, typename > class _T >	// class _T 와 같은 의미
class babo2
{
public:
	void Draw( void )
	{
		std::cout << sizeof(p) << "의 용량을 가진 클래스" <<std::endl;
	}
private:
	_T<int, std::allocator<int> > *p; // typename을 써줘야 함.
public:
	typename _T<int, std::allocator<int> >::iterator muhaha;
};

int main( void )
{
	babo<std::vector<int> > Test;
	Test.Draw();	

	babo2<std::vector> Test2; // 여기선 인자를 안 넣어준다는게 내부적으로 정의되어있음 28,30줄
	Test2.Draw();	
	return 0;
}
