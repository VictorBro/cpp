#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon)
{
    std::cout << "HumanA " << name << " created with weapon of type " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA " << name << " destroyed." << std::endl;
}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
