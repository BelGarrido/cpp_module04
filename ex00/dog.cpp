#include "dog.hpp"

Dog::Dog() {
    std::cout << "A Dog appear in the terminal" << std::endl;
    _type = "Dog";
}

Dog::~Dog() {
    std::cout << "Dog left the terminal" << std::endl;
    //delete(this);
}

void Dog::makeSound() const {
    std::cout << "Woof. Woof. Woof" << std::endl;
}