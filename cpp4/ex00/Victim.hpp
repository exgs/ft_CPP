#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <string>

// using namespace std;

class Victim
{
	protected:
		std::string name_;
	public:
		Victim(std::string name = "null");
		Victim(const Victim &ref);
		virtual ~Victim(); //포인터로 가리켰을 때를 대비하여..
		Victim &operator=(const Victim &ref);
		std::string getName() const;
		virtual void getPolymorphed() const; // 상속 받을 것을 알고 있었다고하면, 이렇게 정의해줬을 것 같아.
};

std::ostream &operator<<(std::ostream &os, const Victim &ref); //여기서 값을 이용할 수 있게 get함수 만들자.

#endif
