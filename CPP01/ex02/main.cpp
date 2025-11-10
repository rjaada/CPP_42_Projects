/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:50:59 by rjaada            #+#    #+#             */
/*   Updated: 2025/10/08 15:28:16 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string* stringREF = &brain;

	std::cout << "The memory address of Brain : " << &brain << std::endl;
	std::cout << "The memory address held by StringPTR : " << stringPTR << std::endl;
	std::cout << "The memory address held by StringPTR : " << stringREF << std::endl;
	std::cout << "The value of Brain : " << brain << std::endl;
	std::cout << "The value pointed to by stringPTR :" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF :" << *stringREF << std::endl;
	return 0;
}