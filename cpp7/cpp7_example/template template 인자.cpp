#include <iostream>
#include <list>

// list는 다음과 같이 선언되어 있습니다
// namespace std
// {
// template <typename T, typename Allocator = allocator<T> > class list;
// }
// 즉 템플릿 파라미터가 2개 입니다

template <typename T1,
			typename T2,
			template<typename T, typename = std::allocator<T> > class Container > //A 부분
// Container 1개의 템플릿 파라미터를 갖는 템플릿 템플릿 파라미터
class Relation
{
public :
//...
private :
	Container<T1> dom1;
	Container<T2> dom2;
};


template < template < typename T, typename = std::allocator<T> > class Container >
void test()
{
	std::cout << "hello" << std::endl;
}

template < template < typename T, typename = std::allocator<T> > class Container >
void test(Container<int, std::allocator<int> > a)
{
	std::cout << "hello2" << std::endl;
}

int main()
{
	std::list <int> a;
	Relation< int, double, std::list > rel; //B부분
	// test<std::list <int> >(); // error가 남.
	test<std::list>();
	test<std::list>(a);
	//에러 std::list는 하나 이상의 템플릿 파라미터 가짐
}
