#include "dog.hpp"

Dog::Dog() {
    _type = "Dog";
    print(" appear in the terminal");
}

Dog::Dog(const Dog &original) : Animal(original) {
    print(" cloned with copy constructor");
}

Dog& Dog::operator=(const Dog &original) {
    Animal::operator=(original);
    print(" using copy assigment");
    return *this;
}

Dog::~Dog() {
    print(" left the terminal");
}

void Dog::print(const std::string &message) const {
    std::cout << "\033[94m" << _type << message << "\033[0m" << std::endl;
}

void Dog::makeSound() const {
    print(" makes: Woof. Woof. Woof");
}