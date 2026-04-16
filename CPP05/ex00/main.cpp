/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:26:14 by rjaada            #+#    #+#             */
/*   Updated: 2026/04/13 21:34:29 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat b("hassan", 1);
	b.decrementGrade();
	
	try
	{
		Bureaucrat b1("Rachid", 42);
		std::cout << b1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Jaada", 0);
		std::cout << b2;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b3("Imane", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	




	return (0);
}