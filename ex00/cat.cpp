#include "cat.hpp"

Cat::Cat() {
    std::cout << "A Cat appear in the terminal" << std::endl;
    _type = "Cat";
}

Cat::~Cat() {
    std::cout << "Cat left the terminal" << std::endl;
    //delete(this);
}

void Cat::makeSound() const {
    std::cout << "Meow. Mrrrow. Prrrr" << std::endl;
}