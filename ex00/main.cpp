#include "cat.hpp"
#include "dog.hpp"
#include "wrongCat.hpp"

int main()
{
    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Test Construction ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << j->getType() << " checked" << std::endl;
    std::cout << i->getType() << " checked" << std::endl;
    std::cout << std::endl;
    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Test Copy and Copy Assigment ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    Cat michi;
    Cat misssi(michi);
    Cat misifu;
    misifu = michi;
    std::cout << std::endl;
    std::cout << misifu.getType() << " checked" << std::endl;
    std::cout << std::endl;

    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Test makeSound() ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Test WrongCat ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    const WrongAnimal* x = new WrongCat();
    x->makeSound();
    std::cout << std::endl;

    std::cout << "\033[1;96m" << "*´¯`*..*´¯`* [ Test Destructor ] *´¯`*..*´¯`* " << "\033[0m" << std::endl; 
    delete meta;
    delete j;
    delete i;
    return 0;
}