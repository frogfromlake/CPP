/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/26 15:18:58 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___EASYFIND_HPP___)
#define ___EASYFIND_HPP___

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

struct ParamNotFoundInCont : public std::exception
{
	const char *what() const throw()
	{
		return "Parameter not found in Container";
	}
};

template<typename DataType>
DataType easyfind(std::vector<DataType>& cont, int toFind)
{
	typename std::vector<DataType>::iterator it = std::find(cont.begin(), cont.end(), toFind);
	if (it == cont.end())
		throw ParamNotFoundInCont();
	return *it;
}

#endif // ___EASYFIND_HPP___