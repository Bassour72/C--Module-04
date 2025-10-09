#include "AMateria.hpp"
AMateria::AMateria(std::string const & type):_type(type)
{

}
std::string const &AMateria::getType() const 
{
    return (_type);
}

void AMateria::setType(std::string &type)
{
    _type = type;
}

void AMateria::use(ICharacter& target)
{
   std::cout << "* The Materia shimmers faintly, releasing a default energy *\n";
    (void)target;
}
AMateria::~AMateria()
{

}