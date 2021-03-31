#include <iostream>
using namespace std;

class A
{
	private:
		int a_;
	public :
		int geta(){return (a_);}
		void seta(int a){a_ = a;}
		void geta_object(A &temp)
		{
			cout << temp.a_ << endl;
		}
};

int main()
{	
	A a;
	a.seta(40);

	A b;
	b.geta_object(a);
	b.seta(23);
	b.geta_object(b);

	return (1);
}
