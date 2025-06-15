#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &name) : name(name)
{
    std::cout << "Zombie " << name << " created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " destroyed." << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
