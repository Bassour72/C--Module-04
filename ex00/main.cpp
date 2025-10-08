#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
    // Cat C;
    // Animal &A = C;
    // A.makeSound();
    // const Animal* meta = new Animal();
    // if (!meta)
    // {
    //     std :: cout << "Error: allocaed "<< std :: endl;
    //     return 1;
    // }
    // const Animal* j = new Dog();
    // if (!j)
    // {
    //     delete meta;
    //     std :: cout << "Error: allocaed "<< std :: endl;
    //     return 1;
    // }
    // const Animal* i = new Cat();
    // if (!i)
    // {
    //     delete meta;
    //     delete j;
    //     std :: cout << "Error: allocaed "<< std :: endl;
    //     return 1;
    // }
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound();
    // j->makeSound();
    // meta->makeSound();
    // std::cout << std::endl;
    // delete meta;
    // std::cout << std::endl;
    // delete j;
    //  std::cout << std::endl;
    // delete i;
    //===wrong//
    WrongCat wc;
    wc.makeSound(); 
    WrongAnimal &ra = wc;
    ra.makeSound();

    return 0;
}