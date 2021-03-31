// dynamic_cast
#include <iostream>
#include <exception>
using namespace std;

class CBase { virtual void dummy() {} };
class CDerived: public CBase
{ int a; };

int main () {
  try {
    CDerived * pd; // 자식

    CBase * pba = new CDerived;
    pd = dynamic_cast<CDerived*>(pba); // 확인작업
    if (pd==0) cout << "Null pointer upcasting" << endl;

    CBase * pbb = new CBase;
    pd = dynamic_cast<CDerived*>(pbb); // 확인작업
    if (pd==0) cout << "Null pointer downcasting" << endl;

  } catch (exception& e) {cout << "Exception: " << e.what();}
  return 0;
}
