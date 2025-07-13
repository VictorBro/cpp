#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
    if (DEBUG)
        std::cout << "Ice materia created." << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    if (DEBUG)
        std::cout << "Ice materia copied." << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        if (DEBUG)
            std::cout << "Ice materia assigned." << std::endl;
    }
    return *this;
}

Ice::~Ice()
{
    if (DEBUG)
        std::cout << "Ice materia destroyed." << std::endl;
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
