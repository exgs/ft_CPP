#include <iostream>
#include <ctime>
#include <sys/time.h>

using namespace std;

int main()
{
	time_t temp;
	timeval time2;
	gettimeofday(&time2, NULL);
	cout << time2.tv_sec << endl;
	cout << "----" << endl;
	cout << "time(NULL): " << (temp = time(NULL)) << endl;
	srand(temp);
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << "----" << endl;
	cout << "time(NULL): " << (temp = time(NULL)) << endl;
	srand(temp);
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	return (1);
}
