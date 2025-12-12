#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	Cat();
	Cat(const Cat &other);
	Cat& operator=(Cat const other);
	void makeSound();
	~Cat();
};

#endif