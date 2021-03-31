#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	list<int>::iterator p = a.begin();
	for(int i = 0; i < 15; i++)
	{
		cout << *p << endl;
		p++;
	}
	cout << " = = = = = = " << endl;
	list<int>::iterator q = std::find(a.begin(), a.end(), 1000);
	cout << *q << endl;
	q++;
	cout << *q << endl;

	return (1);
}
