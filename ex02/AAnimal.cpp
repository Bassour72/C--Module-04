
#include "AAnimal.hpp"

AAnimal::AAnimal(const std::string& t) : type(t) 
{
    std::cout << "AAnimal created: " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) 
{
    std::cout << "AAnimal copied: " << type << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

std::string AAnimal::getType() const 
{
    return type;
}

void AAnimal::setType(const std::string& t) 
{
    type = t;
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destroyed: " << type << std::endl;
}
