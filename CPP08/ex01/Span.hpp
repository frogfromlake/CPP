/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/26 10:23:39 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___SPAN_HPP___)
#define ___SPAN_HPP___

#include <string>
#include <vector>
#include <iostream>

class Span
{
	private:
		/* private Members */
		unsigned int _maxElements;
		std::vector<int> _integers;

	public:
		/* Constructors */
		Span();
		Span(const Span &copy);
		Span(unsigned int maxElements);
		/* Destructors */
		~Span();

		/* Overloaded Operators */
		Span &operator=(const Span &op);

		/* Public Methods */
		void addNumber(int number);
		void iterAddNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void clear();

		/* Getter */
		unsigned int getSize() const;
		int getElement(unsigned int index) const;

		/* Setter */

		/* Exceptions */
		struct IndexOutOfBounds : public std::exception
		{
			const char *what() const throw()
			{
				return "[IndexOutOfBounds]\n>> Index is out of bounds for Vector '_integers':"
					   " Size defined by '_maxElements'";
			}
		};

		struct OverflowException : public std::exception
		{
			const char *what() const throw()
			{
				return "[OverflowException]\n>> Too many Elements in Vector '_integers':"
					   " Size defined by '_maxElements'";
			}
		};

		struct InvalidOperationException : public std::exception
		{
			const char *what() const throw()
			{
				return "[InvalidOperationException]\n>> Too few Elements in Vector '_integers':"
					   " Span calculation not possible.";
			}
		};
};

std::ostream& operator<<(std::ostream&, const Span&);

#endif // ___SPAN_HPP___