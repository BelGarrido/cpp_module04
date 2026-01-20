#include "cat.hpp"

// Default constructor
Cat::Cat() {
    _type = "Cat";
    print(" appears in the terminal"); 

    _catBrain = new Brain(); 
    // Allocate a new Brain on the heap
    // Every Cat must have its own Brain
    // Deep copy isn't needed here because this is the first Cat
    std::cout << &_catBrain << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &original) : AAnimal(original) {
    // First copy the base class part (Animal) to preserve _type etc.
    
    _catBrain = new Brain(*(original._catBrain)); 
    // Allocate a new Brain for this Cat (deep copy)
    // Dereference original._catBrain to pass a Brain object to Brain copy constructor
    // This avoids shallow copy (two Cats sharing the same Brain pointer)
    std::cout << &_catBrain << std::endl;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat &original) {
    AAnimal::operator=(original);
    _catBrain = new Brain(*(original._catBrain));
    // Copy base class attributes (_type etc.)
    return *this;
}

// Destructor
Cat::~Cat() {
    print(" left the terminal");
    delete _catBrain; 
    // Delete the Brain we allocated i
}

void Cat::print(const std::string &message) const {
    std::cout << "\033[95m" << _type << message << "\033[0m" << std::endl;
}

void Cat::makeSound() const {
    print(" makes: Meow. Mrrrow. Prrrr");
    // Example of polymorphism: Cat overrides Animal::makeSound()
}
