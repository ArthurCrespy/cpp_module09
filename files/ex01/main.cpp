/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:27:29 by acrespy           #+#    #+#             */
/*   Updated: 2024/04/09 17:58:54 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void test(RPN &rpn)
{
	std::cout << "------ Tests ------" << std::endl;

	std::cout << "input: 3 4 +" << std::endl << "expected result: 7" << std::endl << "     rpn result: ";
	rpn.exec("3 4 +");
	std::cout << std::endl << "input: 8 5 -" << std::endl << "expected result: 3" << std::endl << "     rpn result: ";
	rpn.exec("8 5 -");
	std::cout << std::endl << "input: 2 6 *" << std::endl << "expected result: 12" << std::endl << "     rpn result: ";
	rpn.exec("2 6 *");
	std::cout << std::endl << "input: 9 3 /" << std::endl << "expected result: 3" << std::endl << "     rpn result: ";
	rpn.exec("9 3 /");
	std::cout << std::endl << "input: 6 3 2 + -" << std::endl << "expected result: 1" << std::endl << "     rpn result: ";
	rpn.exec("6 3 2 + -");
	std::cout << std::endl << "input: 5 1 2 + 4 * + 3 -" << std::endl << "expected result: 14" << std::endl << "     rpn result: ";
	rpn.exec("5 1 2 + 4 * + 3 -");

	std::cout << std::endl << "input: 5 6 $" << std::endl << "expected result: Error: invalid character" << std::endl << "     rpn result: ";
	rpn.exec("5 6 $");
	std::cout << std::endl << "input: 5 +" << std::endl << "expected result: Error: not enough operands" << std::endl << "     rpn result: ";
	rpn.exec("5 +");
	std::cout << std::endl << "input: 5 6 7 +" << std::endl << "expected result: Error: too many operands" << std::endl << "     rpn result: ";
	rpn.exec("5 6 7 +");
	std::cout << std::endl << "input: 8 0 /" << std::endl << "expected result: Error: division by zero" << std::endl << "     rpn result: ";
	rpn.exec("8 0 /");
	std::cout << std::endl << "input: 2 0 / 3 +" << std::endl << "expected result: Error: division by zero" << std::endl << "     rpn result: ";
	rpn.exec("2 0 / 3 +");
}

int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
		return (std::cout << "Usage: ./rpn \"[expression]\"" << std::endl, 1);
	if (std::string(argv[1]) == "test")
		test(rpn);
	else
		rpn.exec(argv[1]);

	return (0);
}
