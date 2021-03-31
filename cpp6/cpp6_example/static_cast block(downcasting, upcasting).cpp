# include <iostream>
# include <cstdio>
using namespace std;
 
class shape{
private:
    int a;
public:
    virtual void draw(){
        cout << "shape : called draw()" << endl;
    }
};
 
 
class triangle : public shape{
private:
    int b;
public:
    triangle(){
        b = 30;
    }
    void draw(){
        cout << "triangle : called draw()" << endl;
    }
 
    void onlyTriangle(){
        cout << "triangle : onlyTriangle()" << endl;
        cout << b << endl; // 비정상적인 결과
    }
};
 
 
int main(void){
 
    //1.upcast
    shape *ps;  //부모 클래스 타입 포인터
    triangle t; //자식 클래스 인스턴스
    ps = static_cast<shape *>(&t);
    cout << "//1. upcasting //\n";
    ps->draw();
 
 
    //2.downcast
    shape s;        //부모 클래스 인스턴스
    triangle *pt;   //자식 클래스 타입 포인터
    cout << "\n//2. downcast //\n";
    // pt = static_cast<triangle *>(&s);
    pt = (triangle *)(&s); // 동일
    pt->draw();
	// 부모클래스의 draw()함수가 virtual(O) -> 부모의 draw()가 작성됨. // shape객체가 생성될 때, vtable이 생성됨.
	// 부모클래스의 draw()함수가 virtual(X) -> 자식의 draw()가 작성됨. // shape객체가 생성될 때, vtable이 생성되지않음. 따라서 자료형 따라 멤버함수가 호출됨.
	triangle t1;
	t1.draw();


    pt->onlyTriangle();
    //허용은 된다. but, 자식 클래스의 멤버 함수를 부르면 예상값과 다르게 나온다.
    //부모 클래스 인스턴스가 자식멤버함수를 부르는 것이 비 정상적인 결과를 초래할 수 있다
 
}
// 출처: https://blockdmask.tistory.com/236?category=249379 [개발자 지망생]
