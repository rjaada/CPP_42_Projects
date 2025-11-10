/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:19:58 by rjaada            #+#    #+#             */
/*   Updated: 2025/11/07 20:57:34 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

const int FixedPoint::frac_bits = 8;

FixedPoint::FixedPoint()
{
	fp_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

FixedPoint::FixedPoint(const FixedPoint &copy)
{
	this->fp_value = copy.fp_value;
	std::cout << "Copy constructor called" << std::endl;
}

FixedPoint &FixedPoint::operator=(FixedPoint const &copy)
{
	if (this != &copy)
		this->fp_value = copy.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int FixedPoint::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_value);
}

void FixedPoint::setRawBits(int const raw)
{
	this->fp_value = raw;
}

FixedPoint::~FixedPoint()
{
	std::cout << "Destructor called" << std::endl;
}
