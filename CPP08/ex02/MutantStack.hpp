/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/26 13:56:34 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___MUTANTSTACK_HPP___)
#define ___MUTANTSTACK_HPP___

#include <stack>

template <typename DataType>
class MutantStack : public std::stack<DataType>
{
	public:
		/* Constructors */

		MutantStack() : std::stack<DataType>(){};
		MutantStack(const MutantStack &copy) : std::stack<DataType>(copy){};
		MutantStack(const std::stack<DataType> &copy) : std::stack<DataType>(copy){};

		/* Destructors */

		virtual ~MutantStack(){};

		/* Overloaded Operators */

		MutantStack &operator=(const MutantStack &op)
		{
			if (this == &op)
				return *this;

			this->c = op.c;
			return *this;
		}

		/* Iterators */

		typedef typename std::stack<DataType>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		typedef typename std::stack<DataType>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }

		typedef typename std::stack<DataType>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		typedef typename std::stack<DataType>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif // ___CLASS_HPP___