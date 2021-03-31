
#include "Squad.hpp"


Squad::Squad():
	count_(0)
{
	squads_ = new ISpaceMarine*[1];;
	
	squads_[0] = NULL;
}

Squad::~Squad()
{
	delete_squad(this->squads_, this->count_);
}

Squad::Squad(const Squad &ref)
{
	ISpaceMarine **temp = ref.squads_;
	// cout << this->squads_ << std::endl;
	count_ = ref.count_;
	this->squads_ = new ISpaceMarine *[count_ + 1];
	initNull_squad(this->squads_, count_ + 1);
	// cout << this->squads_ << std::endl;

	// cout << squads_[0] << std::endl;
	// this->push(temp[0]->clone());
	deepcopy(temp, this->count_);
	// this->squads_[count_] = NULL;
}

Squad &Squad::operator=(Squad &ref)
{
	ISpaceMarine **temp = this->squads_;
	this->squads_ = new ISpaceMarine *[ref.count_ + 1];
	initNull_squad(this->squads_, ref.count_);
	deepcopy(ref.squads_, ref.count_);
	// this->squads_[count_] = NULL;
	this->delete_squad(temp, this->count_);
	count_ = ref.count_;
	// this->delete_squad(ref.squads_, ref.count_);
	// ref.count_ = 0;
	// ref.squads_ = new ISpaceMarine*[1];
	// ref.squads_[0] = NULL;
	return (*this);
}

void Squad::delete_squad(ISpaceMarine** squads, int count)
{
	if (squads == NULL)
		return ;
	// cout << count << std::endl;
	for (int i = 0; i < count; i++)
	{
		if (squads[i] != NULL)
			delete squads[i];
	}
	delete [] squads;
}

void Squad::initNull_squad(ISpaceMarine** squads, int count)
{
	if (squads == NULL)
		return ;
	// cout << count << std::endl;
	for (int i = 0; i < count; i++)
	{
		squads[i] = NULL;
	}
}

void Squad::deepcopy(ISpaceMarine **temp, int count)
{
	// cout << "count : " << count << std::endl;
	for (int i = 0; i < count; i++)
	{
		// cout << "i : " << i << std::endl;
		squads_[i] = temp[i]->clone();
		// this->push(temp[i]->clone());
	}
	this->squads_[count] = NULL;
	return ;
}

void Squad::softcopy(ISpaceMarine **temp, int count)
{
	for (int i = 0; i < count; i++)
	{
		this->squads_[i] = temp[i];
	}
	this->squads_[count] = NULL;
	return ;
}

// 순수가상함수 받기
int Squad::getCount() const{return (count_);}

ISpaceMarine* Squad::getUnit(int i) const
{
	if (i < 0 || i >= count_)
		return (NULL);
	return (squads_[i]);
}

bool Squad::is_already_in_squads(ISpaceMarine *address)
{
	int i = 0;
	while (this->squads_[i] != NULL)
	{
		if (address == squads_[i])
			return (true);
		i++;
	}
	return (false);
}

int Squad::push(ISpaceMarine *marine)
{
	if (marine == NULL || is_already_in_squads(marine) == true)
		return (count_);
	ISpaceMarine **temp = squads_;
	int before_count;
	if (count_ == 0)
	{
		before_count = this->count_;
		this->count_++;
		squads_ = new ISpaceMarine*[count_ + 1];
		squads_[0] = marine;
		squads_[1] = NULL;
		delete_squad(temp, before_count + 1);
		// delete [] temp; // 맨처음이라도 new ISpaceMarine*[1]; 할당을 해주었음
		return (count_);
	}
	else
	{
		before_count = this->count_;
		this->count_++;
		squads_ = new ISpaceMarine*[count_ + 1];
		softcopy(temp, count_ - 1);
		squads_[count_ - 1] = marine;
		squads_[count_] = NULL;
		delete []temp;
	}
	return (count_);
}

