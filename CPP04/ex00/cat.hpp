#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(Cat const &other);
		virtual void makeSound();
		virtual ~Cat();
		std::string GetType() const {return type;}
};

#endif