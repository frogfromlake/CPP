/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:09 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___MATERIASOURCE_HPP___)
#define ___MATERIASOURCE_HPP___

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#include <string>

class MateriaSource : public IMateriaSource
{
	private:
		/* Private Attributes */
		static const unsigned int _invSlots = 4;
		AMateria *_inventory[_invSlots];
	public:
		/* Constructors */
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		
		/* Destructors */
		~MateriaSource();

		/* Overloaded Operators */
		MateriaSource &operator=(const MateriaSource &op);

		/* Public Methods */
		virtual void learnMateria(AMateria *m);
		virtual AMateria* createMateria(std::string const & type);

		/* Getter */
		
		/* Setter */
};

#endif // ___MATERIASOURCE_HPP___