#include "Replace.hpp"

std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0; //string처음부터 검사
    while((start_pos = str.find(from, start_pos)) != std::string::npos)  //from을 찾을 수 없을 때까지
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // 중복검사를 피하고 from.length() > to.length()인 경우를 위해서
    }
    return str;
}


int error(int error_num)
{
	std::string error_message_array[] = {
		"정상 동작", // 0
		"에러", // 1
		"아규먼트를 3개만 넣어주세요", // 2
		"빈 문자열 입니다.", // 3
		"파일이 존재하지 않습니다." // 4 
    };
	if (error_num == 0)
	    std::cout << error_message_array[error_num] << std::endl;
	else
    	std::cout << "Error : " << error_message_array[error_num] << std::endl;
    return (error_num);
}

