/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:21:27 by acrespy           #+#    #+#             */
/*   Updated: 2024/04/10 12:23:28 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		_stack = rhs._stack;
	return (*this);
}

int RPN::exec(std::string const &str)
{
	calculate(str);
	while (!_stack.empty())
		_stack.pop();
	return (0);
}

int RPN::calculate(std::string const &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
			continue ;
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && !isdigit(str[i]))
			return (std::cout << "Error: invalid character" << std::endl, 1);
		if (isdigit(str[i]))
			_stack.push(str[i] - '0');
		else
		{
			if (_stack.size() < 2)
				return (std::cout << "Error: not enough operands" << std::endl, 1);
			size_t b = _stack.top();
			_stack.pop();
			size_t a = _stack.top();
			_stack.pop();
			if (str[i] == '+')
				_stack.push(a + b);
			else if (str[i] == '-')
				_stack.push(a - b);
			else if (str[i] == '*')
				_stack.push(a * b);
			else if (str[i] == '/')
			{
				if (b == 0)
					return (std::cout << "Error: division by zero" << std::endl, 1);
				_stack.push(a / b);
			}
			else
				return (std::cout << "Error: invalid operator" << std::endl, 1);
		}
	}
	if (_stack.size() != 1)
		return (std::cout << "Error: too many operands" << std::endl, 1);
	std::cout << _stack.top() << std::endl;
	return (0);
}
