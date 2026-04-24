/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 04:34:10 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-23 04:34:10 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

void ScalarConverter::checker(std::string literals)
{

	if (literals[0] == '\'')
		convert_char(literals);
	else if ((literals[literals.length() - 1]) == 'f')
		convert_float(literals);
	else if (literals.find("nanf") != std::string::npos || literals.find("+inff") != std::string::npos || literals.find("-inff") != std::string::npos)
		convert_float(literals);
	else if (literals.find('.') != std::string::npos)
		convert_double(literals);
	else if (literals.find("nan") != std::string::npos || literals.find("+inf") != std::string::npos || literals.find("-inf") != std::string::npos)
		convert_double(literals);
	else
		convert_int(literals);

}

void ScalarConverter::convert_char(std::string literals)
{
	char	c;

	c = literals[1];
	std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
}

void	ScalarConverter::convert_float(std::string literals)
{
	float f;
	f = std::stof(literals);
	if (isprint(static_cast<char>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else if (literals == "nanf" || literals == "+inff" || literals == "-inff")
		std::cout << "char: Impossible"  << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
	if (literals == "nanf" || literals == "+inff" || literals == "-inff")
		std::cout << "int: Impossible"  << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
}

void	ScalarConverter::convert_double(std::string literals)
{
	double d;
	d = std::stod(literals);
	if (literals == "nan" || literals == "+inf" || literals == "-inf")
		std::cout << "char: Impossible"  << std::endl;
	else if (isprint(static_cast<char>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	if (literals == "nan" || literals == "+inf" || literals == "-inf")
		std::cout << "int: Impossible"  << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void	ScalarConverter::convert_int(std::string literals)
{
	int i;
	i = std::stoi(literals);
	if (isprint(static_cast<char>(i)))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable"  << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	std::string l = argv[1];
	ScalarConverter::checker(l);
	return 0;
}