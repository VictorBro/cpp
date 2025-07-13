#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(const std::string &name) : name(name), inventorySize(0)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;

    if (DEBUG)
        std::cout << "Character " << name << " created." << std::endl;
}

Character::Character(const Character &other) : name(other.name), inventorySize(other.inventorySize)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;

    if (DEBUG)
        std::cout << "Character " << name << " copied." << std::endl;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        name = other.name;
        inventorySize = other.inventorySize;

        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
        }

        if (DEBUG)
            std::cout << "Character " << name << " assigned." << std::endl;
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        if (inventory[i])
            delete inventory[i];

    if (DEBUG)
        std::cout << "Character " << name << " destroyed." << std::endl;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (inventorySize < 4 && m)
    {
        inventory[inventorySize++] = m;
        if (DEBUG)
            std::cout << "Equipped " << m->getType() << " to " << name << "." << std::endl;
    }
    else
    {
        std::cout << "Cannot equip " << (m ? m->getType() : "null") << ". Inventory full or materia is null." << std::endl;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < inventorySize)
    {
        if (DEBUG)
            std::cout << "Unequipped " << inventory[idx]->getType() << " from " << name << "." << std::endl;

        // Shift all items after this one back by one position
        for (int i = idx; i < inventorySize - 1; ++i)
            inventory[i] = inventory[i + 1];

        // Clear the last slot and decrease inventory size
        inventory[inventorySize - 1] = NULL;
        --inventorySize;
    }
    else
    {
        std::cout << "Invalid index for unequip." << std::endl;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < inventorySize && inventory[idx])
    {
        if (DEBUG)
            std::cout << name << " uses " << inventory[idx]->getType() << " on " << target.getName() << "." << std::endl;
        inventory[idx]->use(target);
    }
    else
    {
        std::cout << "Invalid index or no materia equipped." << std::endl;
    }
}
