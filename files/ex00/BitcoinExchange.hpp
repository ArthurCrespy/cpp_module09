/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:26:38 by acrespy           #+#    #+#             */
/*   Updated: 2024/04/04 17:26:44 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <iostream>
# include <sstream>
# include <fstream>
# include <regex>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;

	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void addCurrency(std::string const &date, double value);
		void displayCurrency(std::string const &date, double value);
};

void readFile(std::ifstream &file, std::string key, BitcoinExchange &exchange, void (BitcoinExchange::*f)(std::string const &, double));

#endif
