#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

// using namespace std;

class AMateria
{
	private:
		std::string _type;
		unsigned int _xp;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(std::string const &type, unsigned int const &xp);
		AMateria(AMateria const &); // 추상클래스는 객체를 만들 수 없으므로, 만들어질 일이 없다.
		AMateria &operator=(AMateria const &);
		virtual ~AMateria();
		std::string const & getType() const;
		unsigned int getXP() const;
		void setType(std::string const &);
		void setXP(unsigned const int &);
		virtual AMateria* clone() const = 0; // 아마도 AMateria를 상속받는 자식의 클론 생성
		virtual void use(ICharacter& target);
};
#endif
