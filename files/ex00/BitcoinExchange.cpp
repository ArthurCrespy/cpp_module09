/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:26:38 by acrespy           #+#    #+#             */
/*   Updated: 2024/04/04 17:27:19 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
		_data = rhs._data;
	return (*this);
}

void BitcoinExchange::addCurrency(std::string const &date, double value)
{
	_data.insert(std::make_pair(date, value));
}

void BitcoinExchange::displayCurrency(std::string const &date, double value)
{
	map_it it = _data.find(date);

	if (it != _data.end())
		std::cout << date << " => " << value << " = " << it->second * value << std::endl;
	else
	{
		map_it lower = _data.lower_bound(date);
		map_it upper = _data.upper_bound(date);

		if (lower == _data.begin())
			std::cout << date << " => " << value << " = " << lower->second * value << std::endl;
		else if (upper == _data.end())
		{
			map_it prev_lower = lower;
			--prev_lower;
			std::cout << date << " => " << value << " = " << prev_lower->second * value << std::endl;
		}
		else
			displayCurrencyInRange(date, value, lower, upper);
	}
}

void BitcoinExchange::displayCurrencyInRange(std::string const &date, double value, map_it lower, map_it upper)
{
	std::istringstream iss_lower(lower->first);
	std::istringstream iss_upper(upper->first);
	double lower_date;
	double upper_date;
	iss_lower >> lower_date;
	iss_upper >> upper_date;
	std::istringstream iss_date(date);
	double date_value;
	iss_date >> date_value;

	double lowerDiff = date_value - lower_date;
	double upperDiff = upper_date - date_value;
	if (lowerDiff < upperDiff)
	{
		map_it prev_lower = lower;
		--prev_lower;
		std::cout << date << " => " << value << " = " << prev_lower->second * value << std::endl;
	}
	else if (lowerDiff > upperDiff)
		std::cout << date << " => " << value << " = " << upper->second * value << std::endl;
	else
		std::cout << date << " => " << value << " = " << lower->second * value << std::endl;
}
