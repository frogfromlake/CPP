/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:29 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___IMATERIASOURCE_HPP___)
#define ___IMATERIASOURCE_HPP___

#include "AMateria.hpp"

#include <string>

class IMateriaSource
{
	private:
		/* Private Attributes */
	protected:
		/* Protected Attributes */

	public:
		/* Constructors */
		
		/* Destructors */
		virtual ~IMateriaSource() {}
		
		/* Overloaded Operators */

		/* Public Methods */
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
		/* Getter */
		
		/* Setter */
};

#endif // ___IMATERIASOURCE_HPP___