#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal &original);
        Animal &operator=(const Animal &original);
        virtual ~Animal();

        virtual void makeSound() const;
        virtual void print(const std::string &message) const;

        std::string getType() const;

} ;

#endif