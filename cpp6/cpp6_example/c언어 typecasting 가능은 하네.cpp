// class type-casting
#include <iostream>
using namespace std;

class CDummy
{
	float i,j;
};

class CAddition {
  public:
	int x,y;
	CAddition (int a, int b) { x=a; y=b; }
	int result() { return x+y;}
};

int main () {
  CDummy d;
  CAddition *padd;
  padd = (CAddition*) &d; // 주석처리하면, segfault error/ 공간은 필요하다는 사실을 알 수 있다.
  padd->x = 21;padd->y = 41;
  cout << padd->result(); // 멤버함수가 아닌 것을 불러오고있음.
  // 다만 함수의 경우에는 객체에 저장되는 것이 아니라 코드영역에 저장되는 것.
  
  // The subsequent call to member result will produce either a run-time error or a unexpected result.
  return 0;
}
