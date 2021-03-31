#include <math.h>
#include <float.h>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	
	double d;
	d = atof("23232141241213213124343223232141241213213124343243243242141242142131312321321312312312123901409134120942109402194092147019247091274092323214124121321312434324324324214124214213131232132131231231212390140913412094210940219409214701924709127409909019247109");
	float f = FLT_MAX;
	// if (f > d)
	// 	cout << "hello" <<endl;
	cout << d << endl;
	cout << f << endl;
	double a = FLT_MAX * 10;
	// cout << a << endl;

	double b = FLT_MAX;
	b = std::numeric_limits<double>::infinity();
	// b = -std::numeric_limits<double>::infinity();
	if (a == b)
		cout << "good" << endl;
	float c = FLT_MAX;
	cout << b << endl;
	cout << c << endl;
	cout << " - - - - -- - - -" << endl;
	float ab = 100.2f;
	char abc = static_cast<char>(ab);
	cout << abc << endl;
	return (1);
}
