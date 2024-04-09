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
    std::map<std::string, double>::iterator it = _data.find(date);

    if (it != _data.end())
        std::cout << date << " => " << value << " = " << it->second * value << std::endl;
    else
    {
        std::map<std::string, double>::iterator lower = _data.lower_bound(date);
        std::map<std::string, double>::iterator upper = _data.upper_bound(date);

        if (lower == _data.begin())
            std::cout << date << " => " << value << " = " << lower->second * value << std::endl;
        else if (upper == _data.end())
            std::cout << date << " => " << value << " = " << std::prev(lower)->second * value << std::endl;
        else
        {
            double lowerDiff = std::stod(date) - std::stod(std::prev(lower)->first);
            double upperDiff = std::stod(upper->first) - std::stod(date);
            if (lowerDiff < upperDiff)
                std::cout << date << " => " << value << " = " << std::prev(lower)->second * value << std::endl;
            else if (lowerDiff > upperDiff)
                std::cout << date << " => " << value << " = " << upper->second * value << std::endl;
            else
                std::cout << date << " => " << value << " = " << lower->second * value << std::endl;
        }
    }
}
