#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{
    std::cout << "HumanB " << name << " created." << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB " << name << " destroyed." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
    std::cout << "HumanB " << name << " now has a weapon of type " << weapon.getType() << std::endl;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}
