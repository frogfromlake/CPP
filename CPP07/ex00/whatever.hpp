/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/24 12:23:52 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___WHATEVER_HPP___)
#define ___WHATEVER_HPP___

template<typename T>
void swap(T &arg1, T &arg2)
{
	T tmp;

	tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template<typename T>
const T &min(T &arg1, T &arg2)
{
	return arg1 < arg2 ? arg1 : arg2;
}

template<typename T>
const T &max(T &arg1, T &arg2)
{
	return arg1 > arg2 ? arg1 : arg2;
}

#endif // ___WHATEVER_HPP___