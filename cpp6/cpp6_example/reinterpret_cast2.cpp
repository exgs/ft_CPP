#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int* p = new int(200);
	long c = reinterpret_cast<long> (p);
	cout << "c : " << c << endl;
	char *i = reinterpret_cast<char *>(p);
	cout << "i : " << (long)i << endl;

	int* temp1 = reinterpret_cast<int *>(c);
	int* temp2 = reinterpret_cast<int *>(i);
	cout << "temp2 : " << (long)temp2 << endl;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

	// char abc = reinterpret_cast<char>(p); // 큰거에서 작은거는 안됨 8byte -> 1byte
	int e;
	int *cba = reinterpret_cast<int *>(e); // 작은거에서 큰거는 됨 4byte -> 8byte
	return 0;
}
