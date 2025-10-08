#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal(const std::string& t = "Animal");
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);

    std::string getType() const;
    void setType(const std::string& t);

    virtual void makeSound() const = 0;
    virtual ~AAnimal();
};

#endif
