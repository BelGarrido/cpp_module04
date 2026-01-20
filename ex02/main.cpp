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
    //const AAnimal* j = new AAnimal();
    const AAnimal* i = new Cat();
    /*const Cat *micho = new Cat();

    const Cat *copyMicho = new Cat(*micho); */
    std::cout << "*´¯`*.......*´¯`* [ Testing array ] *´¯`*.......*´¯`* \n" << std::endl; 

    const AAnimal *animals[4];

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

    for(int i = 0; i < 4; i++) {
        delete animals[i];
        std::cout << std::endl; 
    };

/*     delete copyMicho;
    delete j; //should not create a leak */
    delete i; 

    std::cout << "*´¯`*......*´¯`* [ Testing deep copy ] *´¯`*.....*´¯`* \n" << std::endl; 
    Cat michi;
    std::cout << std::endl; 
    Cat misi(michi);
    std::cout << std::endl; 
    return 0;
}