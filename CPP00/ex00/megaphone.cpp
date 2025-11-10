/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:04:21 by rjaada            #+#    #+#             */
/*   Updated: 2025/06/11 13:55:27 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (1);
	}
	int i = 1;
	int j = 0;
	while (argc > i)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
			{
				argv[i][j] -= 32;
				std::cout << argv[i][j];
				j++;
			}
			else
			{
				std::cout << argv[i][j];
				j++;
			}
		}
		j = 0;
		i++;
	}
	std::cout << '\n';
	return (0);
}