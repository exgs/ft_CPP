#include <iostream>
#include <exception>

using namespace std;

class A
{
	public:
		A()
		{
			cout << "created" << endl;
			throw std::bad_alloc();
		}
		~A()
		{
			cout << "destroyed" << endl; // 호출이 되지 않는다.
		}
};

int main()
{
	A a;
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (1);
}
