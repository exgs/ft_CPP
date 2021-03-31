#include <iostream>

using namespace std;

// 아래 두 함수는 다르다.
void test(int *i){cout << "void, int" << endl;};
void test(const int *i){cout << "void, const int" << endl;};

// 아래 두 함수는 같다.
void test(int i){cout << "void, int" << endl;};
void test(const int i){cout << "void, const int" << endl;};

int main()
{
	int a = 2;
	int *b = &a;
	const int *c = &a;
	test(b);
	test(c);
	return (1);
}
