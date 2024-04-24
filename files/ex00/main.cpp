/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:27:29 by acrespy           #+#    #+#             */
/*   Updated: 2024/04/04 17:27:32 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange	exchange;

	if (argc != 2)
		return (std::cerr << "Usage: ./bitcoin [filename]" << std::endl, 1);

	std::ifstream	input(argv[1]);
	if (!input.is_open() || !input.good() || input.bad())
		return (std::cerr << "Error: could not open input file" << std::endl, 1);

	std::ifstream 	db("data.csv");
	if (!db.is_open() || !db.good() || db.bad())
		return (input.close(), std::cerr << "Error: could not open database file" << std::endl, 1);

	readFile(db, ",", exchange, &BitcoinExchange::addCurrency);
	readFile(input, "|", exchange, &BitcoinExchange::displayCurrency);

	input.close();
	db.close();
	return (0);
}
