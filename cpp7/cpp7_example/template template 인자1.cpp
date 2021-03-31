#include <iostream>
#include <array>

using namespace std;

// template < template < typename A, size_t size > class T>
// std::array의 두번째인자가 size_t임을 정확하게 알아야함.
// 사실상 선언에 가깝기 때문에 인자는 쓰이지 않는다.(함수 선언처럼)
template < template < typename , size_t > class T> // 이렇게 쓰는게 헷갈리지 않을 듯
void test(T <int, 10> & ref)
{
	cout << "test1" << endl;
}
// template<class T, std::size_t N> struct array;

template < typename T, std::size_t N >
void test2(std::array<T, N> & ref)
{
	cout << "test2" << endl;
}

int main()
{
	std::array<int, 10> a= {0,0,0,0,0,0,0,0,0,0};
	int array[3] = {0, 0, 0};

	test(a);
	test<std::array>(a);
	// test<std::array <int, 10> >(a);// error 템플릿에서 언급한 것만 제시하면 됨.

	test2<int, 10>(a);
	test2(a);
	return (1);
}
