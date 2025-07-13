#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Dog assigned." << std::endl;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
