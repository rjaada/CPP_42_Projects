/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 23:40:45 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/19 00:52:59 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called" << std::endl;
	int i = 0;
	while (i < 100)
	{
		ideas[i] = "Food";
		i++;
	}
}

Brain::Brain(const Brain& other)
{
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
	std::cout << "Brain Copy Constructor Called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain Copy Assignment Called" << std::endl;
	int i = 0;
	if(this != &other)
	{
		while (i < 100)
		{
			this->ideas[i] = other.ideas[i];
			i++;
		}
	}
	return *this;
}

void Brain::setIdea(int index, std::string idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (ideas[index]);
    return ("");
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called" << std::endl;
}