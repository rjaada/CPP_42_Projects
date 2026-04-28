/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-28 01:41:07 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-28 01:41:07 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *original = new Data;
	original->name = "Test Data";

	std::cout << "Original pointer: " << original << std::endl;
	std::cout << "Original name: " << original->name << std::endl;

	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Serialized to: " << raw << std::endl;

	Data *restored = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << restored << std::endl;
	std::cout << "Restored name: " << restored->name << std::endl;

	if (original == restored)
		std::cout << "SUCCESS: Pointers match!" << std::endl;
	else
		std::cout << "FAILURE: Pointers don't match!" << std::endl;

	delete original;
	return 0;
}
