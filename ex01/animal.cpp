#include "animal.hpp"

Animal::Animal() {
    std::cout << "New animal in the terminal" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal left the terminal" << std::endl;
    //delete(this);
}

Animal::Animal(const Animal &original) {
    _type = original._type;
}

Animal& Animal::operator=(const Animal &original) {
    this->_type = original._type;
    return *this;
}

std::string Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << "Animal sound being reproduced" << std::endl;
}

void Animal::print(const std::string &message) const {
    std::cout << "Animal " << message << std::endl;
}