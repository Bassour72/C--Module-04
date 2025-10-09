#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
    std::cout << "[AMateria] Default constructor called\n";
}

AMateria::AMateria(const std::string& type) : _type(type)
{
    std::cout << "[AMateria] Parameterized constructor called for type: " << _type << '\n';
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
    std::cout << "[AMateria] Copy constructor called\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "[AMateria] Copy assignment operator called\n";
    if (this != &other)
        _type = other._type;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "[AMateria] Destructor called\n";
}

const std::string& AMateria::getType() const
{
    return _type;
}

void AMateria::setType(const std::string& type)
{
    _type = type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* The Materia shimmers faintly, releasing a gentle magical energy *\n";
    (void)target;
}
