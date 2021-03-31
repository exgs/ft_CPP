#ifndef PIG_HPP
# define PIG_HPP

# include "Victim.hpp"
# include "Sorcerer.hpp"


class Pig : public Victim // Victim이 Bass class
{
public:
	Pig(std::string name_="null");
	Pig(const Pig &ref);
	virtual ~Pig();
	Pig& operator=(const Pig & ref);

	void    getPolymorphed() const;
};

#endif
