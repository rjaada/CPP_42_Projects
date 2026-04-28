/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-28 01:03:57 by rjaada            #+#    #+#             */
/*   Updated: 2026-04-28 01:03:57 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	std::cout << "this is the result of serialization: " << raw << std::endl;
	return raw;
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data *pointer = reinterpret_cast<Data*>(raw);
	std::cout << "this is the result of deserialization: " << pointer << std::endl;
	return pointer;
}
