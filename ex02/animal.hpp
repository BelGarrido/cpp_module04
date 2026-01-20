#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(const AAnimal &original);
        AAnimal &operator=(const AAnimal &original);
        virtual ~AAnimal();

        virtual void makeSound() const = 0;
        //std::string getType() const;
        virtual void print(const std::string &message) const;
} ;

#endif