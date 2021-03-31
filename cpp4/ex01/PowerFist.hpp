#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"
#include <iostream>
#include <iomanip>

// using namespace std;

class PowerFist : public AWeapon
{
	public:
		PowerFist();
		PowerFist(std::string name, int apcost, int damage); // 세가지 인자를 가져야만 객체를 생성 할 수 있음.
		virtual ~PowerFist();
		PowerFist(const PowerFist &ref);
		PowerFist &operator=(const PowerFist &ref);
		void attack() const; //override
};

#endif
