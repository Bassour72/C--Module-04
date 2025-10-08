#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal(const std::string& t = "WrongAnimal");
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);

    std::string getType() const;
    void setType(const std::string& t);

    virtual void makeSound() const;
    virtual ~WrongAnimal();
};

#endif
