/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 03:08:25 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-23 03:08:25 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <iostream>
#include <cstring>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();

		
	public:
		static void convert(std::string literals);
		static void checker(std::string literals);
		static void convert_char(std::string literals);
		static void convert_float(std::string literals);
		static void convert_double(std::string literals);
		static void convert_int(std::string literals);
		char c;
		float f;
		int i;
		double d;
};

#endif