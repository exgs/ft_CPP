#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

// using namespace std;

class Squad : public ISquad
{
	private:
		int count_;
		ISpaceMarine** squads_;
	public:
		Squad();
		virtual ~Squad();
		Squad(const Squad &ref);
		Squad &operator=(Squad &ref);

		// 내가 만든 함수
		void deepcopy(ISpaceMarine **temp, int count);
		bool is_already_in_squads(ISpaceMarine *temp);
		void delete_squad(ISpaceMarine** , int);
		void initNull_squad(ISpaceMarine**, int );
		void softcopy(ISpaceMarine **temp, int count);


		// 순수가상함수 받기
		int getCount() const;
		ISpaceMarine* getUnit(int) const;
		int push(ISpaceMarine *);

};

#endif
