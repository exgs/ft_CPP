#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private :
		std::string name_;
		int inventory_num;
		AMateria *inventory[4]; // clone에서 리턴한거 쓸려면, 포인터 형식이 맞는 듯.
	public:
		Character(std::string name = "null");
		Character(Character &ref);
		virtual ~Character();
		Character &operator=(Character &ref);

		//
		int getInventory_num() const;
		void delete_inventory_all(AMateria *inventory[4]);
		void init_inventory_all(AMateria *inventory[4]);

		// 순수 가상함수
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
