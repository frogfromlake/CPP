/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/24 12:48:06 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___ITER_HPP___)
#define ___ITER_HPP___

#include <iostream>
#include <string>

template<typename T>
void iter(T *arr, size_t length, void (*f)(const T &element))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

template<typename T>
void printElement(const T &element)
{
	std::cout << element << std::endl;
}

#endif // ___ITER_HPP___