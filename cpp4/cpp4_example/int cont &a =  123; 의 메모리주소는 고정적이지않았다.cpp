#include <iostream>
using namespace std;
int main()
{
	int const &b = 123;
	int const &c = 123;
	int const &d = 123;
	// int &f = 123; //Error: r value를 non-const로 담으려다보니
	int e = 123;

	cout << "b : " << &b << endl;
	cout << "c : " << &c << endl;
	cout << "d : " << &d << endl;
	// cout << "f : " << &f << endl;
	cout << "e : " << &e << endl;

	// r-value는 const로 담을 수 있다는 점에서, 특정 위치에 정적으로 존재하는 줄 알았으나,
	// int const & 메모리 주소를 출력해보니, 매번 다른 위치에 할당 되는 것 같다.
	return (1);
}
