#include "Cat.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

Cat::Cat()
{
    // Seed the random number generator only once per program execution
    static bool seeded = false;
    if (!seeded)
    {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }
    
    type = "Cat";
    brain = new Brain(); // This will throw std::bad_alloc if it fails
    
    // Initialize the brain with some default ideas
    for (int i = 0; i < 100; ++i)
    {
        std::ostringstream ss;
        ss << "Default idea " << i;
        brain->setIdea(i, ss.str());
    }
    
    std::cout << "Cat created." << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
    type = other.type;
    brain = new Brain(*other.brain); // This will throw std::bad_alloc if it fails
    std::cout << "Cat copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        
        // Create new brain first
        Brain* newBrain = new Brain(*other.brain); // This will throw std::bad_alloc if it fails
        
        // Only delete old brain after successful allocation
        delete brain;
        brain = newBrain;
        
        std::cout << "Cat assigned." << std::endl;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

std::string Cat::getIdea() const
{
    // get random idea from the brain
    int index = rand() % 100;
    return brain->getIdea(index);
}
