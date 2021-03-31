#include <iostream>
#include <string>

class a
{
	public :
		int x;
};

class b
{
	private:
 	public :
		int y;
		b();
		b(const a &obj);
		b(const b &obj);
		b &operator=(b &obj);
};

b::b(){}
b::b(const a &obj){this->y = obj.x;}
b::b(const b &obj){this->y = obj.y;}

b &b::operator=(b &obj)
{
	this->y = obj.y;
	return (*this);
}

using namespace std;
int main()
{
	a f1; f1.x = 100;
	b f2; f2.y = 200;
	b f3; f3 = f2;
	cout << &f2 << endl;
	cout << &f3 << endl;
	cout << "------------------" << endl;
	cout << f2.y << endl;
	cout << &f2 << endl;
	cout << f3.y << endl;
	cout << &f3 << endl;
	return (1);
}
