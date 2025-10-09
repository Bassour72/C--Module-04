#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "ICharacter.hpp"
#include <iostream>
class ICharacter;
class AMateria
{

protected:
    std::string _type;
public:

    AMateria();
    AMateria(std::string const & type);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    void setType(const std::string &type);
    AMateria &operator=(const AMateria& other);
    AMateria(const AMateria& other);
    virtual ~AMateria();
};

#endif
