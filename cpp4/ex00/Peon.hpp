#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"
# include "Sorcerer.hpp"


class Peon : public Victim // Victim이 Bass class
{
public:
	Peon(std::string name_ = "null");
	Peon(const Peon &ref);
	virtual ~Peon();
	Peon& operator=(const Peon & ref);

	void    getPolymorphed() const;
};

#endif
