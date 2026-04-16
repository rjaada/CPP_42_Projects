/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-16 03:37:09 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-16 03:37:09 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("form"), issigned(false), sign_it(75), execute_it(75)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(std::string const &name, int const sign_it, int const execute_it) : name(name), sign_it(sign_it), execute_it(execute_it)
{
	this->issigned = false;
	std::cout << "Form Constructor Called" << std::endl;
	if (sign_it < 1)
		throw GradeTooHighException();
	if (sign_it > 150)
		throw GradeTooLowException();
	if (execute_it < 1)
		throw GradeTooHighException();
	if (execute_it > 150)
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Form::Form(const Form &other) : name(other.name), sign_it(other.sign_it), execute_it(other.execute_it)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form &Form::operator=(Form const &other)
{
	std::cout << "Form Copy Assignment Called" << std::endl;
	if (this != &other)
		this->issigned = other.issigned;
	return (*this);
}

std::string Form::getName() const
{
	return name;
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
	out << "Form: " << f.getName() 
        << ", Signed: " << (f.getIsSigned() ? "Yes" : "No") 
        << ", Grade to sign: " << f.getSignGrade() 
        << ", Grade to execute: " << f.getExecuteGrade() << std::endl;
    return out;
}

int Form::getSignGrade() const
{
	return sign_it;
}

int Form::getExecuteGrade() const
{
	return execute_it;
}

bool Form::getIsSigned() const
{
	return issigned;
}

void Form::beSigned(Bureaucrat const &b)
{
	if(b.getGrade() <= sign_it)
		issigned = true;
	else
		throw GradeTooLowException();

}

Form::~Form()
{
	std::cout << "Form Destructor Called" << std::endl;
}