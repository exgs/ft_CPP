//참고로, 함수에 noexcept 키워드를 붙였다고 해서, 함수가 예외를 절대로 던지지 않는다는 것은 아닙니다.
// 대신 noexcept 로 명시된 함수가 예외를 발생시키게 된다면 예외가 제대로 처리되지 않고 프로그램이 종료됩니다. 

#include <iostream>

int noerror() _NOEXCEPT {} // throw() 랑 같음

int yeserror() _NOEXCEPT
{
	throw 1;
}

int main() {
	noerror();
	try
	{
		yeserror();
	}
	catch (int x)
	{
		std::cout << "Error : " << x << std::endl;
	}
}
