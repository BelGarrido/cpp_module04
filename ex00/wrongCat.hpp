#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "wrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    private:
    public:
        WrongCat();
        WrongCat(const WrongCat &original);
        WrongCat &operator=(const WrongCat &original);
        ~WrongCat();
        void makeSound() const;
        void print(const std::string &message) const;
};

#endif