/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-20 03:50:33 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-20 03:50:33 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(Intern const &other)
{
	std::cout << "Intern Copy Constructor Called" << std::endl;
	(void)other;
}

Intern &Intern::operator=(Intern const &other)
{
	std::cout << "Intern Copy Assignment Called" << std::endl;
	(void)other;
	return (*this);
}

AForm *Intern::makeShrubbery(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePardon(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*funcs[3])(std::string const &target) const = {
        &Intern::makeShrubbery, 
        &Intern::makeRobotomy, 
        &Intern::makePardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*funcs[i])(target);
        }
    }
    std::cout << "Intern couldn't create form: " << formName << " doesn't exist." << std::endl;
    return NULL;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}