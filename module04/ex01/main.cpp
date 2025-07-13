#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <exception> // for std::bad_alloc

int main()
{
    Animal *animals[4];

    for (int i = 0; i < 4; ++i)
    {
        animals[i] = NULL;
    }

    try
    {
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog(*static_cast<Dog *>(animals[0]));
        animals[3] = new Cat(*static_cast<Cat *>(animals[1]));

        for (int i = 0; i < 4; ++i)
        {
            std::cout << "Animal " << i + 1 << ": " << animals[i]->getType() << std::endl;
            animals[i]->makeSound();
            std::cout << "Idea: " << animals[i]->getIdea() << std::endl;
            delete animals[i];
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            delete animals[i];
        }
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            delete animals[i];
        }
        return 1;
    }

    return 0;
}