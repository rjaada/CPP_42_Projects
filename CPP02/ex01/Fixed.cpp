/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:21:29 by rjaada            #+#    #+#             */
/*   Updated: 2025/11/07 23:44:46 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed()
{
	fp_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fp_value = num << this->frac_bits;
}

Fixed::Fixed(const float f_num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fp_value = roundf(f_num * (1 << this->frac_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fp_value = copy.fp_value;
}

Fixed &Fixed::operator=(Fixed const &Fixed)
{
	if (this != &Fixed)
		this->fp_value = Fixed.fp_value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &copy)
{
	out << copy.toFloat();
	return (out);
}

float Fixed::toFloat(void) const
{
	return (float)this->fp_value / (1 << this->frac_bits);
}

int Fixed::toInt(void) const
{
	return (this->fp_value >> this->frac_bits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
