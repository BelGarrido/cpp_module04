#include "animal.hpp"

AAnimal::AAnimal() {
    std::cout << "AAnimal created" << std::endl;
    _type = "animal";
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destroyed" << std::endl;
    //delete(this);
}

AAnimal::AAnimal(const AAnimal &original) {
    _type = original._type;
}

AAnimal& AAnimal::operator=(const AAnimal &original) {
    this->_type = original._type;
    return *this;
}

void AAnimal::makeSound() const {
    std::cout << "AAnimal sound being reproduced" << std::endl;
}

void AAnimal::print(const std::string &message) const {
    std::cout << "AAnimal " << message << std::endl;
}