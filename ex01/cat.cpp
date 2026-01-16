#include "cat.hpp"

Cat::Cat() {
    _type = "Cat";
    print(" appear in the terminal");
}

Cat::Cat(const Cat &original) : Animal(original) {
}

Cat& Cat::operator=(const Cat &original) {
    Animal::operator=(original);
    return *this;
}

Cat::~Cat() {
    print(" left the terminal");
}

void Cat::print(const std::string &message) const {
    std::cout << "\033[95m" << _type << message << "\033[0m" << std::endl;
}

void Cat::makeSound() const {
    print(" makes: Meow. Mrrrow. Prrrr");
}

