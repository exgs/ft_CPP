#include "Character.hpp"

Character::Character(std::string name) :
	name_(name), inventory_num(0)
{
	init_inventory_all(this->inventory);
}

Character::Character(Character &ref) :
	name_(ref.name_), inventory_num(ref.inventory_num)
{
	int count = 4;
	for (int i = 0; i < count; i++)
	{
		if (ref.inventory[i] != NULL)
			this->inventory[i] = ref.inventory[i]->clone(); // clone을 잘 정의해야할 듯
		else
			this->inventory[i] = NULL;
	}
	// delete_inventory_all(ref.inventory);
	// init_inventory_all(ref.inventory);
	// ref.inventory_num = 0;
}

Character::~Character()
{
	delete_inventory_all(this->inventory);
	init_inventory_all(this->inventory);
}

Character &Character::operator=(Character &ref)
{
	if (this == &ref)
		return (*this);
	int count = 4;
	for (int i = 0; i < count; i++)
	{
		if (ref.inventory[i] != NULL)
			this->inventory[i] = ref.inventory[i]->clone(); // clone을 잘 정의해야할 듯
		else
			this->inventory[i] = NULL;
	}
	name_ = ref.name_;
	inventory_num = ref.inventory_num;
	// delete_inventory_all(ref.inventory);
	// init_inventory_all(ref.inventory);
	// ref.inventory_num = 0;
	return (*this);
}

std::string const & Character::getName() const{return (this->name_);}
int Character::getInventory_num() const{return (this->inventory_num);}

void Character::equip(AMateria* m)
{
	if (this->inventory_num >= 4)
	{
		delete m;
		return ;
	}
	else if (this->inventory_num == 4)
	{
		for (int i = 0; i < this->inventory_num - 1; i++)
		{
			this->inventory[i] = this->inventory[i + 1];
		}
		this->inventory[this->inventory_num - 1] = m;
	}
	else
	{
		this->inventory[inventory_num] = m;
		this->inventory_num++;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4 || idx > (this->inventory_num - 1) || this->inventory[idx] == NULL)
		return ;
	for (int i = idx; i < 4; i++)
	{
		if (i < this->inventory_num)
			this->inventory[i] = this->inventory[i + 1];
		else
			this->inventory[i] = NULL;
	}
	this->inventory_num--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4 || idx > (this->inventory_num - 1) || this->inventory[idx] == NULL)
		return ;
	// cout << this->inventory[idx] << std::endl; //
	this->inventory[idx]->use(target);// Character보다 더 밑단에 있는 클래스를 전달함.(다형성)
}

void Character::delete_inventory_all(AMateria *inventory[4])
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

void Character::init_inventory_all(AMateria *inventory[4])
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

