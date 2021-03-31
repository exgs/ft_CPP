// 논리적으로 변환 가능한 타입을 변환한다
// 포인터 타입을 다른 것으로 변환하지 못함
// 상속 관계에 있는 포인터끼리 변환 가능

// downcasting에서는 dynamic_cast를 사용하라고 권고

#include<iostream>
using namespace std;
int main(void)
{
	double d = 13.24;
	float f = 10.12f;
	double tmp_double;
	int tmp_int;
	float tmp_float;
	char tmp_char;

	tmp_int = static_cast<int>(d); //double -> int 로 형변환
	cout << "static_cast<int>(double) : " << tmp_int << endl;

	tmp_float = static_cast<float>(d); //double -> float 로 형변환
	cout << "static_cast<float>(double) : " << tmp_float << endl;

	tmp_double = static_cast<double>(f); //float -> double 로 형변환
	cout << "static_cast<double>(float) : " << tmp_double << endl;

	tmp_char = static_cast<char>(f); //float -> char 로 형변환
	cout << "static_cast<char>(float) : " << tmp_char << endl;

	return 0;
}

// 출처: https://blockdmask.tistory.com/236?category=249379 [개발자 지망생]
