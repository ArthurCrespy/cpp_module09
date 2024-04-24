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
void fordJohnsonSort(std::vector<T> &container)
{
    if (container.size() <= 1)
        return ;

    typename std::vector<T>::iterator middle = container.begin() + container.size() / 2;
    std::vector<T> left(container.begin(), middle);
    std::vector<T> right(middle, container.end());

    for (size_t i = 1; i < left.size(); ++i)
	{
        T key = left[i];
        int j = i - 1;
        while (j >= 0 && left[j] > key)
		{
            left[j + 1] = left[j];
            --j;
        }
        left[j + 1] = key;
    }

    if (right.size() > 1)
	{
        typename std::vector<T>::iterator middle = right.begin() + right.size() / 2;
        std::vector<T> right_left(right.begin(), middle);
        std::vector<T> right_right(middle, right.end());

        fordJohnsonSort(right_left);
        fordJohnsonSort(right_right);

        std::merge(right_left.begin(), right_left.end(), right_right.begin(), right_right.end(), right.begin());
    }
    std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
}

template <typename T>
void fordJohnsonSort(std::deque<T> &container)
{
    if (container.size() <= 1)
        return ;

    typename std::deque<T>::iterator middle = container.begin() + container.size() / 2;
    std::deque<T> left(container.begin(), middle);
    std::deque<T> right(middle, container.end());

    for (size_t i = 1; i < left.size(); ++i)
	{
        T key = left[i];
        int j = i - 1;
        while (j >= 0 && left[j] > key)
		{
            left[j + 1] = left[j];
            --j;
        }
        left[j + 1] = key;
    }

    if (right.size() > 1)
	{
        typename std::deque<T>::iterator middle = right.begin() + right.size() / 2;
        std::deque<T> right_left(right.begin(), middle);
        std::deque<T> right_right(middle, right.end());

        fordJohnsonSort(right_left);
        fordJohnsonSort(right_right);

        std::merge(right_left.begin(), right_left.end(), right_right.begin(), right_right.end(), right.begin());
    }
    std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
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
