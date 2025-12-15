#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		Animal& operator=(Animal const &other);
		virtual void makeSound();
		virtual ~Animal();
		std::string GetType() const {return type;}
};

#endif