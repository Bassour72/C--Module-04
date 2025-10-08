
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string& t) : type(t) 
{
    std::cout << "WrongAnimal created: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) 
{
    std::cout << "WrongAnimal copied: " << type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
 {
    if (this != &other)
        type = other.type;
    return *this;
}

std::string WrongAnimal::getType() const 
{
    return type;
}

void WrongAnimal::setType(const std::string& t) 
{
    type = t;
}

void WrongAnimal::makeSound() const 
{
    std::cout << type << " makes a sound..." << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destroyed: " << type << std::endl;
}
