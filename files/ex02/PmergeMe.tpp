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

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

template <typename T>
void mergeInsertSort(T &container)
{
    typename T::iterator it1, it2;
    for (it1 = std::next(container.begin()); it1 != container.end(); ++it1)
	{
        int temp = *it1;
        it2 = it1;
        while (it2 != container.begin() && *(std::prev(it2)) > temp)
		{
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}

template <typename T>
void display(const T &container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

#endif
