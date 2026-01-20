#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "brain.hpp"

class Cat: public Animal {
    private:
        const Brain* _catBrain;
    public:
        Cat();
        Cat(const Cat &original);
        Cat &operator=(const Cat &original);
        ~Cat();
        virtual void makeSound() const;
        void print(const std::string &message) const;
};

#endif