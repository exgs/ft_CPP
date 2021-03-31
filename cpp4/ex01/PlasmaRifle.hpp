#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"
#include <iostream>
#include <iomanip>

// using namespace std;

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle();
		PlasmaRifle(std::string name, int apcost, int damage);
		PlasmaRifle(const PlasmaRifle &ref);
		PlasmaRifle &operator=(const PlasmaRifle &ref);
		virtual ~PlasmaRifle();
		void attack() const; //override
};

#endif
