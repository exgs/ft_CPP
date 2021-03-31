#include <iostream>
using namespace std;
int main()
{
	std::string str = "str";
	std::string str1 = "str1";
	std::string str2 = "str2";

	cout << str.compare("str") << endl; //0
	cout << str.compare("str1") << endl;  //-1
	cout << str.compare("str2") << endl; //-1

	cout << str1.compare("str") << endl; //1
	cout << str1.compare("str1") << endl;  // 0
	cout << str1.compare("str2") << endl; // -1

	cout << str2.compare("str") << endl; // 1
	cout << str2.compare("str1") << endl;  // 1
	cout << str2.compare("str2") << endl; // 0

	// 0이면 일치, 나머지 정수면 불일치!
	return (1);
}
