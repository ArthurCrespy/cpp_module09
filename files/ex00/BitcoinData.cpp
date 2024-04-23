/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinData.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:58:06 by acrespy           #+#    #+#             */
/*   Updated: 2024/04/09 17:58:08 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidDate(const std::string &date)
{
	std::tm tm = {};
	char *end = strptime(date.c_str(), "%Y-%m-%d", &tm);

	if (end != &date[date.size()])
		return (std::cerr << "Error: Invalid date format: " << date << std::endl, false);
	if (tm.tm_year < 0 || tm.tm_year > 200)
		return (std::cerr << "Error: Invalid year: " << date << std::endl, false);
	if(tm.tm_mon == 1 && (tm.tm_mday == 30 || tm.tm_mday == 31))
		return (std::cerr << "Error: Invalid day: " << date << std::endl, false);
	if (tm.tm_mon == 1 && tm.tm_mday == 29)
	{
		if (((tm.tm_year + 1900) % 4 == 0 && (tm.tm_year + 1900) % 100 != 0) || (tm.tm_year + 1900) % 400 == 0)
			return (true);
		return (std::cerr << "Error: Invalid day: " << date << std::endl, false);
	}
	if ((tm.tm_mon == 3 || tm.tm_mon == 5 || tm.tm_mon == 8 || tm.tm_mon == 10) && tm.tm_mday > 30)
		return (std::cerr << "Error: Invalid day: " << date << std::endl, false);
	return (true);
}

bool isPositiveValue(const std::string &value)
{
	long double				val;
	std::istringstream	ss(value);

	ss >> val;
	if (ss.fail())
		return (std::cerr << "Error: Invalid value format: " << static_cast<int>(val) << std::endl, false);
	if (val < -1000)
		return (std::cerr << "Error: Invalid value (too low): not shown (may have overflow)" << std::endl, false);
	if (val < 0)
		return (std::cerr << "Error: Invalid value (negative): " << static_cast<int>(val) << std::endl, false);
	return (true);
}

bool isInRangeValue(const std::string &value)
{
	long double				val;
	std::istringstream	ss(value);

	ss >> val;
	if (ss.fail())
		return (std::cerr << "Error: Invalid value format: " << static_cast<int>(val) << std::endl, false);
	if (val > 1000)
		return (std::cerr << "Error: Invalid value (too high): not shown - may have overflow" << std::endl, false);
	return (true);
}

void readFile(std::ifstream &file, std::string key, BitcoinExchange &exchange, void (BitcoinExchange::*f)(std::string const &, double))
{
	std::string	line;
	while (std::getline(file, line))
	{
		double		value;
		std::string	date;
		std::string	separator;
	
		if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos || line[0] == '#'
		|| strcmp(line.c_str(), "date | value") == 0 || strcmp(line.c_str(), "date,exchange_rate") == 0)
			continue ;
		size_t pos = line.find(',');
		if (pos != std::string::npos)
			line.replace(pos, 1, " , ");
	
		std::istringstream	iss(line);
		if (!(iss >> date >> separator >> value))
		{
			std::cerr << "Error: Invalid line format: " << line << std::endl;
			continue ;
		}
		if (separator != key)
		{
			std::cerr << "Error: Invalid separator: " << separator << std::endl;
			continue ;
		}
		if (!isValidDate(date))
			continue ;
		std::ostringstream	strs;
		strs << value;
		std::string str_value = strs.str();
		if (key == "|" && (!isPositiveValue(str_value) || !isInRangeValue(str_value)))
				continue ;
		(exchange.*f)(date, value);
	}
}
