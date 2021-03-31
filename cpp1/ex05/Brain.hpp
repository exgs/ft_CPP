#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>
// using namespace std;

class Brain
{
	private :
		int _iq;
		int _eq;
		int _scale;
	public :
		Brain(int iq = 100, int eq = 100, int scale = 100);
		~Brain();
		Brain(const Brain&);
		Brain &operator=(const Brain &);
		void setiq(int iq);
		void seteq(int eq);
		void setscale(int scale);
		//get함수는 const로 만들어도 부담없잖아
		int getiq() const;
		int geteq() const;
		int getscale() const;
		std::string identify() const;
};

#endif
