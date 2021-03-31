#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		int sources_num_;
		AMateria *sources_[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &ref);
		virtual ~MateriaSource();
		MateriaSource &operator=(MateriaSource const &ref);

		// 내가만든함수
		bool is_type_(std::string const & str, AMateria const *ref);
		bool is_type_in_sources(std::string const & str);
		void delete_sources_all(AMateria *sources[4]);
		void init_sources_all(AMateria *sources[4]);

		// 순수가상함수
		void learnMateria(AMateria *);
		AMateria* createMateria(std::string const & type);
};


#endif
