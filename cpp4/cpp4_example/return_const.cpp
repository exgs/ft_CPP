#include <iostream>

using namespace std;

class A
{
	public:
		string name;
		const string return_value(){return name;};
};



int main()
{
	A object;
	object.name = "what should i do";
	string a;
	int size;
	// a = (object.return_value()).append("sdfsd"); //error occured
	// cout << a << endl;
	// object.return_value()++; //error occured
	
	// size는 const에 걸릴까? -> 안 걸림
	size = (object.return_value()).size(); 
	cout << size << endl;
	return (0);
}
