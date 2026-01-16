#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "New animal in the terminal" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal left the terminal" << std::endl;
    //delete(this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &original) {
    _type = original._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &original) {
    this->_type = original._type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    print("sound being reproduced");
}

void WrongAnimal::print(const std::string &message) const {
    std::cout << "\031[95m" << _type << message << "\033[0m" << std::endl;
}