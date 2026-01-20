#include "brain.hpp"

// Default constructor
Brain::Brain() {
    print("Brainstorming"); 
    for (int i = 0; i < 50; i++) {
        _ideas[i] = "Nap in the sun"; 
    }

    for (int i = 50; i < 100; i++) {
        _ideas[i] = "Steal socks"; 
    }
    // Note: No new or delete needed for _ideas, it's a fixed array of strings
}

// Destructor
Brain::~Brain() {
    print("Brain shut down"); 
    // Strings clean themselves, no manual delete needed
}

// Copy constructor
Brain::Brain(const Brain &original) {
    print("Brain copy constructor called"); 
    for (int i = 0; i < 100; i++) {
        _ideas[i] = original._ideas[i]; 
        // Deep copy each string from original Brain
        // Important: Brain itself owns the array, so we copy contents
    }
}

// Copy assignment operator
Brain& Brain::operator=(const Brain &original) {
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = original._ideas[i]; 
        // Deep copy each idea
        // NOTE: Brain has no dynamic pointer members, so no need to delete old memory
        // For classes with dynamic memory, assignment must handle deletion first
    }
    return *this; 
}

// Helper print function
void Brain::print(const std::string &message) const {
    std::cout << "\033[33m" << message << "\033[0m" << std::endl; 
}
