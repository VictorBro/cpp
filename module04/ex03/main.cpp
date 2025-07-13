#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    std::cout << "=== BASIC TEST ===" << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    std::cout << "\n=== TEST UNEQUIP ===" << std::endl;
    src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *alice = new Character("Alice");
    bob = new Character("Bob");
    AMateria *equiped1 = src->createMateria("ice");
    alice->unequip(0); // Should do nothing
    alice->equip(equiped1);
    AMateria *equiped2 = src->createMateria("cure");
    alice->equip(equiped2);
    std::cout << "Before unequip:" << std::endl;
    alice->use(0, *bob);
    alice->use(1, *bob);
    alice->unequip(0);
    std::cout << "After unequip index 0:" << std::endl;
    alice->use(0, *bob); // Now it's a cure
    alice->use(1, *bob); // Invalid index
    delete bob;
    delete alice;
    delete src;
    delete equiped1;

    std::cout << "\n=== INVENTORY LIMIT TEST ===" << std::endl;
    src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    AMateria *extra = new Ice();
    src->learnMateria(extra); // Should not be added, inventory is full
    delete extra;
    alice = new Character("Alice");
    for (int i = 0; i < 5; ++i) {
        AMateria *m = src->createMateria(i % 2 == 0 ? "ice" : "cure");
        alice->equip(m);
        if (i == 4)
            delete m; // Last materia should not be equipped
    }
    delete alice;
    delete src;
    
    return 0;
}