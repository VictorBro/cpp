#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
    std::cout << "WrongAnimal copied." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        type = other.type;
        std::cout << "WrongAnimal assigned." << std::endl;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed." << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Wrong animal sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}
