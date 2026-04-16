/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:11:59 by rjaada            #+#    #+#             */
/*   Updated: 2026/04/13 21:26:18 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("bureaucrat"), grade(75)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name), grade(grade)
{
	std::cout << "Bureaucrat Constructor Called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "Bureaucrat Copy Assignment Called" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return grade;
}

std::string Bureaucrat::getName() const
{
	return name;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}


Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}