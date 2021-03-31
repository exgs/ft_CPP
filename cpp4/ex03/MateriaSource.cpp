#include "MateriaSource.hpp"

MateriaSource::MateriaSource() :
	sources_num_(0)
{
	init_sources_all(this->sources_);
}

MateriaSource::MateriaSource(MateriaSource const &ref) :
	sources_num_(ref.sources_num_)
{
	int count = 4;
	for (int i = 0; i < count; i++)
		this->sources_[i] = NULL; // 초기화
	for (int i = 0; i < ref.sources_num_; i++)
		this->sources_[i] = ref.sources_[i]->clone();
	// 여기서는 Deep copy내용이 없더라도 소멸자에서 sources의 요소들을 하나하나 delete해주니깐,
	// Deep copy로 해야한다.
}

MateriaSource::~MateriaSource()
{
	// if (this->sources_[i] != NULL) 안써도 됨.
	// delete []this->sources_[i]; 쓰면 에러남!!
	delete_sources_all(this->sources_);
}

MateriaSource &MateriaSource::operator=(MateriaSource const &ref)
{
	if (this == &ref)
		return (*this);
	int count = 4;
	for (int i = 0; i < count; i++)
		this->sources_[i] = NULL; // 초기화
	this->sources_num_ = ref.sources_num_;
	for (int i = 0; i < ref.sources_num_; i++)
		this->sources_[i] = ref.sources_[i]->clone();
	this->sources_num_ = ref.sources_num_;
	return (*this);
}

bool MateriaSource::is_type_(std::string const &str, AMateria const *ref)
{
	if (str.compare(ref->getType()))
		return (false);
	else
		return (true);
}

bool MateriaSource::is_type_in_sources(std::string const &str)
{
	for (int i = 0; i < this->sources_num_; i++)
	{
		if (this->is_type_(str, this->sources_[i]))
			return (true);
	}
	return (false);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->sources_num_ > 4)
		return ;
	if (this->is_type_in_sources(m->getType())) //이미 '그 타입'이 존재하는 경우
		return ;
	else if (this->sources_num_ == 4)
	{
		for (int i = 0; i < this->sources_num_ - 1; i++)
		{
			this->sources_[i] = this->sources_[i + 1];
		}
		this->sources_[this->sources_num_ - 1] = m;
	}
	else
	{
		this->sources_[this->sources_num_] = m;
		// cout << "m : " << m << std::endl;
		this->sources_num_++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (this->is_type_in_sources(type) == 0)
		return (NULL);
	for (int i = 0; i < this->sources_num_; i++)
	{
		if (this->is_type_(type, this->sources_[i]) == true)
			return (this->sources_[i]->clone());
	}
	return (NULL);
}


void MateriaSource::delete_sources_all(AMateria *inventory[4])
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

void MateriaSource::init_sources_all(AMateria *inventory[4])
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}
