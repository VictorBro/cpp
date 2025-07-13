#include "Dog.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

Dog::Dog()
{
    // Seed the random number generator only once per program execution
    static bool seeded = false;
    if (!seeded)
    {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }

    type = "Dog";
    brain = new Brain(); // This will throw std::bad_alloc if it fails

    // Initialize the brain with some default ideas
    for (int i = 0; i < 100; ++i)
    {
        std::ostringstream ss;
        ss << "Default idea " << i;
        brain->setIdea(i, ss.str());
    }

    std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    type = other.type;
    brain = new Brain(*other.brain); // This will throw std::bad_alloc if it fails
    std::cout << "Dog copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);

        // Create new brain first
        Brain *newBrain = new Brain(*other.brain); // This will throw std::bad_alloc if it fails

        // Only delete old brain after successful allocation
        delete brain;
        brain = newBrain;

        std::cout << "Dog assigned." << std::endl;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea() const
{
    // get random idea from the brain
    int index = rand() % 100;
    return brain->getIdea(index);
}
