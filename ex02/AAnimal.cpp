
#include "AAnimal.hpp"


AAnimal::AAnimal() : type("Animal") 
{
    std::cout << "[AAnimal] Default constructor called. Type: " << type << std::endl;
}

AAnimal::AAnimal(const std::string& t) : type(t) 
{
    std::cout << "[AAnimal] Parameterized constructor called. Type: " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) 
{
    std::cout << "[AAnimal] Copy constructor called. Copied Type: " << type << std::endl;
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
