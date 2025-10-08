#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

  Animal* animals[10];

    for (size_t i = 0; i < 10; i++) 
    {
        if (i < 5)
        {    
            animals[i] = new Dog();
        }
        else
        {    
            animals[i] = new Cat();
        }
    }
    for (size_t i = 0; i < 10; i++) 
    {
        if (animals[i])
            animals[i]->makeSound();
    }
    for (size_t i = 0; i < 10; i++) 
    {
        delete animals[i];
    }
    const Animal* j = new Dog();
    if (j)
        j->makeSound();
    const Animal* i = new Cat();
    if (i)
        i->makeSound();
    delete j;//should not create a leak
    delete i;
return 0;
}