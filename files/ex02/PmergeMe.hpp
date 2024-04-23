/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:14 by acrespy           #+#    #+#             */
/*   Updated: 2024/04/17 14:27:19 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <deque>
# include <ctime>


class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const &rhs);

		int parse(int argc, char **argv);
		int merge(int argc, char **argv);
};

#endif
