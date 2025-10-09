#include "Character.hpp"

Character::Character() : _name("default")
{
    for (int i = 0; i < 4; ++i)
        inventoryTmp[i] = inventory[i] = NULL;
    std::cout << "[Character] Default constructor called for '" << _name << "'\n";
}

Character::Character(const std::string &name) : _name(name)
{
    for (int i = 0; i < 4; ++i)
        inventoryTmp[i] = inventory[i] = NULL;
    std::cout << "[Character] Parameterized constructor called for '" << _name << "'\n";
}

Character::Character(const Character &other) : _name(other._name)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.inventory[i])
        {
            inventory[i] = other.inventory[i]->clone();
            inventoryTmp[i] = inventory[i];
        }
        else
            inventoryTmp[i] = inventory[i] = NULL;
    }
    std::cout << "[Character] Copy constructor called for '" << _name << "'\n";
}

Character &Character::operator=(const Character &other)
{
    std::cout << "[Character] Copy assignment operator called for '" << _name 
              << "' = '" << other._name << "'\n";

    if (this != &other)
    {
        _name = other._name;

        for (int i = 0; i < 4; ++i)
        {
            if (inventory[i] != inventoryTmp[i])
            {
                delete inventoryTmp[i];
                inventoryTmp[i] = NULL;
            }
            delete inventory[i];
            inventory[i] = NULL;

            if (other.inventory[i])
            {
                inventory[i] = other.inventory[i]->clone();
                inventoryTmp[i] = inventory[i];
            }
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        if (inventoryTmp[i] && !isExist(inventory, inventoryTmp[i]))
        {
            delete inventoryTmp[i];
        }
        if (inventory[i])
        {
            delete inventory[i];
        }
        inventoryTmp[i] = NULL;
        inventory[i] = NULL;
    }
    std::cout << "[Character] Destructor called for '" << _name << "'\n";
}


std::string const &Character::getName() const
{
    return _name;
}
void Character::setName(std::string &name)
{   
    _name = name;
}

bool Character::isExist(AMateria* const _inventory[4], const AMateria* m) const
{
    if (!m)
        return false;

    for (short i = 0; i < 4; ++i)
    {
        if (_inventory[i] == m)
            return true;
    }
    return false;
}

void Character::equip(AMateria* m)
{
    if (!m) return;

    if (isExist(inventory, m)) return;

    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            if (inventoryTmp[i] && inventoryTmp[i] != m)
            {
                delete inventoryTmp[i];
            }

            inventory[i] = m;
            inventoryTmp[i] = m;
            std::cout << "[Character] Equipped Materia in slot " << i << "\n";
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx])
        inventory[idx]->use(target);
}
