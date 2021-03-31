#include "HumanB.hpp"
#include "HumanA.hpp"

int main()
{
	HumanA west1;
	west1.setName("jikang");
	west1.setType("foot");
	west1.attack();
	
	HumanB west2;
	west2.setName("yunslee");
	west2.setType("gun");
	west2.attack();
	
	
	return (1);
}