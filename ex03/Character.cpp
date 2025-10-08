#include "Character.hpp"

Character::Character(const std::string &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        inventoryTmp[i]  = inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventoryTmp[i]  = inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != inventoryTmp[i])
        {
            delete inventoryTmp[i];
            inventoryTmp[i] =NULL;
        }
        delete inventory[i];
        inventory[i] = NULL;
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{

    if (!m) 
        return;
    
    for (int i = 0; i < 4; i++)
    {   
        if (!inventory[i])
        {
            delete inventoryTmp[i];
            inventoryTmp[i] = NULL;
            inventory[i] = m;
            inventoryTmp[i] = m;
            break;
        }
    }
}
void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4) 
        return;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4) 
        return;
    if (inventory[idx])
        inventory[idx]->use(target);
}
