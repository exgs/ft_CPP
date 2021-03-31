#include<iostream>
using namespace std;
 
int main(void){
    int tmp = 15;
    const int &ref = tmp;
    cout << "before : " << tmp << endl;
 
    // ref = 20; == > error;
 
    int & r = const_cast<int &>(ref);
    r = 30;
    cout << "after : " << tmp << endl;
 
    return 0;
}

// 출처: https://blockdmask.tistory.com/240 [개발자 지망생]
