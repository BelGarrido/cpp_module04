#include "wrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    print(" appear in the terminal");
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original) {
}

WrongCat& WrongCat::operator=(const WrongCat &original) {
    WrongAnimal::operator=(original);
    return *this;
}

WrongCat::~WrongCat() {
    print(" left the terminal");
}

void WrongCat::print(const std::string &message) const {
    std::cout << "\033[31m" << _type << message << "\033[0m" << std::endl;
}

void WrongCat::makeSound() const {
    print(" makes: Meow. Mrrrow. Prrrr");
}

