#include<iostream>
#include<cstdio>
using namespace std;
 
enum E_VAL {A=11, B, C};
 
int main(void)
{
    E_VAL e = A;
    cout << "E_VAL : " << e << endl;
 
    int a;
    a = static_cast<int>(e);
    cout << "1. static_cast<int>(enum) : " << a << endl;
 
    int b;
    b = static_cast<int>(B);
    cout << "2. static_cast<int>(enum) : " << b << endl;
 
    E_VAL e2;
    e2 = static_cast<E_VAL>(13); // 명시해줘야함.
    cout << "3. static_cast<enum>(int) : " << e2 << endl;
 
    return 0;
}
// 출처: https://blockdmask.tistory.com/236?category=249379 [개발자 지망생]
