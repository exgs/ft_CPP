// 포인터 또는 참조형의 const 성질을 무시하는 캐스팅
// 다른 캐스트 연산자가 하는 형변환 불가능, 오직 상수성 제거에만 사용됨.
#include <iostream>

using namespace std;

int main(void){
    char str[] = "BlockDMask";
    const char * ptr = str;
    cout << "before : " << str << endl;
 
    // ptr[0] = 'Q';// ==> error
 
    char * c = const_cast<char *>(ptr);
    c[0] = 'Q';
    cout << "after : " << str << endl;
	c[1] = 'Q';
    cout << "after : " << str << endl;
 
    return 0;
}
// 출처: https://blockdmask.tistory.com/240 [개발자 지망생]
