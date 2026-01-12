#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"

class Cat: public Animal {
    private:
    public:
        Cat();
        ~Cat();
        virtual void makeSound() const;
};

#endif