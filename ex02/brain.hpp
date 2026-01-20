#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain &original);
        Brain &operator=(const Brain &original);
        virtual ~Brain();
        virtual void print(const std::string &message) const;

} ;

#endif