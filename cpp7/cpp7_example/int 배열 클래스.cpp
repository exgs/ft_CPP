#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
	int array[5] = {0,1,2,3,4};
	std::array<int, 5> array1 = {0,1,2,3,4};
	// cout << array.size() << endl; 그냥 배열에는 크기를 담아 줄 수 없음
	cout << array1.size() << endl;
	// 메소드가 많은 것으로 보아, 리스트처럼 구현됬다고 보임.
	return (1);
}
