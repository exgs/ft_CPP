#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>
#include <iomanip>

// using namespace std;

class AWeapon // 추상클래스가 되어버려서 더이상 객체를 생성할 수 없는 클래스임.
{
	private :
		int apcost_;
		int damage_;
		std::string name_;
		AWeapon(); // 호출될 수 없는 생성자!
	public:
		AWeapon(const std::string &name, int apcost, int damage); // 세가지 인자를 가져야만 객체를 생성 할 수 있음.
		AWeapon(const AWeapon &ref);
		AWeapon &operator=(const AWeapon &ref);
		virtual ~AWeapon();
		std::string const getName() const; // 반환되자마자 바뀌는 대참사를 막기위해서
		int getAPCost() const;
		int getDamage() const;
		void setName(std::string name);
		void setAPCost(int apcost);
		void setDamage(int damage);
		virtual void attack() const = 0; // 순수 가상 함수

		// 내가 만들어 준 함수
		virtual void showStatus() const; // 가상 함수
};

#endif
