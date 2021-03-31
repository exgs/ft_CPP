#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Vector
{
	T *data;
	int capacity;
	int length;

	public:
		Vector(int n = 1) : data(new T[n]), capacity(n), length(0){}
		~Vector(){if (data){delete[] data;}};
		void push_back(T s);
		void remove(int x);
		int size(){return length;};
		T operator[](int i) {return data[i];};
};

template <typename S>
void Vector<S>::push_back(S s)
{
	if (this->capacity <= this->length)
	{
		S *temp = new S [capacity * 2];
		for (size_t i = 0; i < this->length; i++)
			temp[i] = this->data[i];
		delete []this->data;
		this->data = temp;
		this->capacity *= 2;
	}
	this->data[this->length] = s;
	this->length++;
}

template <typename T>
void Vector<T>::remove(int x)
{
	if (x >= length)
		return;
	else
	{
		for (size_t i = x; i < this->length; i++)
		{
			this->data[i] = this->data[i+1];
		}
	}
	this->length--;
}

int main()
{
  // int 를 보관하는 벡터를 만든다.
  Vector<int> int_vec;
  int_vec.push_back(3);
  int_vec.push_back(2);

  std::cout << "-------- int vector ----------" << std::endl;
  std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

  Vector<std::string> str_vec;
  str_vec.push_back("hello");
  str_vec.push_back("world");
  std::cout << "-------- std::string vector -------" << std::endl;
  std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << str_vec[1] << std::endl;
}
