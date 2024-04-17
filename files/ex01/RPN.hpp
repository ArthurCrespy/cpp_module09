/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:21:27 by acrespy           #+#    #+#             */
/*   Updated: 2024/04/10 12:23:22 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <algorithm>
# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<size_t> _stack;

	public:
		RPN(void);
		RPN(RPN const &src);
		~RPN(void);

		RPN &operator=(RPN const &rhs);

		int exec(std::string const &str);
		int calculate(std::string const &str);
};

#endif
