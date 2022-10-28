/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:53:38 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:29 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___AMATERIA_HPP___)
#define ___AMATERIA_HPP___

#include <string>

class ICharacter;

class AMateria
{
	protected:
		/* Protected Attributes */
		std::string _type;
	public:
		/* Constructors */
		AMateria();
		AMateria(const AMateria &copy);
		AMateria(std::string const & type);
		/* Deconstructors */
		virtual ~AMateria() = 0;

		/* Overloaded Operators */
		AMateria &operator=(const AMateria &op);

		/* Public Methods */
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		/* Getter */
		std::string const & getType() const; //Returns the materia type

};

#endif // ___AMATERIA_HPP___