/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-26 01:47:26 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-26 01:47:26 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cstring>
# include <iomanip>
# include <iostream>
# include <string>

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(ScalarConverter const &other);
	~ScalarConverter();

	static void convert_char(std::string literals);
	static void convert_float(std::string literals);
	static void convert_double(std::string literals);
	static void convert_int(std::string literals);

  public:
	static void convert(std::string literals);
};

#endif