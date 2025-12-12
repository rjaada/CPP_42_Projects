#ifndef DOG_HPP
# define  DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	Dog();
	Dog(const Dog &other);
	Dog& operator=(Dog const other);
	void makeSound();
	~Dog();

};

#endif