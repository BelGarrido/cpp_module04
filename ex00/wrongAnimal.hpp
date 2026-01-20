#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &original);
        WrongAnimal &operator=(const WrongAnimal &original);
        virtual ~WrongAnimal();

        void makeSound() const;
        virtual void print(const std::string &message) const;

        std::string getType() const;

} ;
