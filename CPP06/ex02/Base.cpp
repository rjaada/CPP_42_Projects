/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-28 05:50:30 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-28 05:50:30 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base	*generate(void)
{
	Base	*p = NULL;
	int		highest;
	int		lowest;
	int		range;
	int		random_integer;

	highest = 3;
	lowest = 1;
	range = (highest - lowest) + 1;
	random_integer = lowest + rand() % range;
	if (random_integer == 1)
		p = new A();
	else if (random_integer == 2)
		p = new B();
	else if (random_integer == 3)
		p = new C();
	return (p);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception &)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::exception &)
			{
			}
		}
	}
}

Base::~Base()
{
}
