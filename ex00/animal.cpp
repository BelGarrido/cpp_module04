#include "animal.hpp"

Animal::Animal() {
    std::cout << "New animal in the terminal" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal left the terminal" << std::endl;
    //delete(this);
}

std::string Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << "Animal sound being reproduced" << std::endl;
}