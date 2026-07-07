/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:52:39 by rjaada            #+#    #+#             */
/*   Updated: 2026/07/07 03:29:03 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : _db(other._db)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
	{
		this->_db = other._db;
	}
	return (*this);
}

void BitcoinExchange::readfile()
{
	size_t	location;
	float	price;

	std::ifstream fileCsv("data.csv");
	if (!fileCsv.is_open())
	{
		std::cerr << "Error: could not open database." << std::endl;
		return ;
	}
	std::string line;
	// Skip the first line (header: date,exchange_rate)
	std::getline(fileCsv, line);
	// Loop the whole file
	while (std::getline(fileCsv, line))
	{
		location = line.find(',');
		if (location != std::string::npos)
		{
			std::string date = line.substr(0, location);
			price = std::atof(line.substr(location + 1).c_str());
			_db[date] = price; // Store it in the map!
		}
	}
}

bool BitcoinExchange::isValidDate(std::string const &date)
{
	int	year;
	int	month;
	int	day;

	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	return (true);
}

void BitcoinExchange::processInput(std::string const &filename)
{
	size_t	location;
	size_t	first;
	size_t	last;
	float	value;
	float	exchangeRate;
	float	result;

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		location = line.find('|');
		if (location == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = line.substr(0, location);
		std::string valueStr = line.substr(location + 1);
		first = date.find_first_not_of(" \t");
		last = date.find_last_not_of(" \t");
		if (first != std::string::npos && last != std::string::npos)
		{
			date = date.substr(first, (last - first + 1));
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		value = std::atof(valueStr.c_str());

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		std::map<std::string, float>::iterator it = _db.lower_bound(date);
		if (it == _db.begin() && it->first != date)
		{
			std::cerr << "Error: date is before Bitcoin database begins." << std::endl;
			continue ;
		}
		if (it == _db.end() || it->first != date)
		{
			--it;
		}

		exchangeRate = it->second;
		result = value * exchangeRate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange()
{
}