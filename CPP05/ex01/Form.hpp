/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-16 03:19:34 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-16 03:19:34 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
  private:
	std::string const name;
	bool issigned;
	int const sign_it;
	int const execute_it;

  public:
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	Form();
	Form(std::string const &name, int const sign_it, int const execute_it);
	Form(const Form &other);
	Form &operator=(Form const &other);
	~Form();

	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat const &b);
};
std::ostream &operator<<(std::ostream &out, Form const &f);
#endif