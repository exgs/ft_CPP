#include "Replace.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (error(ERROR_ARGC));
	string filename = argv[1];
	string s1		= argv[2];
	string s2		= argv[3];
	if (filename.size() == 0 || s1.size() == 0 || s2.size() == 0)
		return (error(ERROR_EMPTY_STRING));
	
	ifstream file_read;
	ofstream file_write;
	file_read.open(filename);
	if (file_read.is_open() == FALSE)
		return (error(ERROR_FILE_DOES_NOT_EXIST));
	else
	{
		filename.append(".replace");
		file_write.open(filename);
	}
	string temp;
	
	while (file_read.eof() == FALSE)
	{
		std::getline(file_read, temp);
		temp = ReplaceAll(temp, s1, s2);
		// cout << temp << endl;
		file_write.write(temp.c_str(), temp.size());
		if (file_read.eof() == FALSE)
			file_write.write("\n", 1);
	}
	file_write.close();
	file_read.close();
	return (1);
}
	// cout << filename << endl;
	// cout << s1 << endl;
	// cout << s2 << endl;
	// cout << "=================" << endl;
