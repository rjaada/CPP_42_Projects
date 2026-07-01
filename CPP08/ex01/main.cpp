/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-21 17:48:08 by rjaada            #+#    #+#             */
/*   Updated: 2026-06-21 17:48:08 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	std::cout << "--- Subject Test ---" << std::endl;
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- 10k Range Test ---" << std::endl;
	Span bigSp = Span(10000);
	std::vector<int> randomNums;

	// Fill vector with 10k numbers
	for (int i = 0; i < 10000; i++)
	{
		randomNums.push_back(i * 2);
	}

	try
	{
		// Adding them all at once
		bigSp.addNumber(randomNums.begin(), randomNums.end());
		std::cout << "Shortest: " << bigSp.shortestSpan() << std::endl;
		std::cout << "Longest: " << bigSp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}