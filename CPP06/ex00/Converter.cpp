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
	int i = 0;
	int l = 0;

	if (literals[l] == '\0')
		l++;
	if (literals[i] == '\'')
		convert_char(literals);
	else if ((literals[l - 1] == 'f')
		convert_float(literals);
	else if ((literals[i] != '.'))
		{
			if (literals[i] == '.')
				convert_double(literals);
			i++;
		}
	else if (literals[i] == )
}

