#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") 
{
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) 
{
    std::cout << "WrongCat copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound() const 
{
    std::cout << type << " says Meow!" << std::endl;
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destroyed" << std::endl;
}
