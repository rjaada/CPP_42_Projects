/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-16 03:19:34 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-16 03:19:34 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
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
	class NotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	AForm();
	AForm(std::string const &name, int const sign_it, int const execute_it);
	AForm(const AForm &other);
	AForm &operator=(AForm const &other);
	virtual ~AForm();

	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat const &b);

	void execute(Bureaucrat const & executor) const;
    virtual void executeAction() const = 0;
};
std::ostream &operator<<(std::ostream &out, AForm const &f);
#endif