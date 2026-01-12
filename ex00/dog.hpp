#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class Dog: public Animal {
    private:
    public:
        Dog();
        ~Dog();
        virtual void makeSound() const;
};

#endif