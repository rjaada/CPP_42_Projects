/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:10:16 by rjaada            #+#    #+#             */
/*   Updated: 2025/08/03 22:26:41 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <sstream>

void Contact::set_info()
{
	do {
		std::cout << "Enter the first name: ";
		std::getline(std::cin, first_name);
	} while (first_name.empty());

	do {
		std::cout << "Enter the last name: ";
		std::getline(std::cin, last_name);
	} while (last_name.empty());

	do {
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, nickname);
	} while (nickname.empty());

	do {
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, phone_number);
	} while (phone_number.empty());

	do {
		std::cout << "Enter the darkest secret: ";
		std::getline(std::cin, darkest_secret);
	} while (darkest_secret.empty());
}

void Contact::show_info()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

std::string Contact::format_field(const std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	std::string formatted = field;
	while (formatted.length() < 10)
		formatted = " " + formatted;
	return formatted;
}

void Contact::display_table(int index)
{
	std::stringstream ss;
	ss << index;
	std::cout << format_field(ss.str()) << "|";
	std::cout << format_field(first_name) << "|";
	std::cout << format_field(last_name) << "|";
	std::cout << format_field(nickname) << "|\n";
}

bool Contact::is_empty()
{
	return first_name.empty();
}