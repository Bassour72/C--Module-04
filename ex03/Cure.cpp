#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "[Cure] Default constructor called — type set to '" << _type << "'\n";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "[Cure] Copy constructor called — cloned from another Cure of type '" 
              << _type << "'\n";
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << "[Cure] Copy assignment operator called\n";

    if (this != &other)
    {
        AMateria::operator=(other);
        std::cout << "[Cure] Assignment complete — type updated to '" << _type << "'\n";
    }
    else
    {
        std::cout << "[Cure] Self-assignment detected — no changes made\n";
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "[Cure] Destructor called — '" << _type << "' materia released\n";
}


AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

