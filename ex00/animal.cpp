#include "animal.hpp"

Animal::Animal() {
    std::cout << "New animal in the terminal" << std::endl;
    _type = "animal";
}

Animal::~Animal() {
    std::cout << "Animal left the terminal" << std::endl;
}

Animal::Animal(const Animal &original) {
    print(" cloned with copy constructor");
    _type = original._type;
}

Animal& Animal::operator=(const Animal &original) {
    this->_type = original._type;
    print(" using copy assigment");
    return *this;
}

std::string Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << "Animal sound being reproduced" << std::endl;
}

void Animal::print(const std::string &message) const {
    std::cout << "Animal" << message << std::endl;
}