/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-16 03:37:09 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-16 03:37:09 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("AForm"), issigned(false), sign_it(75), execute_it(75)
{
	std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(std::string const &name, int const sign_it, int const execute_it) : name(name), sign_it(sign_it), execute_it(execute_it)
{
	this->issigned = false;
	std::cout << "AForm Constructor Called" << std::endl;
	if (sign_it < 1)
		throw GradeTooHighException();
	if (sign_it > 150)
		throw GradeTooLowException();
	if (execute_it < 1)
		throw GradeTooHighException();
	if (execute_it > 150)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

AForm::AForm(const AForm &other) : name(other.name), sign_it(other.sign_it), execute_it(other.execute_it)
{
	std::cout << "AForm Copy Constructor Called" << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
	std::cout << "AForm Copy Assignment Called" << std::endl;
	if (this != &other)
		this->issigned = other.issigned;
	return (*this);
}

std::string AForm::getName() const
{
	return name;
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
	out << "AForm: " << f.getName() 
        << ", Signed: " << (f.getIsSigned() ? "Yes" : "No") 
        << ", Grade to sign: " << f.getSignGrade() 
        << ", Grade to execute: " << f.getExecuteGrade() << std::endl;
    return out;
}

int AForm::getSignGrade() const
{
	return sign_it;
}

int AForm::getExecuteGrade() const
{
	return execute_it;
}

bool AForm::getIsSigned() const
{
	return issigned;
}

void AForm::beSigned(Bureaucrat const &b)
{
	if(b.getGrade() <= sign_it)
		issigned = true;
	else
		throw GradeTooLowException();

}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	this->executeAction();
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("this form is not signed");
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called" << std::endl;
}