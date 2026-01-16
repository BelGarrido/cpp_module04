#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class Dog: public Animal {
    private:
    public:
        Dog();
        Dog(const Dog& original);
        Dog& operator=(const Dog& original);
        ~Dog();
        virtual void makeSound() const;
        void print(const std::string &message) const;
};

#endif