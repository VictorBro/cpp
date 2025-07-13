#pragma once
#include <string>

#ifndef DEBUG
#define DEBUG 0
#endif

class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};
