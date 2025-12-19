/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:27:20 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/19 00:56:16 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain(); // to allocate a new memo
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << "Dog Copy Assignment Called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain; // to prevent leaks
		this->brain = new Brain(*other.brain); // reallocate new memo and copy 
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "woof woof woof" << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
    if (brain)
        brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
    if (brain)
        return (brain->getIdea(i));
    return ("");
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor Called" << std::endl;
}