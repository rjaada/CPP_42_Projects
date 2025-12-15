/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 15:58:11 by rjaada            #+#    #+#             */
/*   Updated: 2025-12-15 15:58:11 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	std::cout << "Animal Copy Assignment Called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void Animal::makeSound()
{
	std::cout << "Animal Sound" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}
