#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"

class Cat: public Animal {
    private:
    public:
        Cat();
        Cat(const Cat &original);
        Cat &operator=(const Cat &original);
        ~Cat();
        virtual void makeSound() const;
        virtual void print(const std::string &message) const;
};

#endif