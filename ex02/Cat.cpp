#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") 
{
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) 
{
    std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{   
    if (this != &other)
        AAnimal::operator=(other);
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << type << " says Meow!" << std::endl;
}

Cat::~Cat() 
{
    std::cout << "Cat destroyed" << std::endl;
}