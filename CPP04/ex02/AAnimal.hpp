/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:40:13 by nelix             #+#    #+#             */
/*   Updated: 2022/08/20 12:36:05 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___AANIMAL_HPP___)
#define ___AANIMAL_HPP___

#include <string>

class AAnimal
{
	protected:
		/* Protected Attributes */
		std::string _type;
	public:
		/* Constructors */

		/* Deconstructorss */
		virtual ~AAnimal() = 0;

		/* Overloaded Operators */

		/* Public Methods */
		virtual void makeSound() const = 0;

		/* Getter */
		virtual std::string getType() const = 0;
};

#endif // ___AANIMAL_HPP___