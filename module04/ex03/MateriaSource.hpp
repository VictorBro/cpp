#pragma once
#include "IMateriaSource.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
private:
    AMateria *materias[4];
    int materiaCount;

public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);
    ~MateriaSource();

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};
