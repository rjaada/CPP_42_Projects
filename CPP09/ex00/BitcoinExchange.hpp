/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:41:23 by rjaada            #+#    #+#             */
/*   Updated: 2026/07/07 03:09:42 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <map>
# include <sstream>
# include <iomanip>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange& operator=(BitcoinExchange const &other);
		~BitcoinExchange();
		
		void readfile();
		void processInput(std::string const &filename);

		bool isValidDate(std::string const &date);
};


#endif