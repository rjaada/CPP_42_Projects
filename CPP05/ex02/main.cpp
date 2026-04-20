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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL)); // Seeds RNG for Robotomy

	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat noob("Noob", 150);

		ShrubberyCreationForm tree("Garden");
		RobotomyRequestForm robo("Bender");
		PresidentialPardonForm pardon("Zaphod");

		std::cout << "\n--- NOOB TRIES STUFF ---" << std::endl;
		noob.executeForm(tree); // Fails: not signed
		noob.signForm(tree);    // Fails: grade too low

		std::cout << "\n--- BOSS SIGNS ---" << std::endl;
		boss.signForm(tree);
		boss.signForm(robo);
		boss.signForm(pardon);

		std::cout << "\n--- BOSS EXECUTES ---" << std::endl;
		boss.executeForm(tree);
		boss.executeForm(robo);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}