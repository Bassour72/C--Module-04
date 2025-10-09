#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* inventory[4];
    AMateria* inventoryTmp[4];

public:
    Character();
    Character(const std::string &name);                 
    Character(const Character& other);                  
    Character& operator=(const Character& other);
    ~Character();

    std::string const & getName() const;
    void setName(std::string &name);
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    bool isExist(AMateria* const inventory[4], const AMateria* m) const;
};

#endif /* CHARACTER_HPP */