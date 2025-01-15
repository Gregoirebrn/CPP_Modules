#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->unequip(0);
	me->unequip(3);
	me->equip(tmp);
	AMateria* out;
	{
		std::cout << "INN" << std::endl;
		std::string tht = "gregoire";
		AMateria test = AMateria(tht);
		test = src->createMateria("ice");
		out = test;
		out->getType();
	}
	out->getType();
		std::cout << "OUUT" << std::endl;
	me->equip(tmp);
	me->equip(tmp);
	me->unequip(-1);
	me->unequip(200);
	me->unequip(3);
	me->equip(tmp);
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(-1, *bob);
	me->use(100, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}