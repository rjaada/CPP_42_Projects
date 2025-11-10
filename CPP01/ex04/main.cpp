/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:53:48 by rjaada            #+#    #+#             */
/*   Updated: 2025/10/09 17:48:07 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int	main(int argc, char **argv)
{
	argv[0] = NULL;
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return (1);
	}

	if (s1.empty())
	{
		std::cerr << "Error: The string to be replaced cannot be empty." << std::endl;
		return (1);
	}

	if (s2.empty())
	{
		std::cerr << "Error: The string to be replaced cannot be empty." << std::endl;
		return (1);
	}

	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	std::string content = buffer.str();
	inputFile.close();

	std::size_t pos = content.find(s1);
	while (pos != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos = content.find(s1, pos + s2.length());
	}

	std::ofstream outputFile((filename + ".replace").c_str());
	outputFile << content;
	outputFile.close();

	return (0);
}