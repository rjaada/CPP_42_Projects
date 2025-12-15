/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 16:53:24 by rjaada            #+#    #+#             */
/*   Updated: 2025-12-15 16:53:24 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	std::cout << "Cat Copy Assignment Called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

void Cat::makeSound()
{
	std::cout << "Meowwwwwwwwwww" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}