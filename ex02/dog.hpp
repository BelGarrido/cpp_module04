#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "brain.hpp"

class Dog: public AAnimal {
    private:
        const Brain* _dogBrain;
    public:
        Dog();
        Dog(const Dog& original);
        Dog& operator=(const Dog& original);
        ~Dog();
        virtual void makeSound() const;
        void print(const std::string &message) const;
};

#endif