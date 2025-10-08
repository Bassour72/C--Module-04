#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    if (j)
    {     
        std::cout << j->getType() << " " << std::endl;
        j->makeSound();
    }
    if (i)
    {    
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
    }
     std::cout << std::endl;
    delete j;
     std::cout << std::endl;
    delete i;
    return 0;
}
