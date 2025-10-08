#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") 
{
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        AAnimal::operator=(other);
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << type << " says Bark!" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

