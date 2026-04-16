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
	
	try
	{
		Bureaucrat b("hassan", 150);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl; 
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b0("b0", 1);
		std::cout << b0 << std::endl;
		b0.incrementGrade();
		std::cout << b0 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	try
	{
		Bureaucrat b1("Rachid", 42);
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Jaada", 0);
		std::cout << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b3("Imane", 151);
		std::cout << b3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b4("b4", 50);
		std::cout << b4 << std::endl;
		b4.decrementGrade();
		std::cout << b4 << std::endl;
		b4.incrementGrade();
		std::cout << b4 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}