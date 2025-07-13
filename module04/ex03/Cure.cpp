#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    if (DEBUG)
        std::cout << "Cure materia created." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
    if (DEBUG)
        std::cout << "Cure materia copied." << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
        if (DEBUG)
            std::cout << "Cure materia assigned." << std::endl;
    }
    return *this;
}

Cure::~Cure()
{
    if (DEBUG)
        std::cout << "Cure materia destroyed." << std::endl;
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
