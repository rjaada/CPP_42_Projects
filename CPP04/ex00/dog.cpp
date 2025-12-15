/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 17:27:20 by rjaada            #+#    #+#             */
/*   Updated: 2025-12-15 17:27:20 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
	std::cout << "Dog Copy Assignment Called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void Dog::makeSound()
{
	std::cout << "woof woof woof" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
}