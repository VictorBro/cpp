#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal *meta = new Animal();
    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
    delete meta;

    std::cout << "------------------------" << std::endl;
    const Animal *dog = new Dog();
    std::cout << dog->getType() << " " << std::endl;
    dog->makeSound();
    delete dog;

    std::cout << "------------------------" << std::endl;
    const Animal *cat = new Cat();
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    delete cat;

    std::cout << "------------------------" << std::endl;
    const WrongAnimal *wrongMeta = new WrongAnimal();
    std::cout << wrongMeta->getType() << " " << std::endl;
    wrongMeta->makeSound();
    delete wrongMeta;

    std::cout << "------------------------" << std::endl;
    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    delete wrongCat;
    
    std::cout << "------------------------" << std::endl;
    const WrongCat *wrongCat2 = new WrongCat();
    std::cout << wrongCat2->getType() << " " << std::endl;
    wrongCat2->makeSound();
    delete wrongCat2;

    return 0;
}