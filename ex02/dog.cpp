#include "dog.hpp"

Dog::Dog() {
    _type = "Dog";
    print(" appears in the terminal");
    _dogBrain = new Brain(); 
    // Allocate a new Brain on the heap
    // Every Dog must have its own Brain
    // Deep copy isn't needed here because this is the first Dog
    std::cout << &_dogBrain << std::endl;
}

Dog::Dog(const Dog &original) : AAnimal(original) {
    _dogBrain = new Brain(*(original._dogBrain)); 
    // Allocate a new Brain for this Dog (deep copy)
    // Dereference original._dogBrain to pass a Brain object to Brain copy constructor
    // This avoids shallow copy (two Dogs sharing the same Brain pointer)
    std::cout << &_dogBrain << std::endl;
}

Dog& Dog::operator=(const Dog &original) {
    AAnimal::operator=(original);
    _dogBrain = new Brain(*(original._dogBrain));
    // Copy base class attributes (_type etc.)
    return *this;
}

Dog::~Dog() {
    print(" left the terminal");
    delete _dogBrain;
}

void Dog::print(const std::string &message) const {
    std::cout << "\033[94m" << _type << message << "\033[0m" << std::endl;
}

void Dog::makeSound() const {
    print(" makes: Woof. Woof. Woof");
}