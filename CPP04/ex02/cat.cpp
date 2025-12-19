/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:53:24 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/19 00:58:27 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << "Cat Copy Assignment Called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meowwwwwwwwwww" << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
    if (this->brain) 
        this->brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const
{
    if (this->brain)
        return (this->brain->getIdea(i));
    return ("");
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor Called" << std::endl;
}