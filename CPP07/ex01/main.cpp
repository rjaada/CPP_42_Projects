/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-05 02:55:57 by rjaada            #+#    #+#             */
/*   Updated: 2026-05-05 02:55:57 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	printInt(int &x)
{
	std::cout << x << std::endl;
}

void	printStr(std::string &s)
{
	std::cout << s << std::endl;
}

void	increment(int &x)
{
	x += 1;
}

int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	int len = 5;

	std::string s[] = {"rachid", "jaada", "42school"};

	iter(arr, len, printInt);
	iter(s, 3, printStr);

	// test modification
	int arr2[] = {10, 20, 30};
	iter(arr2, 3, increment);
	iter(arr2, 3, printInt);

	return (0);
}