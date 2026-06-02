/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-02 14:54:47 by rjaada            #+#    #+#             */
/*   Updated: 2026-06-02 14:54:47 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <vector>

int	main(void)
{
	int arr[] = {1, 2, 3, 42, 7};
	std::vector<int> numbers(arr, arr + 5);
	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 42);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	return (0);
}