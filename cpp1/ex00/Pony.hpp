#ifndef PONY_HPP
# define PONY_HPP
# include <string>
# include <iostream>
// using namespace std;
class Pony
{
	private:
		std::string	_name;
		int			_height;
		int			_weight;
	public :
		void set_name(std::string name);
		void set_height(int height);
		void set_weight(int weight);
		std::string get_name();
		int get_height();
		int get_weight();
		Pony();
		Pony(std::string name, int height, int weight);
		~Pony();
		void print_pony();
};


void ponyOnTheHeap();
void ponyOnTheStack();

#endif
