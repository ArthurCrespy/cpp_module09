/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:14 by acrespy           #+#    #+#             */
/*   Updated: 2024/04/17 14:28:04 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
	{
		_vector = rhs._vector;
		_deque = rhs._deque;
	}
    return (*this);
}

int PmergeMe::parse(int argc, char **argv)
{
    if (argc <= 1)
		return (std::cerr << "Error: No sequence provided as argument." << std::endl, 1);
	for (int i = 1; i < argc; ++i)
	{
		int num = std::stoi(argv[i]);
		if (num < 0)
			return(std::cerr << "Error: Negative integer found in the sequence." << std::endl, 1);
		_vector.push_back(num);
		_deque.push_back(num);
	}
	std::cout << "Initial sequence: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	return (0);
}

int PmergeMe::merge(int argc, char **argv)
{
	if (parse(argc, argv))
		return (1);

    std::chrono::high_resolution_clock::time_point startVector = std::chrono::high_resolution_clock::now();
    mergeInsertSort(_vector);
    std::chrono::high_resolution_clock::time_point endVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedTimeVector = endVector - startVector;

    std::chrono::high_resolution_clock::time_point startDeque = std::chrono::high_resolution_clock::now();
    mergeInsertSort(_deque);
    std::chrono::high_resolution_clock::time_point endDeque = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedTimeDeque = endDeque - startDeque;

	std::cout << "Sorted  sequence: ";
	display(_vector);
	std::cout << std::endl;

	std::cout << "std::vector<int> sort time for " << argc - 1 << " elements: " << elapsedTimeVector.count() << "ms" << std::endl;
	std::cout << "std::deque<int>  sort time for " << argc - 1 << " elements: " << elapsedTimeDeque.count() << "ms" << std::endl;


	return (0);
}

