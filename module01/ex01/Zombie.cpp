#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("Unnamed")
{
    std::cout << "Zombie " << name << " created." << std::endl;
}

Zombie::Zombie(const std::string &name) : name(name)
{
    std::cout << "Zombie " << name << " created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " destroyed." << std::endl;
}

void Zombie::setName(const std::string &name)
{
    this->name = name;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
