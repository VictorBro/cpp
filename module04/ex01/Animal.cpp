#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
    std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Animal copied." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        type = other.type;
        std::cout << "Animal assigned." << std::endl;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound!" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

std::string Animal::getIdea() const
{
    return "No idea available.";
}
