#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource() : materiaCount(0)
{
    for (int i = 0; i < 4; ++i)
        materias[i] = NULL;

    if (DEBUG)
        std::cout << "MateriaSource created." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : materiaCount(other.materiaCount)
{
    for (int i = 0; i < 4; ++i)
        materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;

    if (DEBUG)
        std::cout << "MateriaSource copied." << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < materiaCount; ++i)
            delete materias[i];

        materiaCount = other.materiaCount;

        for (int i = 0; i < 4; ++i)
            materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;

        if (DEBUG)
            std::cout << "MateriaSource assigned." << std::endl;
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < materiaCount; ++i)
        delete materias[i];

    if (DEBUG)
        std::cout << "MateriaSource destroyed." << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (materiaCount < 4 && m)
    {
        materias[materiaCount++] = m;
        if (DEBUG)
            std::cout << "Learned materia: " << m->getType() << std::endl;
    }
    else
    {
        std::cout << "Materia source is full or materia is null." << std::endl;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < materiaCount; ++i)
    {
        if (materias[i] && materias[i]->getType() == type)
        {
            return materias[i]->clone();
        }
    }
    std::cout << "Materia of type " << type << " not found." << std::endl;
    return NULL;
}
