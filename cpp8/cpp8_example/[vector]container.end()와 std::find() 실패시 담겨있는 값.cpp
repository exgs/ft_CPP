#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);

	vector<int>::iterator p = a.begin();
	for(int i = 0; i < 15; i++)
	{
		cout << *p << endl;
		p++;
	}
	cout << " = = = = = = " << endl;
	vector<int>::iterator q = std::find(a.begin(), a.end(), 1000);
	cout << *q << endl;
	q++;
	cout << *q << endl;

	return (1);
}
