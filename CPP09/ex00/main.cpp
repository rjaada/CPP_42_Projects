/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:52:57 by rjaada            #+#    #+#             */
/*   Updated: 2026/07/07 03:00:07 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: there's no file to open" << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.readfile();
	btc.processInput(argv[1]);
	return 0;
}