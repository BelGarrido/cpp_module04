#include "cat.hpp"
#include "dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    //Cat *michi = new Cat();
    //Cat michi;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    //michi.makeSound();
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
/*     const WrongAnimal* x = new WrongCat();
    x->makeSound(); */

    delete meta;
    delete j;
    delete i;
    return 0;
}