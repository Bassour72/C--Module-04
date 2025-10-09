#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
   AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);

    ICharacter *bob = new Character("bob");
    //bob->equip(tmp);
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("ice"));

    me->use(0, *bob); // from me
    me->use(1, *bob);
    me->unequip(1);
    me->unequip(0);
    me->unequip(2);
    me->unequip(3);

    *me = *bob;

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));

    me->unequip(0);
    delete bob;
   // bob = NULL;
    delete me;
     delete src;
    return 0;
}
/*
 * shoots an ice bolt at bob *$
 * heals bob's wounds *$
 */

 //todo
 /*
    set  to null in des
 */