#include "Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
    std::cout << "Dog created" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "Dog copied" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "Dog assigned" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

void Dog::makeSound() const 
{
    std::cout << type << " says Bark!" << std::endl;
}
void Dog::addIdea(const std::string& idea)
{
    if (_brain)
        _brain->setIdeas(idea);
    else
        std::cout << "Cannot add idea: empty brain.\n";
}

void Dog::showLastIdea() const
{
    if (_brain)
        std::cout << "Dog's last idea: " << _brain->getIdeas() << std::endl;
    else
        std::cout << "Dog has no brain.\n";
}


Dog::~Dog() 
{
    delete _brain;
    std::cout << "Dog destroyed" << std::endl;
}

