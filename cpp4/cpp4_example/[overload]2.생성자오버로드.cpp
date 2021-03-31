# include <iostream>
using namespace std;

class Enemy
{
protected:
	std::string	type_;

public:
	Enemy()
	: type_("default"){}

	//1번
	Enemy(std::string type)
	: type_(type){cout << "std::string" << endl;
	cout << "string a"        	<< &type	<< endl;}

	//2번
	// Enemy(const std::string type)
	// : type_(type){cout << "const std::string" << endl;
	// cout << "const string b"  	<< &type	<< endl;}

	// 3번
	// Enemy(std::string &type)
	// : type_(type){cout << "std::string &type" << endl;
	// cout << "string &c"       	<< " : " << &type	<< endl;}

	//4번
	// Enemy(std::string const &type)
	// : type_(type){cout << "std::string const &type" << endl;
	// cout << "const string &d" 	<< " : " << &type	<< endl;}
};

/*1, 2*/
// 1번. const인 경우에도 값 복사하면, 변경되도 상관없기 때문에 가능하다.
// 2번. const러 각각의 값이 초기화 된다. 변경될 여지가 없는 변수로 받는다는 이야기

int main()
{
	string a = "sdfdsfds";
	const string b = "sdfdsfds";
	string &c = a;
	const string &d = b;


	cout << "string a"        << " : "	<< &a	<< endl;
	cout << "const string b"  << " : "	<< &b	<< endl;
	cout << "string &c"       << " : "	<< &c	<< endl;
	cout << "const string &d" << " : "	<< &d	<< endl;
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	Enemy test0(a);
	Enemy test1(b);
	Enemy test2(c);
	Enemy test3(d);

	return (0);
}
