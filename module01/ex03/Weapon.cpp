#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string &type) : type(type)
{
    std::cout << "Weapon of type '" << type << "' created." << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon of type '" << type << "' destroyed." << std::endl;
}

const std::string &Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string &type)
{
    this->type = type;
    std::cout << "Weapon type set to '" << type << "'." << std::endl;
}
