#include "cat.hpp"
#include "dog.hpp"

void header() {
    std::cout << 
            "....................................................\n"    
            "...............|\\      _,,,---,,_...................\n"
            ".........ZZZzz /,`.-'`'    -.  ;-;;,_...............\n"
            ".............|,4-  ) )-,_. ,\\ (  `'-'...............\n"
            "............'---''(_/--'  `-'\\_)....................\n"
            "....................................................\n";   

    std::cout << std::endl;
}

int main()
{
    header();
    Animal test;
    std::cout << std::endl; 
    
    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Testing Array ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    const Animal *animals[4];

    for(int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
            std::cout << std::endl; 
        }
        else {
            animals[i] = new Cat();
            std::cout << std::endl; 
        }
    };

    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Testing Destructor ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    for(int i = 0; i < 4; i++) {
        delete animals[i];
        std::cout << std::endl; 
    };

    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Testing Deep Copy ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    Cat michi;
    std::cout << std::endl; 
    
    Cat misi(michi);
    std::cout << std::endl;

    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Testing Deep Copy II ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    Dog basic;
    {
      Dog tmp = basic;
    }
    std::cout << std::endl;
    
    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Testing Destructors ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    return 0;
}
