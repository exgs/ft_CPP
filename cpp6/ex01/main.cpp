#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <string>

// using namespace std;

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

void *serialize(void)
{
	char alphabets[27] = "abcdefghigklmnopqrstuvwxyz"; //26
	int count = 8;
	std::string *temp1; int temp2; std::string *temp3; char *ret;
	temp1 = new std::string; temp3 = new std::string; ret = new char[24 + 4 + 24];

	for (int i = 0; i < count; i++)
	{
		temp1->append(alphabets[rand() % 26], 1);
		temp3->append(alphabets[rand() % 26], 1);
	}
	std::string *temp;
	temp = reinterpret_cast<std::string*>(ret);
	*temp = *temp1;
	temp = reinterpret_cast<std::string*>(ret + 28);
	*temp = *temp3;

	
	temp2 = static_cast<int>(rand());
	// memcpy(ret + 8, &temp2, 4);
	int *temp_int = reinterpret_cast<int *>(ret + 24);
	*temp_int = temp2;

	/* 테스트 */
	std::cout << temp1 << std::endl;
	std::cout << temp2 << std::endl;
	std::cout << temp3 << std::endl;
	//
	delete temp1;
	delete temp3;
	return reinterpret_cast<void *>(ret);
}

Data *deserialize(void *raw)
{
	Data *data = new Data;
	int i = 0;
	std::string *temp;
	temp = reinterpret_cast<std::string *>(raw);
	data->s1 = *temp;
	temp = reinterpret_cast<std::string *>(raw + 28);
	data->s2 = *temp;
	int *temp_int = reinterpret_cast<int *>(raw + 24);
	data->n = *temp_int;
	return (reinterpret_cast<Data *>(data));
}

int main()
{
	srand(time(NULL));
	void *result;
	Data *data;
	result = serialize();
	// std::cout << result << std::endl;
	data = deserialize(result);
	std::cout << "--------------" << std::endl;
	std::cout << "data->s1 : "<< data->s1 << std::endl;
	std::cout << "data->n  : "<< data->n << std::endl;
	std::cout << "data->s1 : "<< data->s2 << std::endl;

	delete (char *)result;
	delete (Data *)data;
	return 0;
}
